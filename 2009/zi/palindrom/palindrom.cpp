#include <cstdio>
#define MAX 1000001
#define B 65599

int N;
char S[MAX];
char R[MAX];
unsigned int potB[MAX];

int main()
{
    scanf("%d", &N);
    scanf("%s", S);

    for (int i = 0; i < N; ++i)
    {
        R[i] = S[N-i-1];
    }
    R[N] = '\0';

    unsigned int hashS = 0, hashR = 0;

    for (int i = 0; i < N; ++i)
    {
        hashS = hashS*B + S[i];
        hashR = hashR*B + R[i];

        if (i) potB[i] = potB[i-1]*B;
        else potB[0] = 1;
    }

    for (int i = 0; i <= N; ++i)
    {
        if (hashS == hashR)
        {
            bool ok = true;
            for (int j = i; j < N && ok; ++j)
            {
                if (R[j-i] != S[j]) ok = false;
            }

            if (ok)
            {
                printf("%s%s\n", S, &R[N-i]);
                break;
            }
        }

        hashS = (hashS - S[i]*potB[N-1])*B;
        hashR = hashR - R[N-i-1]*potB[i];
    }

    return 0;
}
