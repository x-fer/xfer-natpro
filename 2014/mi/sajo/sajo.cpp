#include <algorithm>
#include <cassert>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN = 1010;

struct Bag {
  int v, s;
} bags[MAXN];

bool dp[MAXN][MAXN];
int n, v;

bool can(int S) {
  memset(dp, 0, sizeof(dp));
  dp[0][0] = true;
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j <= v; ++j) {
      dp[i][j] = dp[i-1][j];
      if (bags[i].s <= S && j >= bags[i].v)
        dp[i][j] |= dp[i-1][j - bags[i].v];
    }
  return dp[n][v];
}

int main(void) {
  scanf("%d %d", &n, &v);
  for (int i = 1; i <= n; ++i)
    scanf("%d %d", &bags[i].v, &bags[i].s);
  
  int lo = 0, hi = MAXN;
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (can(mid)) hi = mid; else
      lo = mid+1;
  }
  
  assert(can(lo));
  printf("%d\n", lo);
  return 0;
}
