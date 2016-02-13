#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++i)

const int MAXN = 19;

int N, A[MAXN][MAXN];
int dp[1 << MAXN][MAXN];

int solve(int mask, int last, int day) {
  if (day == N) return 0;
  int &ret = dp[mask][last];
  if (ret != -1) return ret;

  ret = 0;
  REP(i, N) {
    if (mask & (1 << i)) continue;
    ret = max(ret, A[last][i] + solve(mask | (1 << i), i, day + 1));
  }

  return ret;
}

int main(void) {
  
  scanf("%d", &N);
  REP(i, N) REP(j, N) scanf("%d", &A[i][j]);
  
  memset(dp, -1, sizeof dp);
  
  int ans = 0;
  REP(i, N) ans = max(ans, A[i][i] + solve(1 << i, i, 1));
  printf("%d\n", ans);

  return 0;
}


