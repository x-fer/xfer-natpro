#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>

using namespace std;

typedef pair<int,int> par;

int main( void ) {
    int n, m, limit;
    set<par> seen;
    scanf( "%d%d%d", &n, &m, &limit );
    printf( "%d\n", n );
    for( int i = 0; i < n; ++i ) {
        int x = rand()%limit + 1;
        int y = rand()%limit + 1;
        if( seen.count( par(x,y) ) ) { --i; continue; }
        seen.insert( par(x,y) );
        printf( "%d %d\n", x, y );
    }
    printf( "%d\n", m );
    for( int i = 0; i < m; ++i ) {
        int x1 = rand()%limit + 1;
        int y1 = rand()%limit + 1;
        int x2 = rand()%limit + 1;
        int y2 = rand()%limit + 1;
        if( x1 >= x2 || y1 >= y2 ) { --i; continue; }
        printf( "%d %d %d %d\n", x1, y1, x2, y2 );
    }
    return 0;
}
