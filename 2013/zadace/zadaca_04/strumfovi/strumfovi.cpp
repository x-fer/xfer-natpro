#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1010;
const int m = 3;

int n;
char P[MAXN][m+1];
int dp[MAXN][m];

int prebroji(int i, int j, int k) {
  if (k < j) return prebroji(i, k, j);
  int x = 0;
  for (int l = j; l <= k; ++l) {
    if (P[i][l] == 'X') {
      return -1;
    } else if (P[i][l] == 'J') {
      ++x;
    }
  }
  return x;
}

int solve(int i, int j) {
  if (i < 0 || i >= n) {
    return 0;
  }
  if (j < 0 || j >= m) {
    return 0;
  }
  if (P[i][j] == 'X') {
    return -MAXN;
  }

  int &ref = dp[i][j];
  if (ref != -1) {
    return ref;
  }
  ref = 0;

  for (int k = 0; k < m; ++k) {
    int x = prebroji(i, j, k);
    if (x != -1) {
      ref = max(ref, x + solve(i+1, k));
    }
  }

  return ref;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf(" %s", P[i]);
  }

  memset(dp, -1, sizeof(dp));
  printf("%d\n", solve(0, 0));

  return 0;
}
