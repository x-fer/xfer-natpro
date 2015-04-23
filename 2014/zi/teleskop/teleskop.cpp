#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

char s[17][251];

int N;
int len[17], dlen[17][17], memo[17][1 << 16];

int merged_length(int s1, int s2) {
    for (int i = 1; i <= len[s1]; ++i) {
        if (i > len[s2]) break;
        bool check = true;
        for (int j = i; j > 0; --j) {
            check &= s[s1][len[s1] - j] == s[s2][i - j];
        }
        if (check) return len[s2] - i;
    } 
    return 0;
}

void precompute() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j) continue;
            dlen[i][j] = merged_length(i, j);
        }
    }
}

int solve(int last, int mask) {
   
    int ret = 0;
    if (memo[last][mask] != -1) return memo[last][mask];

    for (int i = 0; i < N; ++i) {
        if ((mask & (1 << i)) != 0) continue;
        if (dlen[last][i] > 0) {
            ret = max(ret, dlen[last][i] + solve(i, mask | (1 << i)));
        }
    }

    return memo[last][mask] = ret;

}

int main(void) {

    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%s", s[i]);
        len[i] = strlen(s[i]);
        dlen[N][i] = len[i];
    }

    memset(memo, -1, sizeof memo);
    precompute();

    printf("%d\n", solve(N, 0));

    return 0;

}   
