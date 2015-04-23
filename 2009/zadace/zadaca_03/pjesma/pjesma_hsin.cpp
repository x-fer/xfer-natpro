
/*
DMIH 2004 - Drugi dan natjecanja
Srednjoskolska skupina - I. podskupina
Zadatak ZIDARSKA
*/

#include <cstdio>
#include <vector>

using namespace std;

vector<int> slusanje, skidanje, cekanje;

int main( void ) {
  int n;
  scanf( "%d", &n );

  slusanje.resize( n );
  skidanje.resize( n );
  cekanje.resize( n+1 );

  for( int i = 0; i < n; ++i )
    scanf( "%d%d", &slusanje[i], &skidanje[i] );

  cekanje[n] = 0;
  for( int i = n-1; i >= 0; --i )
    cekanje[i] = skidanje[i] + max( 0, cekanje[i+1] - slusanje[i] );

  printf( "%d\n", cekanje[0] );

  return 0;
}
