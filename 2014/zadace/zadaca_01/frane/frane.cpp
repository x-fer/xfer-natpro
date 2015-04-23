#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 100010;
const double EPS = 1e-7;

int N;
int nums[MAXN];

double distance(double t) {
  double sol = 0.0;
  for (int i = 0; i < N; ++i) {
    sol += (t - nums[i]) * (t - nums[i]);
  }
  return sol;
}

int main(void) {
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    scanf("%d", nums + i);
  }

  double lo = 1.0, hi = 100000.0, mid;
  while (hi - lo > EPS) {
    double t = (hi - lo) / 3.0;
    double t1 = lo + t;
    double t2 = t1 + t;

    if (distance(t1) > distance(t2)) {
      lo = t1;
    } else {
      hi = t2;
    }
  }

  printf("%.3lf\n", distance(lo));
  return 0;
}
