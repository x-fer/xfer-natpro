#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1000010;
const int P = 137, MOD = 10000007;

char S[MAXN], R[MAXN];
int pot[MAXN];

int main(int argc, char **argv) {
    scanf("%s", S);

    int N = strlen(S);
    unsigned int hashR = 0, hashS = 0;

    pot[0] = 1;
    for (int i = 0; i < N; ++i) {
        R[i] = S[N - i - 1];

        if (i) pot[i] = (pot[i - 1] * P);

        hashS = hashS * P + S[i];
        hashR = hashR * P + R[i];
    }

    for (int i = 0; i <= N; ++i) {
        // printf("%u %u\t%s%s\n", hashR, hashS, S, &R[N - i]);

        if (hashR == hashS) {
            /* dodatna provjera jer "ne vjerujemo" hashu */
            bool is_palindrome = true;
            for (int j = i; j < N; ++j) {
                if (S[j] != R[j - i]) is_palindrome = false;
            }

            if (is_palindrome) {
                printf("%s%s\n", S, &R[N - i]);
                break;
            }
        }

        /* makni prvo slovo iz hashS ali zadrzi stupanj N */
        hashS = (hashS - S[i] * pot[N - 1] ) * P;

        /* makni zadnje slovo iz hashR*/
        hashR = hashR - R[N - i - 1] * pot[i];
    }

    return 0;
}
