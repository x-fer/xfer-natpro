#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <cmath>

using namespace std;

const int MAXN = 800010;
const int MAXR = 1e6;

const int GG = 1e9, DG = -1e9;

int main(int argc, char **argv) {
    int N, r, xi;

    srand((unsigned)time(NULL));

    sscanf(argv[1], "%d", &N);

    N = MAXN / exp(10 - N);
    r = rand() % MAXR;

    printf("%d %d\n", N, r);

    for (int i = 0; i < N; ++i) {
        if (i) printf(" ");

        xi = (rand() % (GG - DG)) - DG;
        printf("%d", xi);
    }

    printf("\n");

    return 0;
}
