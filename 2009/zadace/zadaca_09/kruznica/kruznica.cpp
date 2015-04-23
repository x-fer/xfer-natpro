#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <ctime>

using namespace std;

int N, M;
int Xs, Ys, Rs;

int ispitaj(int Xt, int Yt) {
  char odgovor[10];

  printf( "ispitaj %d %d\n", Xt+1, Yt+1 );
  scanf( "%s", odgovor );

  return strcmp( odgovor, "unutra" ) == 0;
}

int binary_search(int Xd, int Yd) {
  int l = 0, m = 0, r = max( N, M );
  int Xm, Ym;

  while( l < r ) {
    m = (l+r+1)/2;

    Xm = Xs+Xd*m, Ym = Ys+Yd*m;
    if( Xm < 0 || Xm >= N || Ym < 0 || Ym >= M ) {
      r = m-1;
      continue;
    }

    if( ispitaj( Xm, Ym ) ) {
      l = m;
    } else {
      r = m-1;
    }
  }
  
  return l;
}

void nadji_uniformno() {
  for( int density = 2; ; density *= 1.5 ) {
    int rx = max( 1, N/density );
    int ry = max( 1, M/density );
    
    for( int i = 0; i < N; i += rx ) 
      for( int j = 0; j < M; j += ry ) 
	if( ispitaj( i, j ) ) {
	  Xs = i;
	  Ys = j;
	  return;
	} 
  }
}

int main() {
  scanf( "%d %d", &N, &M );

  nadji_uniformno();
  
  int dist1 = binary_search( 0, -1 );
  int dist2 = binary_search( 0, 1 );

  Ys += (dist2-dist1)/2;
  
  dist1 = binary_search( -1, 0 );
  dist2 = binary_search( 1, 0 );

  Xs += (dist2-dist1)/2;

  Rs = (dist1+dist2)/2;

  printf( "rjesenje %d %d %d\n", Xs+1, Ys+1, Rs );
  
  return 0;
}
