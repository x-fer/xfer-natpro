#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int N, M;
struct point { int x, y; } A[50000];
struct rect { int x1, y1, x2, y2, ret; } B[50000];
struct event {
    int x, tip, id;
    event( int X, int TIP, int ID ) { x = X; tip = TIP; id = ID; }
};
bool operator < ( const event &A, const event &B ) {
    if( A.x != B.x ) return A.x < B.x;
    return A.tip < B.tip;
}
vector<event> E;

int loga[50000];

int main( void ) {
    scanf( "%d", &N );
    for( int i = 0; i < N; ++i ) {
        scanf( "%d%d", &A[i].x, &A[i].y );
        E.push_back( event( A[i].x, 2, i ) );
    }
    scanf( "%d", &M );
    for( int i = 0; i < M; ++i ) {
        scanf( "%d%d%d%d", &B[i].x1, &B[i].y1, &B[i].x2, &B[i].y2 ); --B[i].y1;
        E.push_back( event( B[i].x1, 1, i ) );
        E.push_back( event( B[i].x2, 3, i ) );
    }
    sort( E.begin(), E.end() ); 
    for( vector<event>::iterator it = E.begin(); it != E.end(); ++it ) {
        if( it->tip == 1 ) {
            for( int y = B[it->id].y2; y > 0; y -= y&-y ) B[it->id].ret -= loga[y];
            for( int y = B[it->id].y1; y > 0; y -= y&-y ) B[it->id].ret += loga[y];
        } 
        if( it->tip == 2 ) {
            for( int y = A[it->id].y; y < 50000; y += y&-y ) ++loga[y];
        }
        if( it->tip == 3 ) {
            for( int y = B[it->id].y2; y > 0; y -= y&-y ) B[it->id].ret += loga[y];
            for( int y = B[it->id].y1; y > 0; y -= y&-y ) B[it->id].ret -= loga[y];
        }
    }
    for( int i = 0; i < M; ++i ) printf( "%d\n", B[i].ret );
    return 0;
}
