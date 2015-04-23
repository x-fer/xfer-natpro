#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
const int NULA = 0;
const int MAXN = 110;

const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, -1, 0, 1 };

char ploca[ MAXN ][ MAXN ];
int when[ MAXN ][ MAXN ];
int r, s;
char *znakovi = ".|#TW";
int cost[ 256 ];

struct stanje {
  int x, y;
  stanje( int _x = 0, int _y = -1 ) : x( _x ), y( _y ) {}

  char& ploca( void ) const { return ::ploca[x][y]; }
  int&  when( void )  const { return ::when[x][y];  }

  stanje add( int i ) { return stanje( x+dx[i], y+dy[i] ); }
  bool valid( void ) { return x >= 0 && x < r && y >= 0 && y < s; }
  bool mogu( int cost ) { return valid() && when() >= cost + ploca(); }

  inline friend bool operator<( const stanje &A, const stanje &B ) {
    if( A.when() != B.when() ) return A.when() < B.when();
    if( A.x != B.x ) return A.x < B.x;
    return A.y < B.y;
  }
};

set< stanje > S;
stanje poc, kraj;

inline void input( void ) {
  scanf( "%d%d", &r, &s );
  for( int i = 0; i < r; ++i ) {
    scanf( " %s", ploca[i] );
    for( int j = 0; j < s; ++j )
      if( ploca[i][j] == 'S' ) poc = stanje( i, j );
      else if( ploca[i][j] == 'C') kraj = stanje( i, j );
  }

  poc.ploca() = '.';
  kraj.ploca() = '.';

  for( int i = 0; i < 5; ++i )
    scanf( " %d", cost + znakovi[i] );
}

inline void init( void ) {
  memset( when, 0x3f, sizeof( when ) );
  poc.when() = 0;
  S.clear();
  for( int i = 0; i < r; ++i )
    for( int j = 0; j < s; ++j )
      S.insert( stanje( i, j ) );
}

inline void relax( stanje sad, int cijena ) {
  if( sad.mogu( cijena ) ) {
    S.erase( sad );
    sad.when() = cijena + cost[ (int)sad.ploca() ];
    S.insert( sad );
  }
}

inline void dijkstra( void ) {
  init();

  for( int i = 0; i < r*s-1; ++i ) {
    stanje sad = *S.begin();
    S.erase( S.begin() );

    for( int j = 0; j < 4; ++j )
      relax( sad.add( j ), sad.when() );
  }
}

inline void output( void ) {
  printf( "%d\n", kraj.when() );
}

int main( void ) {
  input();
  dijkstra();
  output();

  return NULA;
}
