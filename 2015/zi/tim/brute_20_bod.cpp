#include <algorithm>
#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

const int MAXN = 100100;
const int P = 9973;
const int mod = 1e9 + 7;

bool in[MAXN]; // je li trenutno unutra
vector<pair<int, int>> e; // events

int main(void) {
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    e.push_back({a, i});
    e.push_back({b, i});
    e.push_back({c, i});
    e.push_back({d, i});
  }

  sort(e.begin(), e.end());
  set<vector<int>> S;
  S.insert({});

  int tot = 0;
  vector<int> cur;
  for (auto& p: e) {
    if (in[p.second]) {
      in[p.second] = false;
      cur.erase(lower_bound(cur.begin(), cur.end(), p.second));
    } else {
      in[p.second] = true;
      cur.insert(lower_bound(cur.begin(), cur.end(), p.second), p.second);
    }
    tot += cur.size();
    S.insert(cur);
  }
  printf("%d\n", (int)S.size() - 1);
  return 0;
}
