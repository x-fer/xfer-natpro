#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

int n, t;
vector< pair<int,int> > grad;
vector<int> xes;
vector<int> yes;

int dobar(int a, int b, int y) {
  int l, h, ret = 0;

  l = max(a, 0), h = min(b, t);
  if (l <= h) {
    ret += h + 1 - (lower_bound(yes.begin() + l, yes.begin() + h + 1, y) - yes.begin());
  }

  l = max(a, t + 1), h = min(b, n - 1);
  if (l <= h) {
    ret += (lower_bound(yes.begin() + l, yes.begin() + h + 1, y - 1, greater<int>()) - yes.begin()) - l;
  }

  return ret;
}

int solve(int a, int b, int k) {
  a = lower_bound(xes.begin(), xes.end(), a) - xes.begin();
  b = lower_bound(xes.begin(), xes.end(), b + 1) - xes.begin() - 1;

  if (a > b || b - a + 1 < k) return -1;
  
  int l = 0, h = 1000000000;

  while (l < h) {
    int m = (l + h + 1) / 2;
    if (dobar(a, b, m) >= k) {
      l = m;
    } else {
      h = m - 1;
    }
  }
  
  return l;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    grad.push_back(make_pair(x, y));
  }

  sort(grad.begin(), grad.end());
  for (int i = 0; i < n; ++i) {
    t = i;
    if (i != n-1 && grad[i+1].second < grad[i].second) {
      break;
    }
  }

  for (int i = 0; i < n; ++i) {
    xes.push_back(grad[i].first);
    yes.push_back(grad[i].second);
  }

  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    int a, b, k;
    scanf("%d%d%d", &k, &a, &b);

    int sol = solve(a, b, k);
    if (sol == -1) {
      printf("nema\n");
    } else {
      printf("%d\n", sol);
    }
  }

  return 0;
}
