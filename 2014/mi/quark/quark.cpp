#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXN 1000
typedef long long llint;

llint A[MAXN], P[MAXN];
int n;
llint K;

bool p(llint X){
  llint count = 0;
  for (int i=0; i<n; i++)
    if (X >= A[i])
      count += min(X, (llint)A[i] + P[i]) - A[i];

  return count < K;
}

llint solve(void){
  llint lo = 0, hi = 1e15 + 100;
  while(lo < hi){
    llint mid = (lo + hi + 1) / 2;
    if (p(mid)) lo = mid;
    else        hi = mid - 1;
  }

  return lo;
}

int main(void){
  scanf ("%d%lld", &n, &K);
  for (int i=0; i<n; i++)
    scanf ("%lld%lld", &A[i], &P[i]);

  printf ("%lld\n", solve());

  return 0;
}
