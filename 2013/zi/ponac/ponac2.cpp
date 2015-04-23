#include <cstdio>
#include <cstring>

typedef long long llint;

const int mod = 1e6 + 7;
const int maxn = 8;
const int maxdp_k = 500;

const int dx[8] = {-2,-1,1,2,2,1,-1,-2};
const int dy[8] = {1,2,2,1,-1,-2,-2,-1};

int dp[maxn][maxn][maxdp_k];
int N;

int solve(int i, int j, int k) {
  if (i < 0 || j < 0 || i >= N || j >= N) return 0;
  if (!k) return !i && !j;

  if (k < maxdp_k) {
    int &ret = dp[i][j][k];
    if (ret != -1) return ret;

    ret = 0;
    for (int sm = 0; sm < 8; ++sm)
      ret = ((llint) ret + solve(i - dx[sm], j - dy[sm], k - 1)) % mod;
    return ret;
  } else {
    int ret = 0;
    for (int sm = 0; sm < 8; ++sm)
      ret = ((llint) ret + solve(i - dx[sm], j - dy[sm], k - 1)) % mod;
    return ret;
  }
}

int main() {
  int K;
  scanf("%d%d", &N, &K);
  memset(dp, -1, sizeof dp);
  printf("%d\n", solve(0, 0, K));
  return 0;
}
