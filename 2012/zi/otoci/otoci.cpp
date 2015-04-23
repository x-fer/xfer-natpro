#include <cstdio>

const int MAXN = 510;

int n, m;
char mapa[MAXN][MAXN];

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, 1, 0, -1 }; 

int dfs( int x, int y ) {
  if( x < 0 || x >= n ) return 0;
  if( y < 0 || y >= m ) return 0;
  if( mapa[x][y] == '0' ) return 0;

  mapa[x][y] = '0';
  
  int ret = 1;
  for( int i = 0; i < 4; ++i ) 
    ret += dfs( x + dx[i], y + dy[i] );

  return ret;
}

int main() {
  scanf( "%d%d", &n, &m );
  for( int i = 0; i < n; ++i )
    scanf( "%s", mapa[i] );

  int sol = 0;

  for( int i = 0; i < n; ++i ) 
    for( int j = 0; j < m; ++j ) 
      if( mapa[i][j] == '1' ) {
        int area = dfs( i, j );
        sol += area / 5 + 1 - (area % 5 == 0);
      }

  printf( "%d\n", sol );

  return 0;
}
