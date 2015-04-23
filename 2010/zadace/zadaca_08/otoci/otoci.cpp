#include <algorithm>
#include <functional>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <vector>
#include <string>

using namespace std;

const int MAXN = 128;

struct edge {
    int a, b, w;

    edge() {}
    edge( int _a, int _b, int _w ) : a( _b ), b( _b ), w( _w ) {}
};

vector< edge > E[ MAXN ];

int n, e;
int Otpor[ MAXN ];
int boja[ MAXN ];

enum { BIJELA = 0, SIVA, CRNA };

int dfs( int x )
{
    int sum = Otpor[x];
    boja[ x ] = SIVA;

    for( vector< edge >::iterator it = E[x].begin(); it != E[x].end(); ++it ) {
        if( boja[ it->b ] == SIVA ) sum += it->w;
        if( boja[ it->b ] == BIJELA ) sum += dfs( it->b );
    }

    boja[ x ] = CRNA;
    return sum;
}

int main( void )
{
    memset( boja, 0, sizeof boja );
    scanf( "%d %d", &n, &e );

    for( int i = 0; i < n; ++i )
        scanf( "%d", Otpor + i );

    for( int i = 0; i < e; ++i ) {
        int a, b, w; scanf( "%d %d %d", &a, &b, &w ); --a, --b;
        E[a].push_back( edge( a, b, w ) );
        E[b].push_back( edge( b, a, w ) );
    }

    int mini = 1000000000;

    for( int i = 0; i < n; ++i )
        if( boja[i] == BIJELA ) 
            mini = min( mini, dfs( i ) );

    printf( "%d\n", mini );
    return (0-0);
}
