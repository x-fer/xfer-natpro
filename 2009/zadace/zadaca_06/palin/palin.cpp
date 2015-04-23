/*
  Sluzbeno rjesenje zadatka PALIN u slozenosti O( N^2 ) pomocu dinamickog programiranja.
  Memorijsko zauzece: 9 do 10 MB
  Autor: Goran Zuzic
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

const int MAXN = 1510;

char A[ MAXN ];
int dp[ MAXN ][ MAXN ];

int main( void )
{
    int n; scanf( "%d %s", &n, A );
    int maks = 1;
    
    for( int i = 0; i < n; ++i ) {
        dp[i][i] = true;
        if( i+1 < n ) if( ( dp[i][i+1] = (A[i]==A[i+1]) ) ) maks = 2;
    }

    for( int len = 3; len <= n; ++len )
        for( int start = 0; start+len <= n; ++start ) {
            int end = start + len - 1;
            if( ( dp[start][end] = dp[start+1][end-1] && ( A[start] == A[end] ) ) )
                maks = len;
        }

    printf( "%d\n", maks );
    return (0-0);
}
