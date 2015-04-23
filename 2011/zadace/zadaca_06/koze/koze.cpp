/*
  Natjecateljsko programiranje:
  2. Domaca zadaca
  Zadatak GLADIJATORI

  autor rjesenja: Bruno Rahle

  Za svako polje koje nismo posjetili, a nije ograda, napravimo flood-fill,
  tj. izracunamo broj koza i vukova u cijelom podrucju. Sva polja koja se
  nalaze u tom podrucju oznacimo da smo posjetili. Ako je broj koza veci od
  broja vukova, u konacan broj koza dodamo broj koza u tom podrucju, u
  suprotnom u konacan broj vukova dodamo broj vukova u poducju. Flood-fill
  mozemo implementirati pomocu BFS-a ili DFS-a, a u ovom rjesenju to je
  napravljeno pomocu BFS-a. Slozenost ovog algoritma jednaka je O(R*S).

*/

#include <cstdio>
#include <queue>
using namespace std;
const int MAXR = 255;
const int MAXS = 255;

enum { bijela, siva, crna };

char polje[ MAXR ][ MAXS ];
int boja[ MAXR ][ MAXS ];
int r, s, vukovi, koze;

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
const int ds = 4;

struct stanje {
  int x, y;
  stanje( void ) : x( -1 ), y( -1 ) {}
  stanje( int _x, int _y ) : x( _x ), y( _y ) {}

  char& polje( void ) { return ::polje[x][y]; }
  int& boja( void ) { return ::boja[x][y]; }

  bool valid( void ) { return x >= 0 && x < r && y >= 0 && y < s; }
  bool mogu( void ) { return valid() && polje() != '#' && boja() == bijela; }

  stanje add( int i ) { return stanje( x+dx[i], y+dy[i] ); }
};

queue< stanje > Q;

inline void rjesi( stanje sad, int &vukovi, int &koze ) {
  int mojih_vukova = 0;
  int mojih_koza = 0;

  sad.boja() = siva;
  for( Q.push( sad ); !Q.empty(); Q.pop() ) {
    sad = Q.front();
    if( sad.polje() == 'k' ) ++mojih_koza;
    if( sad.polje() == 'v' ) ++mojih_vukova;

    for( int i = 0; i < 4; ++i ) {
      stanje next = sad.add( i );
      if( next.mogu() ) {
        next.boja() = siva;
        Q.push( next );
      }
    }

    sad.boja() = crna;
  }

  if( mojih_koza > mojih_vukova ) koze += mojih_koza;
  else vukovi += mojih_vukova;
}

int main( void ) {
  scanf( "%d%d", &r, &s );
  for( int i = 0; i < r; ++i )
    scanf( " %s", polje[i] );

  for( int i = 0; i < r; ++i )
    for( int j = 0; j < s; ++j )
      if( polje[i][j] != '#' && boja[i][j] == bijela )
        rjesi( stanje( i, j ), vukovi, koze );

  printf( "%d %d\n", koze, vukovi );
  return 0;
}

