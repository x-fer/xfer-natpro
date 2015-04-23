#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <map>

using namespace std;

int n, m;
map<int,vector<int>> factors;

void Insert(int id, int p, int pot) {
  if (factors.count(p) == 0)
    factors[p] = vector<int>(n, 0);
  factors[p][id] = pot;
}

void Factorise(int id, int x) {
  for (int i = 2; i * i <= x; ++i) {
    if (x % i) continue;
    int pot = 0;
    while (x % i == 0) {
      ++pot;
      x /= i;
    }
    Insert(id, i, pot);
  }
  if (x != 1) Insert(id, x, 1);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x; scanf("%d", &x);
    Factorise(i, x);
  }
  scanf("%d", &m);

  int ans = 0;
  for (pair<int,vector<int>> powers : factors) {
    vector<int> v = powers.second;
    ++ans;
    while (true) {
      sort(v.begin(), v.end());
      reverse(v.begin(), v.end());
      if (v[0] == 0) break;
      ++ans;
      for (int i = 0; i < m && v[i]; ++i)
        --v[i];
    }
  }
  printf("%d\n", ans);
  return 0;
}

