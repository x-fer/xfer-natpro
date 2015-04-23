#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MaxN = 10000005;

int loga[MaxN];

void update ( int x ) {
  for (; x < MaxN ; x += x & -x)
    ++loga[x];
}

int read ( int x ) {
  int ret = 0;
  for ( ; x > 0 ; x -= x & -x )
    ret += loga[x];

  return ret;
}

int n;

int main ( ) {

  scanf("%d",&n);
  long long ret = 0;

  memset(loga, 0, sizeof loga);

  for ( int i = 0 ; i < n ; i++ ) {
    int x;
    scanf("%d",&x);
    ret += i - read(x);
    update ( x );
  }

  printf("%lld\n",ret);
  return 0;
}
