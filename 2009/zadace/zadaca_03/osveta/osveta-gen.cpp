#include <cstdio>
#include <ctime>
#include <cassert>
#include <cstdlib>
#include <set>
using namespace std;

const int MAXA = 1000000;
const int MAXN = 100000;
const int MAXM = 100000;
const int MAXP = 100000;

int n, m, p, koliko_m, koliko_p, upper_a;
multiset<int> M;

int get_rand( int lo, int hi ) {

  return lo + (rand()*rand()+rand())%(hi-lo+1);

}

void generiraj_p() {

    ++koliko_p;
    if( rand() % 2 && !M.empty() ) { // obrisi k-ti
        int k = get_rand( 1, M.size() );
        printf( "BRISI %d\n", k );

        for( multiset<int> :: iterator it = M.begin(); it != M.end(); ++it ) {
             --k;
             if( k == 0 ) {
                 M.erase( it );
                 break;
             }
        }
    } else {
        printf( "DODAJ %d\n", get_rand( 0, MAXA-1 ) );
    }

}

void generiraj_m() {

    ++koliko_m;
    printf( "KOLIKO %d\n", get_rand( 0, MAXA-1 ) );

}

int main( int argc, char *argv[] ) {

 srand( time(NULL) );

 if( argc == 1  ) {
    n = get_rand( 100, MAXN );
    m = get_rand( 100, MAXM );
    p = get_rand( 100, MAXP );
    upper_a = MAXA;
 } else if( argc != 5 ) {
    printf( "<n> (<= %d) <m> (<= %d) <p> (<= %d)\n", MAXN, MAXM, MAXP );
 } else {
    sscanf( argv[1], "%d", &n ); n = get_rand( 1, n );
    sscanf( argv[2], "%d", &m ); m = get_rand( 1, m );
    sscanf( argv[3], "%d", &p ); p = get_rand( 1, p );
    sscanf( argv[4], "%d", &upper_a );
 }

 printf( "%d %d %d\n", n, m, p );
 for( int i = 0; i < n; ++i ) {
      int a = get_rand( 0, upper_a );
      M.insert( a );
      printf( "%d\n", a );
 }

    koliko_m = 0, koliko_p = 0;
 for( int i = 0; i < m+p; ++i ) {
      if( koliko_m == m ) generiraj_p();
      else
      if( koliko_p == p ) generiraj_m();
      else {
            if( rand() % 2 ) generiraj_p();
            else             generiraj_m();
      }
 }

    assert( koliko_m == m );
    assert( koliko_p == p );

 return 0;
}
