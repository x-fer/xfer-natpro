#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

struct event {
    int x;
    int start;
    int tip;
    int id;
    event( int x, int start, int tip, int id ) {
        this->x = x;
        this->start = start;
        this->tip = tip;
        this->id = id;
    }
};
bool operator < ( const event &A, const event &B ) {
    if( A.x != B.x ) return A.x < B.x;
    if( A.start != B.start ) return A.start < B.start;
    if( A.tip != B.tip ) return A.tip < B.tip;
    return A.id < B.id;
}



int main( void ) {
    int n;
    scanf( "%d", &n );
    vector<event> E;
    for( int i = 1; i <= n; ++i ) {
        char tip;
        scanf( " %c", &tip );
        if( tip == 't' ) {
            int x1, y1, x2, y2, x3, y3;
            scanf( "%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3 );
            E.push_back( event( min( x1, min( x2, x3 ) ), 1, 1, i ) );
            E.push_back( event( max( x1, max( x2, x3 ) ), 0, 1, i ) );
        } else if( tip == 'p' ) {
            int x1, y1, x2, y2;
            scanf( "%d%d%d%d", &x1, &y1, &x2, &y2 );
            E.push_back( event( min( x1, x2 ), 1, 2, i ) );
            E.push_back( event( max( x1, x2 ), 0, 2, i ) );
        } else {
            int x, y, r;
            scanf( "%d%d%d", &x, &y, &r );
            E.push_back( event( x - r, 1, 3, i ) );
            E.push_back( event( x + r, 0, 3, i ) );
        }        
    }
    sort( E.begin(), E.end() ); 

    for( vector<event>::iterator it = E.begin(); it != E.end(); ++it ) {
        if( it->start ) printf( "Start %d\n", it->id );
        else printf( "Stop %d\n", it->id );
    }
    
    return 0;
}
