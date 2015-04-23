#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;
const int MAXN = 1000005;

int a, b, c, prime[ MAXN ], countf[ MAXN ];

int broj( int p, int x ) {
	int rez = 0;
	for( int tren = p; tren <= x; tren *= p )
		rez += x / tren;
	return( rez );
}

int main( void ) {
	scanf( "%d %d %d", &a, &b, &c );
	
	fill( prime + 2, prime + MAXN, 1 );
	fill( countf, countf + MAXN, 0 );
	
	for( int i = 2; i < MAXN; ++i ) {
		if( !prime[ i ] ) continue;
		
		for( int j = 2 * i; j < MAXN; j += i )
			prime[ j ] = 0;
		
		countf[ i ] = broj( i, b ) - broj( i, a - 1 );
	}
	
	int tr = 1, org = c, rez = 1000000000;
	
	while( c > 1 ) {
		if( tr * tr > org ) tr = c;
		else tr++;
		
		int count = 0;
		while( c % tr == 0 ) {
			count++; c /= tr;
		}
		
		if( count > 0 )
			rez = min( rez, ( tr > b ? 0 : countf[ tr ] ) / count );
	}
	
	printf( "%d\n", rez );
	return( 0 );
}
