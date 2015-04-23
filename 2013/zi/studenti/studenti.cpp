#include <cstdio>
#include <vector>
#include <cassert>
#include <algorithm>
using std::vector;

const int oo = 0x3f3f3f3f;

typedef long long llint;

struct pravac {
  llint k, l;
  pravac(llint k = 0, llint l = 0) :
      k(k), l(l) { }

  llint eval(llint x) const {
    return k * x + l;
  }
  pravac operator+ (const pravac &rhs) const {
    return pravac(k + rhs.k, l + rhs.l);
  }
  pravac operator- (const pravac &rhs) const {
    return pravac(k - rhs.k, l - rhs.l);
  }
};

struct student {
  int from, to;
  pravac g;
  bool in_the_house(int x) const {
    return from <= x && x <= to;
  }
};

struct event {
  int x, is_start, who;
  event(int x = 0, int is_start = 0, int who = 0) :
      x(x), is_start(is_start), who(who) { }

  bool operator< (const event &rhs) const {
    return x < rhs.x;
  }
};

int N;
vector<student> studenti;
vector<event> eventi;

void load() {
  scanf("%d", &N);
  for (int j = 0; j < N; ++j) {
    int poc, pojacanje;
    student s;
    scanf("%d%d%d%d", &s.from, &s.to, &poc, &pojacanje);
    s.g.k = pojacanje;
    s.g.l = poc - (llint) pojacanje * s.from;
    eventi.push_back(event(s.from, true, studenti.size()));
    eventi.push_back(event(s.to + 1, false, studenti.size()));
    studenti.push_back(s);
  }
}

llint solve() {
  std::sort(eventi.begin(), eventi.end());
  pravac S;
  llint ret = 0;
  for (size_t _e = 0; _e < eventi.size(); ++_e) {
    event &e = eventi[_e];
    student &s = studenti[e.who];
    if (_e && e.x != eventi[_e-1].x) {
      ret = std::max(ret, S.eval(eventi[_e-1].x));
      ret = std::max(ret, S.eval(e.x - 1));
    }
    if (e.is_start) {
      S = S + s.g;
    } else {
      S = S - s.g;
    }
  }
  assert(!S.k && !S.l);
  return ret;
}

int main() {
  load();
  printf("%lld\n", solve());
  return 0;
}
