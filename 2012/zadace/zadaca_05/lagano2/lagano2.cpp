#include <iostream>

using namespace std;

typedef long long llint;

const llint MOD = 31337;

void mult( llint C[3][3], llint A[3][3], llint B[3][3] ) {
    static llint tmp[3][3];

    for( int i = 0; i < 3; ++i )
        for( int j = 0; j < 3; ++j ) {
            tmp[i][j] = 0;
            for( int k = 0; k < 3; ++k )
                tmp[i][j] += A[i][k] * B[k][j];
            tmp[i][j] %= MOD;
        }

    for( int i = 0; i < 3; ++i )
        for( int j = 0; j < 3; ++j )
            C[i][j] = tmp[i][j];
}

int main( void ) {
    llint A, B, C, D, E, K;
    cin >> A >> B >> C >> D >> E >> K;
    A %= MOD;
    B %= MOD;
    C %= MOD;
    D %= MOD;
    E %= MOD;

    llint M[3][3] = {
        {0, 1, 0},
        {C, D, E},
        {0, 0, 1}
    };
    llint ret[3][3] = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };

    for( llint x = K-1; x; x >>= 1 ) {
        if( x & 1 ) mult( ret, ret, M );
        mult( M, M, M );
    }

    cout << (ret[0][0]*A + ret[0][1]*B + ret[0][2]) % MOD << endl;

    return 0;
}
