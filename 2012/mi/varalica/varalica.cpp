#include <algorithm>
#include <functional>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using namespace std; 

const int MAXN = 100001;
const int inf  = MAXN*2;

int n, k, a[MAXN];

struct tournament {
  struct node {
    int _min, _max, _diff;

    node() { set(); }

    void set( int __min = +inf, int __max = -inf, int __diff=2*inf ) {
      _min = __min;
      _max = __max;
      _diff = __diff;
    }

    void combine( const node &l, const node &r ) {
      _min = min( l._min, r._min );
      _max = max( l._max, r._max );

      _diff = min( l._diff, r._diff );
      if( r._min != inf && l._max != -inf )
        _diff = min( r._min - l._max, _diff );
    }

    void output() {
      printf( "%d, %d, %d\n", _min, _max, _diff );
    }
  } tree[MAXN<<2];

  int off, c[MAXN];
  
  tournament() {
    for( off = 1; off < MAXN; off <<= 1 );
  }

  inline void inc( int val ) {
    if( ++c[val] > 1 ) return;
    
    int i = val+off-1;
    tree[i].set( val, val );
    for( i /= 2; i > 0; i /= 2 ) 
      tree[i].combine( tree[2*i], tree[2*i+1] );
  }

  inline void dec( int val ) {
    if( --c[val] > 0 ) return;
    
    int i = val+off-1;
    tree[i].set();
    for( i /= 2; i > 0; i /= 2 ) 
      tree[i].combine( tree[2*i], tree[2*i+1] );
  }

  inline int query() {
    return tree[1]._diff;
  }
} T;

int main() {
  scanf( "%d%d", &n, &k );
  for( int i = 0; i < n; ++i ) {
    scanf( "%d", &a[i] ); 

    T.inc( a[i] );
    if( i-k >= 0 ) T.dec( a[i-k] );

    if( i > 0 ) {
      int ans = T.query();
      printf( "%d\n", (ans == 2*inf) ? 0 : ans );
    }
  }

  return 0;
}
