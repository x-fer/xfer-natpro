
/*
  DMIH 2006 - Drugi dan natjecanja
  Srednjoskolska skupina - II. podskupina
  Zadatak KAOS

  Neka je niz X sortirani niz rijeci, a niz Y sortirani niz obrnutih rijeci.

  Dodijelimo svakoj rijeci dva broja x i y koji oznacavaju njenu poziciju unutar
  nizova X i Y.

  Tada mozemo reci da se rijeci A i B ne podnose ako je x(A) < x(B) i y(B) < y(A).

  Obradjujemo rijeci redom po y i ubacujemo jednu po jednu u odgovarajucu
  strukturu. Za svaku rijec racunamo s koliko rijeci koje smo dosad obradili se
  ona ne podnosi. Kako trenutna rijec ima najveci y dosad, to trebamo pronaci
  one rijeci koje imaju manji x.

  Struktura u koju cemo ubacivati rijeci mora dakle podrzavati slijedece
  operacije:

  1) Ubacivanje cijelog broja x
  2) Odgovor na pitanje koliko ima brojeva manjih od x unutar strukture

  Postoji vise struktura koje podrzavaju ove operacije efikasno, a mi cemo
  koristiti tzv. segmentirano polje poznatije kao logaritamska struktura.

  Ako je T(x) neki niz cijelih brojeva, tada segmentirano polje S(x) na svakom
  polju pamti sumu niza T u intervalu <x-lobit(x), x]. Gdje je lobit(x) najveca
  potencija broja 2 s kojom je broj x djeljiv.

  Na taj nacin mozemo ubaciti broj i odgovoriti na pitanje u O(log N), Pa je
  ukupna vremenska slozenost algoritma O(N * log N).

  Detalje o samoj strukturi mozete naci u kodu.
*/

#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

#define MAX 100000

struct log_str {
   int a[MAX+1];
   inline int lobit( int x ) { return x&-x; }

   int pitaj( int x ) {
      int ret = 0;
      for( ; x > 0; x -= lobit( x ) )
         ret += a[x];
      return ret;
   }
   void ubaci( int x ) {
      for( ; x <= MAX; x += lobit( x ) )
         ++a[x];
   }
};
log_str loga;

struct rijec {
   string s1, s2;
   int x, y;
};

bool cmp1( const rijec &A, const rijec &B ) { return A.s1 < B.s1; }
bool cmp2( const rijec &A, const rijec &B ) { return A.s2 < B.s2; }

char buff[1024];
int main( void ) {
   int n;
   scanf( "%d", &n );

   vector<rijec> dict;
   for( int i = 0; i < n; ++i ) {
      scanf( "%s", buff );
      rijec A;
      A.s1 = buff;
      A.s2 = buff;
      reverse( A.s2.begin(), A.s2.end() );
      dict.push_back( A );
   }

   sort( dict.begin(), dict.end(), cmp1 );
   for( int i = 0; i < n; ++i ) dict[i].x = n-i;

   sort( dict.begin(), dict.end(), cmp2 );
   for( int i = 0; i < n; ++i ) dict[i].y = n-i;

   long long ret = 0;
   for( int i = 0; i < n; ++i ) {
      ret += loga.pitaj( dict[i].x );
      loga.ubaci( dict[i].x );
   }
   printf( "%lld\n", ret );

   return 0;
}
