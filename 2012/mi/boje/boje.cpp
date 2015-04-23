#include <algorithm>
#include <functional>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using namespace std; 

const int MAXN = 10000;
const int inf = 2147483647; 

char str[MAXN];
int dp[MAXN][3];
int n, a[MAXN][3];

int rec( int pos, int last ) {
  if ( pos >= n ) return 0;

  int &ref = dp[pos][last];
  if( ref != -1 ) return ref;
  ref = inf;

  for( int i = 0; i < 3; ++i ) {
    if ( last == i ) continue;

    if( str[pos] != 'A'+i ) 
      ref = min( ref, a[pos][i] + rec(pos+1,i) );
    else 
      ref = min( ref, rec(pos+1, i) );
  }

  return ref;
}

int main() {
  scanf( "%s", str );
  n = strlen( str );
  for( int i = 0; i < n; ++i ) 
    for( int j = 0; j < 3; ++j ) 
      scanf( "%d", &a[i][j] ); 

  memset( dp, -1, sizeof dp );

  int sol = inf;
  for( int i = 0; i < 3; ++i ) 
    sol = min( sol, rec( 0, i ) );

  printf( "%d\n", sol );

  return 0;
}

