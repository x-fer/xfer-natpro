#include <cstdio>
#include <algorithm>
#include <cstring>
#include <ctime>
using namespace std;

int get( int lo, int hi ){
	int ret = rand() % ( hi - lo + 1 );
	return lo + ret;
}

int main( int argc, char **argv ){
	srand( (unsigned)time(NULL) );
	
	int r = get( 2, 10 );
	int c = get( 50, 100 );
	
  if (argc >= 2)
  {
    sscanf( argv[1], "%d", &r );
    sscanf( argv[2], "%d", &c );
  }
	
	printf( "%d %d\n", r, c );
	fprintf( stderr, "%d %d\n", r, c );
	
	for( int i = 0; i < r; ++i ){
		for( int j = 0; j < c; ++j ){
			printf( "%d ", get( -5000, 5000 ) );
		}
		printf( "\n" );
	}
	
	return 0;
}
