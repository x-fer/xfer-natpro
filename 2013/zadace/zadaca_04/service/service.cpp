#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXL = 202;
const int MAXN = 1010;
const int INF = 0x3f3f3f3f;

int n, l;
int dp[2][MAXL][MAXL];
int C[MAXL][MAXL];

template <typename T> T mineq(T& x, T y) {
  if (y < x) {
    x = y;
  }
}

int main() {
  int t=1;
  //scanf("%d", &t);
  for (int ii = 0; ii < t; ++ii) {
    scanf("%d%d", &l, &n);
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 0; i < l; ++i) {
      for (int j = 0; j < l; ++j) {
        scanf("%d", C[i]+j);
      }
    }

    int curr = 0;
    int prev = 1;
    int c = 2;
    dp[prev][0][1] = 0;
    dp[prev][1][0] = 0;

    for (int i = 0; i < n; ++i) {
      int d;
      scanf("%d", &d);
      --d;

      for (int a = 0; a < l; ++a) {
        for (int b = 0; b < l; ++b) {
          if (a != c && b != d && c != d) {
            mineq(dp[curr][b][c], dp[prev][a][b] + C[a][d]);
            mineq(dp[curr][c][b], dp[prev][a][b] + C[a][d]);
          }

          if (b != c && a != d && c != d) {
            mineq(dp[curr][a][c], dp[prev][a][b] + C[b][d]);
            mineq(dp[curr][c][a], dp[prev][a][b] + C[b][d]);
          }

          if (a != d && b != d) {
            mineq(dp[curr][a][b], dp[prev][a][b] + C[c][d]);
            mineq(dp[curr][b][a], dp[prev][a][b] + C[c][d]);
          }

          dp[prev][a][b] = INF;
        }
      }

      c = d;
      curr ^= 1;
      prev ^= 1;
    }

    int sol = INF;
    for (int a = 0; a < l; ++a) {
      for (int b = 0; b < l; ++b) {
        sol = min(sol, dp[prev][a][b]);
      }
    }

    printf("%d\n", sol);
  }
  return 0;
}
