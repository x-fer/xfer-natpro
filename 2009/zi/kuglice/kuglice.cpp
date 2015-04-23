#include <cstdio>
#include <cstring>

#define MAX 101

char grid[MAX][4];

int n, dp[MAX][MAX][MAX];

int best_of_three(int a, int b, int c) {
  int ret = a;
  if( b > ret ) ret = b;
  if( c > ret ) ret = c;
  return ret;
}

int solve(int a, int b, int c) {
  if( a == 0 || b == 0 || c == 0 ) return 0;
  
  int &ret = dp[a][b][c];
  if( ret != -1 ) return ret;

  if( grid[a][0] == grid[b][1] && grid[b][1] == grid[c][2] )
    ret = grid[a][0]-'A'+1 + solve(a-1, b-1, c-1);
  else 
    ret = best_of_three( solve(a-1, b,   c  ),
                         solve(a,   b-1, c  ),
                         solve(a,   b,   c-1) );
  return ret;
}

int main() {
  memset(dp, -1, sizeof(dp));
  
  scanf("%d", &n);
  for( int i = 1; i <= n; ++i ) 
    scanf("%s", grid[i]);

  printf("%d\n", solve(n, n, n));
  
  return 0;
}
