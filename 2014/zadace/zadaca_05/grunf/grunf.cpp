/*
  Natjecateljsko programiranje:
  2. Domaca zadaca
  Zadatak GRUNF

  autor rjesenja: Bruno Rahle

  Zadatak cemo jednostavno pretvoriti u trazenje najkraceg puta tako da uzmemo
  logaritam od cijena bridova te da, umjesto mnozenja, zbrajamo cijene. Ovakav
  problem najcesce se rijesava algoritmom Bellman-Ford, buduci da je on
  sposoban detektirati cikluse negativne duljine. Kako je moguce da ne mozemo
  uci u jedan takav ciklus ili iz njega otici u krajnju tocku, to moramo
  dodatno provjeriti. U ovom slucaju to je implementirano pomocu DFS-a.
*/

#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int NULA = 0;
const int MAXN = 302;
const int MAXM = 20002;

const long double inf = 1e302;
#define FORC( it, C ) for( __typeof( (C).begin() ) it = (C).begin(); it != (C).end(); ++it )
typedef long double ld;
typedef vector< int >* vint_ptr;

struct edge {
  int a, b;
  ld cost;
  void get( void ) { scanf( "%d%d%Lf", &a, &b, &cost ); --a; --b; cost = log( cost );  }
};

edge E[ MAXM ];
vector< int > normalni[ MAXN ], okrenuti[ MAXN ];
int PI[ MAXN ];
ld V[ MAXN ];
int n, m;
bool mogu_od_prvog[ MAXN ], mogu_do_zadnjeg[ MAXN ];

/*
  DFS prima trenutni cvor, niz posjecenih cvorova te niz vektora koji
  predstavljaju bestezinske bridove. Kako ce biti potrebno naci moze li se od
  prvog cvora doci do nekog cvora u ciklusu te moze li se iz ciklusa doci u
  zadnji cvor, to cemo najelegantnije izvesti na slijedeci nacin:
    * U dva niza vektora, normalni i okrenuti, za svaki cvor pamtit cemo
      njegove susjede odnosno cvorove kojima je on susjedan
    * Da bismo provjerili mozemo li doci do nekog cvora iz prvog, pozvat cemo
      dfs za prvi cvor sa normalnim bridovima, a on ce u nizu
      mogu_od_prvog sve cvorove do kojih mozemo doci postaviti na jedan
    * Da bismo provjerili mozemo li doci do zadnjega iz nekog cvora, pozvat
      cemo dfs za zadnji cvor sa okrenutim bridovima, a on ce u nizu
      mogu_do_zadnjega sve cvorove iz kojih mozemo doci postaviti na jedan
*/

void dfs( int x, bool *posjetio, const vint_ptr& bridovi ) {
  if( posjetio[ x ] ) return;
  posjetio[ x ] = 1;

  FORC( it, bridovi[x] )
    dfs( *it, posjetio, bridovi );
}

inline bool relax( const edge &E ) {
  if( V[E.a] + E.cost >= V[E.b] ) return 0;
  V[E.b] = V[E.a] + E.cost;
  PI[E.b] = E.a;
  return 1;
}

inline void bellman_ford( void ) {
  for( int i = 0; i < n; ++i ) V[i] = inf;
  V[0] = 0.0;

  for( int i = 0; i < n-1; ++i )
    for( int j = 0; j < m; ++j )
      relax( E[j] );

  dfs( 0,   mogu_od_prvog,   normalni );
  dfs( n-1, mogu_do_zadnjeg, okrenuti );
  for( int j = 0; j < m; ++j )
    if( relax( E[j] ) && mogu_od_prvog[ E[j].a ] && mogu_do_zadnjeg[ E[j].b ] )
      throw 1;

  if( V[n-1] == inf )
    throw 2;
}


int main( void ) {
  scanf( "%d%d", &n, &m );
  for( int i = 0; i < m; ++i ) {
    E[i].get();
    normalni[ E[i].a ].push_back( E[i].b );
    okrenuti[ E[i].b ].push_back( E[i].a );
  }

  try {
    bellman_ford();
  } catch( int x ) {
    if( x == 1 ) printf( "tezi 0\n" );
    if( x == 2 ) printf( "nemoguce\n" );
    return NULA;
  }

  printf( "%.10Lf\n", exp( V[n-1] ) );

  return NULA;
}

