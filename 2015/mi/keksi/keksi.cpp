#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

const int MAXN = 1000100;
typedef long long llint;

int n, t;
pair<int,int> bus[MAXN];

bool check(int k) {
  int prev_time = 0;
  llint in_queue = 0ll;

  for (int i = 0; i < n; ++i) {
    int bus_size = bus[i].second;
    int _time = bus[i].first;
    in_queue = max(0ll, in_queue - (llint)(_time - prev_time) * k) + bus_size;
    prev_time = _time;
  }
  in_queue = max(0ll, in_queue - (llint)(t - prev_time) * k);
  return in_queue == 0ll;
}

int main() {
  scanf("%d%d", &n, &t);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &bus[i].first, &bus[i].second);
  }

  sort(bus, bus + n);

  int lo = 1, hi = 1000000000;
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (check(mid)) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }

  printf("%d\n", lo);
  return 0;
}
