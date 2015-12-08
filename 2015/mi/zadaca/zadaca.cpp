#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

const int off = 1<<17;

int T[2*off];

int get(int i, int lo, int hi, int a, int b) {
  if (lo >= b || hi <= a) return 0;
  if (lo >= a && hi <= b) return T[i];
  return __gcd(get(i*2, lo, (lo+hi)/2, a, b), get(i*2+1, (lo+hi)/2, hi, a, b));
}

int main(void) {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &T[off+i]);

  for (int i = off-1; i > 0; --i)
    T[i] = __gcd(T[i*2], T[i*2+1]);

  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    int j = i;
    while (j < n) {
      int cur = get(1, 0, off, i, j + 1);
      int lo = j, hi = n-1;
      while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (get(1, 0, off, i, mid + 1) == cur) lo = mid;
        else hi = mid - 1;
      }

      ans += (long long)(lo-j+1) * cur;
      j = lo + 1;
    }
  }

  printf("%lld\n", ans);
  return 0;
}
