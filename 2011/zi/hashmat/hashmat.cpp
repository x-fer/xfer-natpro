#include <iostream>
#include <cstdio>
#include <cstring>
#include <cassert>

using namespace std;
#define MAXN 100008

int a, b, m, k;
char s[MAXN];
int n;

int pot[MAXN];

int main(){
  scanf("%d%d%d%d", &a, &b, &m, &k);
  scanf("%s", s);
  n = strlen(s);

  pot[0] = 1;
  for(int i = 1; i < MAXN; ++i)
    pot[i] = ((long long) pot[i-1] * a) % m;

  int hash = 0;
  for(int i = 0; i < k; ++i)
    hash = (hash + (long long) pot[k-i] * (s[i] + b)) % m;
  printf("%d\n", hash);
  assert(hash >= 0);

  for(int i = k; i < n; ++i){
    hash = ((hash - (long long) pot[k] * (s[i-k] + b)) % m + m) % m;
    hash = ((long long) hash * a + (long long) (s[i] + b) * a) % m;
    printf("%d\n", hash);
    assert(hash >= 0);
  }

  return 0;
}

