#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

using namespace std; 

struct event {
  int position, height, type; 
  
  event( int _p, int _h, int _t ) {
    position = _p;
    height   = _h;
    type     = _t;
  }

  friend bool operator < ( const event &A, const event &B ) {
    if( A.position != B.position ) return A.position < B.position;
    if( A.type != B.type ) return A.type < B.type;
    if( A.height != B.height ) return A.height < B.height;
    return true;
  }
};

vector< event > v;
multiset< int > s;

inline void insert() {
  int x; scanf( "%d", &x ); 
  v.push_back( event( x, -1, 2 ) );
}

int main() {
  int n; scanf( "%d", &n ); 
  for( int i = 0; i < n; ++i ) {
    int x, y, h;
    scanf( "%d%d%d", &x, &y, &h );
    v.push_back( event( x+0, h, +1 ) );
    v.push_back( event( y+1, h, -1 ) );
  }
  insert(); 
  insert();

  sort( v.begin(), v.end() ); 

  int curr = 0, st = 0, ed, sol = 0;

  s.insert( 0 );
  for( int i = 0; v[i].type != 2; ++i ) {
    if( v[i].type == +1 ) s.insert( v[i].height );
    else s.erase( s.find(v[i].height) );
    curr = *s.rbegin();
    st = i+1;
  }

  for( ed = st+1; v[ed].type != 2; ++ed );
  
  for( int i = st+1, j; i < ed; i = j ) {
    for( j = i; j < ed && v[i].position == v[j].position; ++j )
      if( v[j].type == +1 ) s.insert( v[j].height );
      else s.erase( s.find(v[j].height) );

    sol += abs( curr - *s.rbegin() );
    curr = *s.rbegin();
  }

  printf( "%d\n", sol );

  return 0;
}
