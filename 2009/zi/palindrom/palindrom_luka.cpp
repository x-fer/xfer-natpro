#include <cstdio>

int N;
char S[1000001];
int P = 123456789;
int invP = 102505021;

int main( void ) {
    scanf( "%d", &N );
    scanf( "%s", S );

    int L = 0, R = N-1;
    int Len = 0, PnaLen = 1;
    int hashL = 0, hashR = 0;
    while( L <= R ) {
        hashL += S[L++] * PnaLen;
        hashR += S[R--] * PnaLen;
        ++Len;
        PnaLen *= P;
    }

    while( hashL != hashR )
        if( L-R == 2 ) {
            hashL = (hashL - S[L-Len--]) * invP;
            hashR = hashR - S[++R] * (PnaLen *= invP);
        } else {
            hashL = (hashL + S[L] * PnaLen - S[L-Len]) * invP; ++L;
        }

    printf( "%s", S );
    for( L -= Len+1; L >= 0; --L ) printf( "%c", S[L] );
    printf( "\n" );

    return 0;
}
