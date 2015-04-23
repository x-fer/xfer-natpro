/*
  Goran Zuzic
  Natjecateljsko programiranje 2009/2010 - 1. ispit
  Zadatak Neboderi, O( NlgN + Q ) rjesenje
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

const int mod = 1000000007;
const int MAXN = 100100;

typedef long long llint;

int n, q;

llint Prefix[ MAXN ];
llint Inverz[ MAXN ];

long long power_mod( long long b, long long e, long long mod )
{
    if( e == 0 ) return 1 % mod;
    if( e == 1 ) return b % mod;
    if( e&1 ) return ( power_mod( b, e-1, mod ) * b ) % mod;
    long long tmp = power_mod( b, e >> 1, mod ); return ( tmp * tmp ) % mod;
}

int main( void )
{
    scanf( "%d %d", &n, &q );

    Prefix[0] = Inverz[0] = 1;

    for( int i = 0; i < n; ++i ) {
        long long x; scanf( "%lld", &x );
        Prefix[i+1] = ( Prefix[i] * x ) % mod;
    }

    for( int i = 1; i <= n; ++i )
        Inverz[i] = power_mod( Prefix[i], mod-2, mod );

    for( int i = 0; i < q; ++i ) {
        int l, r; scanf( "%d %d", &l, &r ); --l, --r;
        if( l > r ) swap( l, r );
        printf( "%lld\n", ( Prefix[r+1] * Inverz[l] ) % mod );
    }


    return (0-0);
}

