#include <cstdio>
#include <ctime>
#include <algorithm>
#include <vector>

using namespace std;

const int mxr = 1000000, mxs = 1000000, mxn = 500;
typedef pair<int,int> par;

vector <par> niz;

int main(){
  srand( time(0) );

  int r, s, n;
  scanf( "%d %d %d", &r, &s, &n );
  if( r > mxr || s > mxs || n > mxn || n <= 0 || r <= 0 || s <= 0 ){
    fprintf( stderr, "Krivo uneseni podatci!!!!\n" );
    return 0;
  }
  printf( "%d %d\n%d\n", r, s, n );

  for( int i = 0; i < n; i++ ){
    par x;
    bool ok  = 0;
    while(!ok){
      x = par( rand()%r + 1, rand()%s + 1 );
      ok = 1;
      for( vector<par>::iterator it = niz.begin(); it != niz.end(); it++ )
	if( *it == x ) ok = 0;
    }
    niz.push_back(x);
    printf( "%d %d\n", x.first, x.second );
  }


  return 0;
}
