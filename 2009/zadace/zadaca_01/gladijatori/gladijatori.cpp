/*
  Natjecateljsko programiranje:
  1. Domaca zadaca
  Zadatak GLADIJATORI

  autor rjesenja: Bruno Rahle

  Zadatak je vrlo lako svesti na provjeru je li neki graf (ne nuzno povezan!)
  moguce pobojati u dvije boje. Stoga je, jedno od mogucih rjesenja da ga
  pokusamo tako pobojati. To se jednostavno implementira pomocu DFS-a ili
  BFS-a. Ako se ikada dogodi da bismo neki cvor trebali pobojati u dvije
  razlicite boje, tada nema rjesenja. U suprotnom potrebno je ispisati sve
  cvorove koje smo pobojali u istu boju. Slozenost tog rjesenja jest O(N+M),
  sto je dovoljno brzo.
*/

#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
const int NULA = 0;
const int MAXN = 100100;
#define FORC( it, C ) for( __typeof( (C).begin() ) it = (C).begin(); it != (C).end(); ++it )

int n, m;
vector< int > E[ MAXN ];
int C[ MAXN ];
bool ok = 1;

enum { NIJE_POBOJAN = -1, BIJELA, CRNA };

inline void input( void ) {
  scanf( "%d%d", &n, &m );
  memset( C, -1, sizeof( C ) );

  for( int i = 0, a, b; i < m; ++i ) {
    scanf( "%d%d", &a, &b );
    --a; --b;
    E[a].push_back( b );
    E[b].push_back( a );
  }
}

bool dfs( int i, int c ) {
  if( C[i] != NIJE_POBOJAN ) return C[i] == c;
  C[i] = c;

  FORC( it, E[i] )
    if( !dfs( *it, c^1 ) )
      return 0;

  return 1;
}

inline void solve( void ) {
  for( int i = 0; i < n; ++i )
    if( C[i] == -1 && !dfs( i, BIJELA ) ) {
      ok = 0;
      return;
    }
}

inline void output( void ) {
  if( !ok ) { printf( "-1\n" ); return; }
  for( int i = 0; i < n; ++i ) if( C[i] == CRNA ) printf( "%d ", i+1 );
  printf( "\n" );
}

int main( void ) {
  input();
  solve();
  output();

  return NULA;
}

