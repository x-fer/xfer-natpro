# include <cstdio>
# include <string>
# include <iostream>

using namespace std;

const int MAXN = 1010;
const int P = 10007;

int N, M;
char matrix[MAXN][MAXN];

int hash_horizontal[MAXN][MAXN], hash_vertical[MAXN][MAXN];
int P_x[MAXN];

void find_all_hashes() {
    P_x[0] = 1;
    for (int i = 1; i < MAXN; ++i)
        P_x[i] = P_x[i - 1] * P;

    for (int i = 0; i < N; ++i)
        for (int j = 0, last_hash = 0; j < M; last_hash = hash_horizontal[i][j], ++j)
            hash_horizontal[i][j] = last_hash * P + matrix[i][j];

    for (int j = 0; j < M; ++j)
        for (int i = 0, last_hash = 0; i < N; last_hash = hash_vertical[i][j], ++i)
            hash_vertical[i][j] = last_hash * P + matrix[i][j];
}

int get_horizontal_hash(int i, int j1, int j2) {
    return hash_horizontal[i][j2] - (j1 == 0 ? 0 : hash_horizontal[i][j1 - 1] * P_x[j2 - j1 + 1]);
}

int get_vertical_hash(int j, int i1, int i2) {
    return hash_vertical[i2][j] - (i1 == 0 ? 0 : hash_vertical[i1 - 1][j] * P_x[i2 - i1 + 1]);
}

int main(void) {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; ++i)
        scanf("%s", matrix[i]);

    find_all_hashes();

    int best = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j) {
            for (int k = best + 1; i + k < N && i + k < M && get_horizontal_hash(i, j, j + k) == get_vertical_hash(j, i, i + k); ++k)
                if (get_horizontal_hash(i + k, j, j + k) == get_vertical_hash(j + k, i, i + k)) best = k;
        }

    printf("%d\n", 2 * best);
    return 0;
}
