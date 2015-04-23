#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>
#include <vector>
using namespace std;
const int NULA = 0;
const int MAXN = 100100;
const int MAXC = 100;

typedef pair< int, int > par;
set< par > S;
vector< int > A[ MAXC ][ 2 ];
int n, m, c;
int pisi;

void generate_pair( void ) {
  int a, b, i;
  i = rand() % c;
  a = rand() % A[i][0].size();
  b = rand() % A[i][1].size();
  
  if( !S.count( par( A[i][0][a], A[i][1][b] ) ) ) {
    S.insert( par( A[i][0][a], A[i][1][b] ) );
    printf( "%d %d\n", A[i][0][a]+1, A[i][1][b]+1 );
    if( pisi ) fprintf( stderr, "%d--%d;\n", A[i][0][a]+1, A[i][1][b]+1 );
    return;
  }
  generate_pair();
}

int main( int argc, char *argv[] ) {
  n = atoi( argv[1] );
  m = atoi( argv[2] );
  c = atoi( argv[3] );
  if( argc >= 5 ) pisi = atoi( argv[4] );
  
  int xXx;
  srand( time( 0 ) * (int)&xXx );

  if( pisi ) fprintf( stderr, "graph G {\n" );
  for( int i = 0; i < n; ++i ) 
    A[ rand() % c ][ rand() & 1 ].push_back( i );

  printf( "%d %d\n", n, m );
  for( int i = 0; i < m; ++i )
    generate_pair();
  
  if( pisi ) fprintf( stderr, "}\n" );
  
  return NULA;
}


