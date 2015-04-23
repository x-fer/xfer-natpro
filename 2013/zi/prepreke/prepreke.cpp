#include <cstdio>

using namespace std;

const int MAXN = 110;

char a[MAXN][MAXN];
bool win[MAXN][MAXN];
int x, y;

int main(void) {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%s", a[i]);
  scanf("%d %d", &x, &y);

  for (int i = n-1; i >= 0; --i)
    for (int j = n-1; j >= 0; --j)
      if (a[i][j] != '#') {
        win[i][j] = false;
        if (i+1 < n && a[i+1][j] != '#' && !win[i+1][j]) win[i][j] = true;
        if (j+1 < n && a[i][j+1] != '#' && !win[i][j+1]) win[i][j] = true;
      }

  if (win[x][y]) puts("Mirko"); else
    puts("Slavko");
  return 0;
}
