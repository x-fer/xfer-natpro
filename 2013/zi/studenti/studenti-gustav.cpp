#include <cstdio>
#include <cstring>

#include <vector>
#include <algorithm>

using namespace std;
typedef long long llint;

#define MAXN 100005

int N;
int Tdolazak;
int Todlazak;
int gpocetno;
int gpojacanje;

struct event {
  int type;
  int t;
  llint k, l;
  event(int type, int t, llint k, llint l) : type(type), t(t), k(k), l(l) {}
  friend bool operator<(const event &a, const event &b) {
    if (a.t == b.t) return a.type < b.type;
    return a.t < b.t;
  }
};

vector< event > e;

llint sweep() {
  llint k = 0, l = 0;
  llint sol = 0;

  for (int i = 0; i < e.size(); ++i) {
    k += e[i].k;
    l += e[i].l;
    if (e[i].type % 2 != 0) 
      sol = max(sol, k * e[i].t + l);
  }

  return sol;
}

int main(void)
{
  scanf("%d", &N);

  for (int i = 0; i < N; ++i) {
    scanf("%d%d%d%d", &Tdolazak, &Todlazak, &gpocetno, &gpojacanje);

    llint k = gpojacanje;
    llint l = gpocetno - (llint)gpojacanje * Tdolazak;

    e.push_back(event(1, Tdolazak - 1, 0, 0));
    e.push_back(event(0, Tdolazak, +k, +l));
    e.push_back(event(1, Tdolazak, 0, 0));

    e.push_back(event(1, Todlazak, 0, 0));
    e.push_back(event(2, Todlazak, -k, -l));
    e.push_back(event(1, Todlazak + 1, 0, 0));
  }

  sort(e.begin(), e.end());
  printf("%lld\n", sweep());

  return 0;
}
