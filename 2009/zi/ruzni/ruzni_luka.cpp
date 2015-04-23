#include <cstdio>
#include <cassert>
#include <set>

using namespace std;

int i, n, p[5] = { 2, 3, 5, 7, 11 };

int main( void ) {
    scanf( "%d", &n );

    set<long long> pq;

    long long last = -1;
    for( pq.insert( 1 ); n--; pq.erase( pq.begin() ) ) {
        assert( last <= *pq.begin() );
        last = *pq.begin();
        for( i = 0; i < 5; ++i )
            pq.insert( *pq.begin() * p[i] );
    }

    printf( "%lld\n", *pq.begin() );

    return 0;
}
