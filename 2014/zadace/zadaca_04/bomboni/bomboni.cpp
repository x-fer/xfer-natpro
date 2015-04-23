#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long llint;
const int MAXV = 2000100;

int main() {
  int n;
  static int count[MAXV];

  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x; scanf("%d", &x);
    ++count[x];
  }

  llint ans = 0;
  for (int i = 1; i < MAXV; ++i) {
    int vrecice = 0;
    for (int j = i; j < MAXV; j += i)
      vrecice += count[j];
    if (vrecice > 1)
      ans = max(ans, (llint)vrecice * i);
  }

  printf("%lld\n", ans);
  return 0;
}

