#include <cstdio>
#include <ctime>
#include <algorithm>

using namespace std;

int n, m;
int a[1000];
int g[1000];

int main( void ) {
  srand( time(0) );
  scanf( "%d %d", &n, &m );
  printf( "%d\n", n );
  for( int i = 0; i < n; ++i ) a[i] = i+1;

  for( int i = 0; i < m; ++i )
    g[i] = rand()%n;
  sort( g, g+m );
  g[m] = n;

  for( int i = 0; i < m; ++i )
    random_shuffle( a+g[i], a+g[i+1] );

  for( int i = 0; i < n; ++i )
    printf( "%d%c", a[i], i+1 < n ? ' ' : '\n' );

  return 0;
}

