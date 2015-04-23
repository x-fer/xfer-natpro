/*
Objasnjenje algoritma:
            Problem se rjesava metodom dinamickog programiranja. Ako promotrimo da se igrac nalazi na poziciji i, onda on moze drugog igraca
            poslati na poziciju i - 1, i - a, i - b. Neka dp[i] bude 1 ako igrac na i-toj poziciji ima pobjednicku strategiju, a 0 ako igrac 
            nema pobjednicku strategiju. Tada slijedi ako je igrac na poziciji i, te vec prije izracunati dp[i-1], dp[i-a], dp[i-b] daju 1 
            onda igrac nikako ne moze pobijediti jer protivnickog igraca moze odvesti samo u pobjednicku poziciju. Ukoliko moze odvesti protivnickog
            igraca u barem jednu poziciju koja je gubitnicka, tada igrac koji je na potezu ima pobjednicku strategiju. Iz toga se moze skraceno pisati
            dp[i] = !(dp[i - 1] & dp[i - a] & dp[i - b]). Jos samo treba paziti na granice u slucaju manjih brojeva jer ako je pozicija i manja od broja
            a ili b, onda nije moguce protivnickog igraca poslati u poziciju i - a ili i - b.
*/
#include <cstdio>
#include <cstdlib>

const int maxN = 1000002;
const int maxM = 62;

bool dp[ maxN ];
int game[ maxM ];

inline int max ( int a, int b ) {
       return a > b ? a : b;
       }
       
int main( void ) {
    int a, b, m, upbound = 0;
    
    scanf( "%d%d%d", &m, &a, &b );
    
    for (int i = 0; i < m; ++i) {
        scanf( "%d", &game[i] );
        upbound = max( upbound , game[i] );
        }
        
    dp[0] = 0;
        
    for (int i = 1; i <= upbound; ++i) 
      dp[i] = !(( (i - a >=0) ? dp[ i-a ] : 1) &  ( (i - b >=0) ? dp[ i-b ] : 1) & dp[ i-1 ] );
    
    for (int i = 0; i < m; ++i) 
        if ( dp[ game[i] ] )  printf( "mirko\n" );  
           else  printf( "slavko\n" );  
    
return ( 7-7 );
}
