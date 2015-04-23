#include <algorithm>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define REP(i, n) FOR(i, 0, n)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define TRACE(x) cout << #x << " = " << (x) << endl

typedef long long llint;

struct Edge {
  int h;
  int x;
  int dir; // 0 -> L, 1 -> R

  friend bool operator < (const Edge& a, const Edge& b) {
    if (a.h != b.h) return a.h < b.h;
    if (a.dir != b.dir) return a.dir < b.dir;
    if (a.dir == 0) { // !?
      return a.x > b.x;
    } else {
      return a.x < b.x;
    }
  }
};

const int mod = 1e9 + 7;
const int MAXNEB = 5e5 + 123;

int dp[MAXNEB];

vector<Edge> es;

int main(void)
{
  int n_neb, n_e, start; scanf("%d %d %d", &n_neb, &n_e, &start); --start;
  REP(i, n_neb) scanf("%*d");
  REP(i, n_e) {
    int h, x, dir; scanf("%d %d %d", &h, &x, &dir); --h; --x;
    es.push_back((Edge){h, x, dir});
  }

  memset(dp, 0, sizeof dp);
  dp[start] = 1;
  sort(es.begin(), es.end());

  REP(i, n_e) {
    Edge e = es[i];
    if (e.dir == 0) {
      if ((dp[e.x-1] += dp[e.x]) >= mod) dp[e.x-1] -= mod;
    } else {
      if ((dp[e.x+1] += dp[e.x]) >= mod) dp[e.x+1] -= mod;
    }
  }

  REP(i, n_neb) printf("%d\n", dp[i]);
  return 0;
}
