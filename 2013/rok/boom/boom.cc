#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1000010;

long long bombe[MAXN];

int main(int argc, char **argv) {
    int N, r;   scanf("%d%d", &N, &r);

    for (int i = 0; i < N; ++i) {
        scanf("%lld", bombe + i);
    }

    sort(bombe, bombe + N);

    long long range = bombe[0] + r;
    int sol = 1;

    for (int i = 1; i < N; ++i) {
        if (bombe[i] > range) {
            sol += 1;
        }
        range = bombe[i] + r;
    }

    printf("%d\n", sol);

    return 0;
}
