/*
    Filip Pavetic
    3. domaca zadaca
    Osveta

	Koristenjem interval stabla moguce je sve operacije izvrsavati u O(lg n).
*/

#include <cassert>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXBROJ = 1000000;

struct tournament { // tournamet = interval = segment stablo

    vector<int> suma; // cuva sumu za svaki cvor
    int offset;

    void init( int n ) {
        for( offset = 1; offset < n; offset *= 2 );
        suma = vector<int> ( 2*offset, 0 );
    }

    void add( int node, int lo, int hi, int a, int b, int val ) {

        if( b < lo || a > hi ) return;
        if( lo == hi ) { // list
            suma[node] += val;
            return;
        }

        add( node*2, lo, (lo+hi)/2, a, b, val );
        add( node*2+1, (lo+hi)/2+1, hi, a, b, val );

        suma[ node ] = suma[ node*2 ] + suma[ node*2+1 ];
    }

    void add( int i, int val ) {
        add( 1, 0, offset-1, i, i, val );
    }

    int koliko( int node, int lo, int hi, int a, int b ) {
        if( b < lo || a > hi ) return 0;
        if( a <= lo && hi <= b ) return suma[node];

        return koliko( node*2, lo, (lo+hi)/2, a, b ) +
               koliko( node*2+1, (lo+hi)/2+1, hi, a, b );
    }

    int koliko( int a ) {
        return koliko( 1, 0, offset-1, 0, a );
    }

    int kti( int node, int lo, int hi, int k ) {
        assert( suma[node] >= k );

        if( lo == hi ) { // list
            return lo;
        }

        int left = 2*node;
        if( suma[left] >= k )
            return kti( node*2, lo, (lo+hi)/2, k );

        k -= suma[left];
        return kti( node*2+1, (lo+hi)/2+1, hi, k );
    }

    int kti( int k ) {
        return kti( 1, 0, offset-1, k );
    }

} T;

int n, m, p;

int main( void ) {

    scanf( "%d%d%d", &n, &m, &p );
    T.init( MAXBROJ );

    for( int i = 0; i < n; ++i ) {
        int a; scanf( "%d", &a );
        assert( 0 <= a < MAXBROJ );
        T.add( a, 1 );
    }

    int koliko_m = 0, koliko_p = 0;
    for( int i = 0; i < m+p; ++i ) {

        char komanda[16];
        int param;
        scanf( "%s%d", komanda, &param );

        if( *komanda == 'D' ) {
            ++koliko_p;

            // 0 <= param < MAXBROJ
            assert( 0 <= param && param < MAXBROJ );
            T.add( param, 1 );
        }
        if( *komanda == 'B' ) {
            ++koliko_p;

            // 1 <= param <= ukupan broj brojeva u memoriji
            assert( 1 <= param && param <= T.koliko( MAXBROJ ) );
            int kti = T.kti( param );
            T.add( kti, -1 );
        }
        if( *komanda == 'K' ) { // 0 <= param < MAXBROJ
            ++koliko_m;
//            assert( 0 <= param && param < MAXBROJ );
            printf( "%d\n", T.koliko( param ) );
        }
    }

    assert( koliko_m == m );
    assert( koliko_p == p );

return 0;
}
