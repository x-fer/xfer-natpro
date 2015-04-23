#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main( int argc, char **argv ){
	
	int mat[ 12 ][ 102 ];
	int r, c;	scanf( "%d%d", &r, &c );
	int sol = 0;
	
	for( int i = 0; i < r; ++i ){
		for( int j = 0; j < c; ++j ){
			scanf( "%d", &mat[i][j] );
		}
	}
	
	int sol1 = sol;

	for( int i = 0; i < ( 1 << r ); ++i){
		int temp = 0;
		for( int j = 0; j < c; ++j ){
			int col_sum = 0;
			
			for( int k = 0; k < 11; ++k ){
				if( (i & (1<<k)) == 0 )continue;
				col_sum += mat[k][j];
			}
			if( col_sum > 0 ) temp += col_sum;
		}
		
		
		if( temp > 0 )sol1 = max( sol1, temp );
	}
	
	printf( "%d\n", sol1);
	return 0;
}
