/*
  Sluzbeno rjesenje za zadatak Rekurzija pomocu alata linearne algebre. Trebalo bi dobiti sve bodove.
  Autor: Goran Zuzic
*/

#include <algorithm>
#include <functional>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <vector>
#include <string>

using namespace std;

typedef long long llint;

const int mod = 10007;
const int N = 3;

int Init[ N ][ N ] = { 0, 1, 0, 1, 1, 1, 0, 0, 1 };
int Mat[ N ][ N ] = { 0, 1, 0, 1, 1, 1, 0, 0, 1 };
int buff[ N ][ N ];

void mnozi( int res[][N], int A[][N], int B[][N] ) {
    for( int i = 0; i < N; ++i )
        for( int j = 0; j < N; ++j ) {
            buff[i][j] = 0;

            for( int k = 0; k < N; ++k )
                buff[i][j] = ( buff[i][j] + A[i][k]*B[k][j] ) % mod;
        }

    for( int i = 0; i < N; ++i )
        for( int j = 0; j < N; ++j )
            res[i][j] = buff[i][j];
}

void matrix_power( llint e )
{
    if( e == 1 ) return ;
    if( e & 1 ) { matrix_power( e-1 ); mnozi( Mat, Mat, Init ); return ; }

    matrix_power( e / 2 );
    mnozi( Mat, Mat, Mat );
}

int main( void )
{
    llint n; scanf( "%lld", &n );
    if( n <= 1 ) { printf( "%d\n", 1 ); return (0-0); }

    matrix_power( n - 1 );
    printf( "%d\n", ( Mat[1][0] + Mat[1][1] + Mat[1][2] ) % mod );

    return (0-0);
}
