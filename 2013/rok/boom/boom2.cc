#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 1000010;

long long bombe[MAXN];
int dad[MAXN], cnt[MAXN];

int nadji(int i) {
    while(i != dad[i] ) {
        dad[i] = dad[dad[i]];
        i = dad[i];
    }
    return i;
}

int spoji(int i, int j) {
    i = nadji(i);
    j = nadji(j);

    if (i == j) return 0;

    if (cnt[i] < cnt[j]) {
        dad[i] = j;
        cnt[j] += cnt[i];
    } else {
        dad[j] = i;
        cnt[i] += cnt[j];
    }

    return 1;
}

inline long long abs(long long x) {
    if (x < 0) return -x;
    else return x;
}

int main(int argc, char **argv) {
    int N, r;   scanf("%d%d", &N, &r);

    int sol = N;

    for (int i = 0; i < N; ++i) {
        scanf("%lld", bombe + i);

        dad[i] = i; cnt[i] = 1;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = i+1; j < N; ++j) {
            if (abs(bombe[i] - bombe[j]) <= r) {
                sol -= spoji(i, j);
            }
        }
    }

    printf("%d\n", sol);

    return 0;
}
