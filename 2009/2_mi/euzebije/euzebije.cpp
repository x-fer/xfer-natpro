#include <cstring>
#include <cstdio>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

const int INF = 1000000000;
typedef pair<int, int> par;

int n;
char tabla[30][31];

int graf[21][21];
vector<par> tocke;
par euzebije;
int dist[30][30];

const int dx[4] = { -1, 0, 0, 1 };
const int dy[4] = { 0, -1, 1, 0 };

void napravi_veze( int sors ) {
        queue<par> Q;
        Q.push( tocke[sors] );
        memset( dist, -1, sizeof dist );

        dist[ tocke[sors].first ][ tocke[sors].second ] = 0;

        for( ; !Q.empty(); Q.pop() ) {
                int x = Q.front().first;
                int y = Q.front().second;


                for( int i = 0; i < 4; ++i ) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if( nx < 0 || nx >= n ) continue;
                    if( ny < 0 || ny >= n ) continue;
                    if( dist[nx][ny] != -1 ) continue;
                    if( tabla[nx][ny] == '#' ) continue;

                    dist[nx][ny] = dist[x][y] + 1;
                    Q.push( par(nx,ny) );
                }
        }

        for( int i = 0; i < tocke.size(); ++i )
            if( dist[ tocke[i].first ][ tocke[i].second ]  != -1 )
                graf[sors][i] = dist[ tocke[i].first ][ tocke[i].second ];
}

int memo[19][1<<18];

int rec( int pos, int mask ) {
        if( mask == (1<<(tocke.size()-1))-1 ) return graf[pos][tocke.size()-1];

        int &ret = memo[pos][mask];
        if( ret >= 0 ) return ret;

        ret = INF;
        for( int i = 0; i + 1 < tocke.size(); ++i ) {
            if( i == pos ) continue;
            if( (mask>>i)&1 ) continue;
            if( graf[pos][i] == -1 ) continue;

            ret = min( ret, graf[ pos ][ i ] + rec( i, mask | (1<<i) ) );
        }

        return ret;
}

int main( void ) {

     scanf( "%d", &n );

     for( int i = 0; i < n; ++i ) scanf( "%s", tabla[i] );

     for( int i = 0; i < n; ++i )
        for( int j = 0; j < n; ++j ) {
            if( tabla[i][j] == 'B' ) tocke.push_back( par(i,j) );
            if( tabla[i][j] == 'E' ) euzebije = par(i,j);
        }

     tocke.push_back( euzebije );

     memset( graf, -1, sizeof graf );
     for( int i = 0; i < (int)tocke.size(); ++i ) napravi_veze( i );

     memset( memo, -1, sizeof memo );
     int sol = rec( tocke.size()-1, 0 );
     if( sol >= INF )   puts( "-1" );
     else               printf( "%d\n", sol );

 return 0;
}
