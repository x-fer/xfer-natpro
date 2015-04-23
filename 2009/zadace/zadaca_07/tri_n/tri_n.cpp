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
const int MAXN = 10000000;

int dp[ MAXN ];
llint maks = -1;

int f( llint x ) {
    if( x > maks ) maks = x;
    if( x == 1 ) return 1;
    if( x < MAXN && dp[x] != -1 ) return dp[x];

    int t = -1;

    if( x%2 ) t = f( 3*x + 1 ) + 1;
    else t = f( x/2 ) + 1;

    if( x < MAXN ) dp[x] = t;
    return t;
}

int main( void )
{
    int l, r; scanf( "%d %d", &l, &r );
    int maxf = -1;

    llint sum = 0;
    memset( dp, -1, sizeof dp );

    for( int i = l; i <= r; ++i ) {        
        int t = f(i);
        if( t > maxf ) maxf = t;
        sum += t;
    }

    printf( "%lld\n", sum );
    return (0-0);
}
