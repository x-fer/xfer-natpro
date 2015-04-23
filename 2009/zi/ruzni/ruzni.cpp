#include <cstdio>
#include <cassert>
#include <deque>
#include <vector>
using namespace std;

typedef long long llong;

int fac[10] = {2, 3, 5, 7, 11};
int it[10];
llong niz[3000001];
int n, k = 5, s = 0;

llong get_next(int p) {
  return niz[it[p]]*fac[p];
}

void put_new(int p) {
  llong nn = get_next(p);
  if(nn != niz[s]) {
    niz[++s] = nn;;
    //    printf("%lld\n", niz[s]);
  }
}

llong solve() {
  niz[0] = 1;

  while(s < n) {
    int next = 0;

    for(int j = 1; j < k; ++j)
      if(get_next(j) < get_next(next))
	next = j;

    put_new(next);
    it[next]++;
  }

  for( int i = 1; i <= s; ++i ) assert( niz[i-1] <= niz[i] );
  return niz[s];
}

int main() {
  scanf("%d", &n);
  printf("%lld\n", solve());

  return 0;
}
