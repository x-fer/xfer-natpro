#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1010;
const int MAXM = 1010;
const int INF = 0x3f3f3f3f;

int n, m;
int dp[MAXN][MAXM];
char ploca[MAXN][MAXM];

int rekurzija(int x, int y) {
  if (x == n-1 && y == m-1) {
    return (ploca[x][y] == 'Z') + 5*(ploca[x][y] == 'D');
  }
  if (x == n || y == m || ploca[x][y] == '#') {
    return -INF;
  }
  if (dp[x][y] != -1) {
    return dp[x][y];
  }
  dp[x][y] =
    (ploca[x][y] == 'Z') +
    5*(ploca[x][y] == 'D') +
    max(
      rekurzija(x+1, y),
      rekurzija(x, y+1)
    );
  return dp[x][y];
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf(" %s", ploca[i]);
  }

  memset(dp, -1, sizeof(dp));
  printf("%d\n", rekurzija(0, 0));

  return 0;
}
