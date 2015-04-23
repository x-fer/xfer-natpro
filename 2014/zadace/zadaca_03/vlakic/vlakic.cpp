#include <cstdio>

int gcd( int a, int b ) { return b == 0 ? a : gcd( b, a%b ); }

int main( void ) {
    int A, B, C;
    scanf( "%d%d%d", &A, &B, &C );

    int gore[A+B+C];
    int dole[A+B+C];
    for( int i = 1; i <= A+B+C; ++i ) gore[i-1] = i;
    for( int i = 1; i <= A; ++i ) dole[i-1] = i;
    for( int i = 1; i <= B; ++i ) dole[i-1+A] = i;
    for( int i = 1; i <= C; ++i ) dole[i-1+A+B] = i;

    int ret = 1;
    for( int i = 0; i < A+B+C; ++i ) {
        for( int j = 0; j < A+B+C; ++j ) {
            int g = gcd( gore[i], dole[j] );
            gore[i] /= g;
            dole[j] /= g;
        }
        ret = (ret * gore[i]) % (24*60);
    }
    ret = (ret + 12*60) % (24*60);
    int hh = ret / 60;
    int mm = ret % 60;
    printf( "%02d:%02d\n", hh, mm );

    return 0;
}
