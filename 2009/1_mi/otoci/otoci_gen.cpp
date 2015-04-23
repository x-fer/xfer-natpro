#include <algorithm>
#include <functional>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <vector>
#include <string>

using namespace std;

int n = 100;
int e = 100000;
int komp = 2;

const int MAXN = 128;
const int MAXO = 1001;

int Perm[ MAXN ];
int kraj[ MAXN ];

int Otpor[ MAXN ];

struct edge {
    int a, b, w;

    edge() {}
    edge( int _a, int _b, int _w ) : a( _a ), b( _b ), w( _w ) {}
};

vector< edge > E;
vector< int > KompList[ MAXN ];

int graf[ MAXN ][ MAXN ];

void push_edge( int a, int b, int w ) {
    E.push_back( edge( a, b, w ) );
    graf[a][b] = true;
    graf[b][a] = true;
}

int main( void )
{
    int xxx; srand( int( &xxx ) + time( 0 ) );

    for( int i = 0; i < n; ++i ) Perm[i] = i;
    random_shuffle( Perm, Perm + n );

    memset( graf, 0, sizeof graf );
    memset( kraj, 0, sizeof kraj );
    kraj[ n-1 ] = true;
    
    for( int tmp_k = komp; tmp_k > 1; ) {
        int x = rand() % (n-1);
        if( kraj[ x ] == true ) continue;
        kraj[ x ] = true; --tmp_k;
    }

    for( int i = 0; i < n; ++i )
        Otpor[i] = rand() % MAXO;

    int last = -1;
    for( int k = 0; k < komp; ++k ) {
        int first = ++last; while( kraj[last] == false ) ++last;

        for( int i = first; i <= last; ++i ) 
            KompList[k].push_back( Perm[i] );

        for( int i = first; i < last; ++i ) {
            push_edge( Perm[i], Perm[i+1], rand()%MAXO );
            --e;
        }
    }

    for( ; e > 0; --e ) {
        int k = rand() % komp;
        vector< int > &V = KompList[k];

        if( V.size() <= 1 ) continue;

        int a = rand() % V.size();
        int b = ( a + rand()%(V.size()-1) + 1 ) % V.size();

        if( graf[V[a]][V[b]] == true ) continue;
        push_edge( V[a], V[b], rand() % MAXO );
    }

    printf( "%d %d\n", n, ( int )E.size() );

    for( int i = 0; i < n; ++i )
        printf( "%d%c", Otpor[i], i+1 == n ? '\n' : ' ' );

    random_shuffle( E.begin(), E.end() );

    for( int i = 0; i < ( int )E.size(); ++i )
        printf( "%d %d %d\n", E[i].a+1, E[i].b+1, E[i].w );

    return (0-0);
}
