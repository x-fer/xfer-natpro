#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int niz[1001];
int bio[1001];

int main( void ) {
  scanf( "%d", &n );
  for( int i = 1; i <= n; ++i )
    scanf( "%d", &niz[i] );

  int C = 0;
  for( int i = 1; i <= n; ++i ) {
    if( !bio[i] ) ++C;
    for( int j = i; !bio[j]; j = niz[j] )
      bio[j] = 1;
  }
  printf( "%d\n", n - C );

  return 0;
}

