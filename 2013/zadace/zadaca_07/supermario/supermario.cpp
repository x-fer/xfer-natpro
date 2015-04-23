#include <cstdio>

using namespace std;

const int mod = 10007;
const int MAXN = 100005;
const int MAXH = 1000005;

int L[MAXH];
int h[MAXN], dp[MAXN];

void add( int x, int y ) { 
  for( ; x < MAXH; x += x&-x )
    if( (L[x] += y) >= mod ) L[x] -= mod;
}

int sum( int x ) {
  int r = 0;
  for( ; x; x -= x&-x )
    if( (r += L[x]) >= mod ) r -= mod;
  return r;
}

int main( void ) {
  int n;
  scanf( "%d", &n );
  for( int i = 0; i < n; ++i )
    scanf( "%d", h+i );
  
  dp[0] = 1;
  add( h[0], dp[0] );
  for( int i = 1; i < n; ++i ) {
    dp[i] = sum( h[i]-1 );
    add( h[i], dp[i] );
  }

  printf( "%d\n", dp[n-1] );
  return 0;
}
