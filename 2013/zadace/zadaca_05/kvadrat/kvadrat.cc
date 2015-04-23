#include <cstdio>
using namespace std;
#define MAXVAL 1000000

int k, n;
int faktor[MAXVAL+1];
char zastupljenost[MAXVAL+1];

int main( void ) {
   for( int i = 2; i <= MAXVAL; ++i ) {
      if( faktor[i] ) continue;
      faktor[i] = i;
      for( int j = 2*i; j <= MAXVAL; j += i ) 
         faktor[j] = i;      
   }

   int broj_neparnih = 0;

   scanf( "%d", &k );
   for( int i = 0; i < k; ++i ) {
      scanf("%d", &n);
      while (n > 1) {
          int p = faktor[n];
          broj_neparnih -= (zastupljenost[p] & 1);
          ++zastupljenost[p];
          broj_neparnih += (zastupljenost[p] & 1);
          n /= p;
      }
      if( broj_neparnih == 0 ) printf( "DA\n" );
      else printf( "NE\n" );
   }
   return 0;
}
