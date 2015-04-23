#include <cstdio>

const int MOD = 31337;

int main( void ) {
    int A, B, C, D, E, K;
    scanf( "%d%d%d%d%d%d", &A, &B, &C, &D, &E, &K );
    A %= MOD;
    B %= MOD;
    if( K == 1 ) printf( "%d\n", A );
    else {
        for( int i = 0; i < K-2; ++i ) {
            int novo = ((long long)C*A + (long long)D*B + E) % MOD;
            A = B;
            B = novo;
        }
        printf( "%d\n", B );
    }
    return 0;
}
