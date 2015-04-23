/*Zavrsni ispit NATPRO 2011/2012
	Zadatak Uspon, Dino Santl

Ideja je da zadatak rijesimo dinamickim programiranjem.

Promatramo zgradu kao matricu dimenzije S x V, na pocetku sva su polja u matrici 
0, jer ni na jedan nacin nije moguce doci u to nijedno polje.
U matricu na mijesto [S/2, 0] zapisemo 1, jer se u to polje moze doci 
na 1 nacin.
Krenemo sa dinamikom na drugom katu, i popunjavamo drugi redak matrice prema 
izrazu Matrica[x, y] = Matrica[x, y-1] + Matrica[x-1, y-1] + Matrica[x+1, y+1],
pritom moramo paziti da ne izadnjemo izvan matrice. 

Ako je x, y koordinata prozora na koji nesmijemo, ne racunamo izraz nego ostavljamo 0, jer 
na to polje (prozor) se moze na 0 nacina.

Vremenska slozenost za rijesenje za prvo rijesenje je O( S*V*K ), prolazimo kroz 
cijelu matricu i za svako polje provjeravamo da li je dopusteno, tj. da 
nije.

Ako spremamo zabranjena polja u set parova 
(struktura koja u logaritamskom vremenu kaze da li ima ili nema element), 
onda mozemo u log K saznati da li je
neko polje zabranjeno ili ne, pa vremenska slozenost postaje O(S*V*log(K)).

Ako spremamo zabranjena polja u hash, tada u O(1) mozemo saznati da li je polje 
zabranjeno pa slozenost postaje O(S*V).

Ako koristimo cijelu matricu prostorna slozenost je O(V*S) ali to je nepotrebno,
zato jer uvijek koristimo trenutni redak i onaj ispod pa je prostorna slozenost
O(S), jer koristimo dva niza, svaki dimenzije sirine zgrade.

*/

#include<cstdio>
#include<cstring>
#include<set>
#include<vector>

using namespace std;

#define MAXI 2005
#define nflag (1-flag) //nflag je uvijek obrnuto od flag (binarni sustav)
#define MOD 100007

int main(void)
{
	
	int S, V, K, X, Y;
	int M[ 2 ][ MAXI ] = { 0 }; //postavimo sve na 0
	vector<pair<int, int> > N; //nedopustene koordinate
	int flag; //varijablu koristimo za oznaku u M, da li je gornji red trenutni 
	int sol; //rjesenje
	
	
	scanf("%d %d", &V, &S);
	scanf("%d", &K);
	
	for (int i = 0 ; i < K ; ++i)
	{
		scanf("%d %d", &X, &Y);
		N.push_back( make_pair(X, Y) );
	}
	
	M[0][ S / 2 ] = 1; //inicjaliziramo pocetnu poziciju studenta
	
	for (int y = 1 ; y < V ; ++y )
	{
		flag = y % 2;
		bool p = false;
		for (int x = 0; x < S ; ++x )
		{
		
			M[ flag ][ x ] = 0; //brisanje stare vrijednosti
			
			for (int j = 0 ; j < (int)N.size() ; ++j)
				if ( N[j] == make_pair(x, y) ) {p=true;break;} 
			
			if ( p ) continue; //ako je prozor zabranjen preskoci ga
			
			//Provjera da li smo na zgradi i odmah racunaj
		
			if ( x != 0 ) M[ flag ][ x ] = ( M[ flag ][ x ] % MOD + M[ nflag ][ x - 1] % MOD ) % MOD; 
			if ( x != S-1 ) M[ flag ][ x ] = ( M[ flag ][ x ] % MOD + M[ nflag ][ x + 1] % MOD ) % MOD;
			M[ flag ][ x ] = ( M[ flag ][ x ] % MOD + M[ nflag ][ x ] % MOD ) % MOD;			
		}			
	} 
	
	sol = 0;
	flag = 1 - V % 2;
	for (int x = 0 ; x < S ; ++x)
	{
		sol = ( sol % MOD + M[flag][x] % MOD ) % MOD;
	}
	
	printf("%d\n", sol);
	
	return 0;
}
