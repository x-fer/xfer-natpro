#include <cstdio>

const int MOD = 24*60;

int pow( int a, int n ) {
    if( n == 0 ) return 1;
    if( n % 2 ) return a * pow( a, n-1 ) % MOD;
    int x = pow( a, n/2 );
    return x * x % MOD;
}

int koliko( int p, int a, int n ) {
    int ret = n/a;
    if( a*p <= n ) ret += koliko( p, a*p, n );
    return ret;
}

int main( void ) {
    int A, B, C;
    scanf( "%d%d%d", &A, &B, &C );

    int N = A+B+C;

    int ret = 1;
    char sito[N+1];
    for( int i = 0; i <= N; ++i ) sito[i] = 0;

    for( int i = 2; i <= N; ++i ) {
        if( sito[i] ) continue;
        for( int j = i*i; j <= N; j += i )
            sito[j] = 1;

        int p = koliko(i,i,N) - koliko(i,i,A) - koliko(i,i,B) - koliko(i,i,C);

        ret = ret * pow(i, p) % MOD;
    }

    ret = (ret + 12*60) % (24*60);
    int hh = ret / 60;
    int mm = ret % 60;
    printf( "%02d:%02d\n", hh, mm );

    return 0;
}
