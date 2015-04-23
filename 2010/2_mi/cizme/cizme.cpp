# include <cstdio>
# include <iostream>
# include <cstring>
# include <algorithm>

using namespace std;

const int MXN = 2010;
const int MOD = 1000000007;

int dp[ MXN ][ MXN ];

int f( int m, int zadnji ){
    if( m == 0 )
        return 1;
    if( zadnji > m || m < 0 )
        return 0;
    if( dp[ m ][ zadnji ] != -1 )
        return dp[ m ][ zadnji ];
    int sol = 0;
    return dp[ m ][ zadnji ] = ( f( m - ( zadnji + 1 ), zadnji + 1 ) + f( m, zadnji + 1 ) ) % MOD;
}

int M;

int main( void ){
    memset( dp, -1, sizeof dp );
    scanf( "%d", &M );
    printf( "%d\n", f( M, 0 ) );
    return 0;
}
