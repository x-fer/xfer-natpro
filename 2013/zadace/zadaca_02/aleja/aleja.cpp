#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const double eps = 1e-7;

int mx, my;
int px, py, kx, ky;

double ans = 1e18;

double dist(double x, double y) {
  return (x-mx)*(x-mx) + (y-my)*(y-my);
}

double gety(double x) {
  return py + (x-px)/(kx-px)*(ky-py);
}

int main(void) {
  scanf("%d %d", &mx, &my);
  scanf("%d %d %d %d", &px, &py, &kx, &ky);

  if (px > kx) swap(px, kx), swap(py, ky);

  ans = min(ans, dist(px, py));
  ans = min(ans, dist(kx, ky));

  if (px == kx) {
    if (py > ky) swap(py, ky);
    if (py <= my && my <= ky) ans = min(ans, dist(px, my));
  } else {
    double lo = px, hi = kx;
    while ((hi-lo) > eps) {
      double mid = (lo+hi)/2;
      if (dist(mid, gety(mid)) > dist(mid+eps, gety(mid+eps))) lo = mid; else
        hi = mid;
    }
    ans = min(ans, dist(lo, gety(lo)));
  }

  printf("%lf\n", sqrt(ans));
  return 0;
}
