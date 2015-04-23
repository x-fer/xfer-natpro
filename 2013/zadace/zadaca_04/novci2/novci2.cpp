#include <algorithm>
#include <cstdio>

using namespace std;

const int MAXN = 1010;
const int MAXM = 1010;
const int INF = 0x3f3f3f3f;

int n, m;
int dp[MAXM][MAXN];
bool izracunao[MAXM][MAXN];
int vrijednost[MAXN];

int izbroji(int zbroj, int koji) {
  if (zbroj == m) {
    return 0;
  }
  if (zbroj > m || koji == n) {
    return INF;
  }
  if (izracunao[zbroj][koji]) {
    return dp[zbroj][koji];
  }
  izracunao[zbroj][koji] = 1;
  return dp[zbroj][koji] = min(
    1 + izbroji(zbroj+vrijednost[koji], koji+1),
    izbroji(zbroj, koji+1)
  );
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", vrijednost+i);
  }

  int rezultat = izbroji(0, 0);
  printf("%d\n", rezultat == INF ? -1 : rezultat);

  return 0;
}
