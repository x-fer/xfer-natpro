#include <iostream>

typedef long long llint;

using namespace std;

llint MOD;

llint pow( llint a, llint n ) {
    if( n == 0 ) return 1 % MOD;
    if( n % 2 ) return a * pow( a, n-1 ) % MOD;
    llint x = pow( a, n/2 );
    return x * x % MOD;
}

llint koliko( llint p, llint a, llint n ) {
    llint ret = n/a;
    if( a*p <= n ) ret += koliko( p, a*p, n );
    return ret;
}

char sito[60001];

int main( void ) {
    llint A, B, C;
    cin >> A >> B >> C;
    cin >> MOD;

    llint N = A+B+C;

    llint ret = 1;
    for( int i = 0; i <= N; ++i ) sito[i] = 0;

    for( llint i = 2; i <= N; ++i ) {
        if( sito[i] ) continue;
        for( llint j = i*i; j <= N; j += i )
            sito[j] = 1;

        llint p = koliko(i,i,N) - koliko(i,i,A) - koliko(i,i,B) - koliko(i,i,C);

        ret = ret * pow(i, p) % MOD;
    }

    cout << ret << endl;

    return 0;
}
