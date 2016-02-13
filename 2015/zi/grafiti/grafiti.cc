#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define mp make_pair
#define pb push_back
#define sz(s) (int)((s).size())
#define eps 10e-7

typedef long long ll;
typedef pair<int, int> pint;

const int MAX = 100010;
const int POC = 0;
const int KRAJ = 1;

struct event {
  int pos;
  int type;
  int h;
};

vector<event> W;

int main() {
  int n;
  scanf("%d", &n);
  REP(i, n) {
    int l, r, h;
    scanf("%d %d %d", &l, &r, &h);
    W.push_back({l, POC, h});
    W.push_back({r, KRAJ, h});
  }

  sort(W.begin(), W.end(), [](const event &a, const event &b) {
    if (a.pos != b.pos)
      return a.pos < b.pos;
    return a.h < b.h;
  });

  set<int, greater<int>> heights;
  heights.insert(0);

  ll len = 0;
  int i = 0;
  int sz = sz(W);
  while (i < sz) {
    int prev_pos = i ? W[i - 1].pos : W[0].pos;
    int pos = W[i].pos;
    int prev_h = *heights.begin();
    while (i < sz && pos == W[i].pos) {
      if (W[i].type == POC)
        heights.insert(W[i].h);
      else
        heights.erase(W[i].h);
      i++;
    }
    len += pos - prev_pos;
    len += abs(prev_h - *heights.begin());
  }

  printf("%lld\n", len);
  return 0;
}

