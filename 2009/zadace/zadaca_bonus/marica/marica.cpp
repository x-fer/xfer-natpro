#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>

#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <utility>
#include <functional>

#include <cmath>
#include <cstring>
#include <ctime>
using namespace std;
const int NULA = 0;
const int MAXN = 1010;
const int MAXM = MAXN * ( MAXN - 1 ) / 2;
const int inf = 0x3f3f3f3f;
#define FORC( it, C ) for( __typeof( (C).begin() ) it = (C).begin(); it != (C).end(); ++it ) 

struct edge {
  int b, v, id;
  edge( void ) : b( -1 ) {}
  edge( int _b, int _v, int _id ) : b( _b ), v( _v ), id( _id ) {}
};

typedef pair< int, int > par;

vector< edge > E[ MAXN ];
int n, m;
bool smijem[ MAXM ];
set< par > S;
int dist[ MAXN ];
int pi[ MAXN ];
vector< int > put;

inline void input( void ) {
  scanf( "%d%d", &n, &m );
  int a, b, v;
  for( int i = 0; i < m; ++i ) {
    scanf( "%d%d%d", &a, &b, &v );
    --a; --b;
    E[a].push_back( edge( b, v, i ) );
    E[b].push_back( edge( a, v, i ) );
    smijem[i] = 1;
  }
}

int dijkstra( void ) {
  S.clear();
  memset( dist, 0x3f, sizeof( dist ) );
  memset( pi, -1, sizeof( pi ) ); 
  dist[0] = 0;
  
  for( int i = 0; i < n; ++i ) 
    S.insert( par( dist[i], i ) );
  int sad;
  
  for( int i = 0; i < n; ++i ) {
    sad = S.begin()->second;
    S.erase( S.begin() );
    //    printf( "obradujem %d, %d\n", sad, dist[sad] );

    if( sad+1 == n ) return dist[sad];
    
    FORC( it, E[sad] )
      if( smijem[ it->id ] && dist[sad] + it->v < dist[it->b] ) {
        S.erase( par( dist[it->b], it->b ) );
        pi[ it->b ] = sad;
        dist[it->b] = dist[sad] + it->v;
        S.insert( par( dist[it->b], it->b ) );
      }
  }
  
  return dist[ n-1 ];
}

int getID( int a, int b ) {
  FORC( it, E[a] )
    if( it->b == b ) 
      return it->id;
  return -1;
}

void spremi( int x ) {
  if( x == -1 ) return;
  spremi( pi[x] );
  put.push_back( x );
}

int solve( void ) {
  int ret = -1;
  for( int i = 0; i+1 < (int)put.size(); ++i ) {
    int id = getID( put[i], put[i+1] );
    smijem[id] = 0;
    ret = max( ret, dijkstra() );
    smijem[id] = 1;
  }
  return ret;
}

int main( void ) {
  input();  
  dijkstra();
  spremi( n-1 );
  printf( "%d\n", solve() );
  
  return NULA;
}
