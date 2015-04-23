#include <cstdio>

const int dr[4] = { -1, 0, 1, 0 };
const int ds[4] = { 0, 1, 0, -1 };

int R, S;
int r1, s1, r2, s2;
char mapa[100][101];
int dist[100][100];
int t[128];

int main( void ) {
    scanf( "%d%d", &R, &S );
    for( int r = 0; r < R; ++r ) {
        scanf( "%s", mapa[r] );
        for( int s = 0; s < S; ++s ) {
            if( mapa[r][s] == 'S' ) mapa[r1=r][s1=s] = '.';
            if( mapa[r][s] == 'C' ) mapa[r2=r][s2=s] = '.';
            dist[r][s] = 1000000000;
        }
    }
    scanf( "%d%d%d%d%d", &t['.'], &t['|'], &t['#'], &t['T'], &t['W'] );

    dist[r1][s1] = 0;

    bool changes = true;
    while( changes ) {
        changes = false;
        for( int r = 0; r < R; ++r )
            for( int s = 0; s < S; ++s )
                for( int d = 0; d < 4; ++d ) {
                    int rr = r + dr[d];
                    int ss = s + ds[d];
                    if( rr < 0 || rr >= R ) continue;
                    if( ss < 0 || ss >= S ) continue;
                    if( dist[rr][ss] > dist[r][s] + t[mapa[rr][ss]] ) {
                        dist[rr][ss] = dist[r][s] + t[mapa[rr][ss]];
                        changes = true;
                    }
                }
    }
    printf( "%d\n", dist[r2][s2] );

    return 0;
}
