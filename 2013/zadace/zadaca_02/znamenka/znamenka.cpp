#include <cstdio>

using namespace std;

typedef long long llint;

const llint MAX = 1e17;

llint count(llint m) {
  llint l = 1, r = 10, c = 1, ans = 0;
  while (r <= m) {
    ans += (r-l)*c;
    c++, l = r, r *= 10;
  }
  return ans + (m-l+1)*c;
}

int main(void) {
  llint x;
  scanf("%lld", &x);
  
  llint lo = 1, hi = MAX;
  while (lo < hi) {
    llint mid = (lo + hi)/2;
    if (count(mid) < x) lo = mid+1; else
      hi = mid;
  }
  
  char buff[20];
  sprintf(buff, "%lld", lo);
  putchar(buff[x-count(lo-1)-1]);
  return 0;
}
