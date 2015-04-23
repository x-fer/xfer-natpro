#include <algorithm>
#include <cstdio> 
#include <stack>

using namespace std;

const int R = 1005, S = 2005, INF = 1e9;

int N, sol;
int grid[1010][2010], prev[1010][2010], dp[1010][2010];

int dr[] = {-1, -1, -1};
int ds[] = {-1, +0, +1};

char smjer[] = "654"; 

stack <int> stog;

inline bool check(int r, int s) {
    return r >= 0 && r < R && s >= 0 && s < S;
}

inline int find_col(int r) {
    for (int i = 0; i < S; ++i) {
        if (dp[r][i] == sol) return i;
    }
    return -1;
}

int main(void) {

    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        
        char s[10];
        scanf("%s", s);

        if (s[2] == 'm') {
            int x, t; scanf("%d%d", &x, &t); x += 1000;
            grid[t][x] = -INF;
        } else {
            int x, t, b; scanf("%d%d%d", &x, &t, &b); x += 1000;
            grid[t][x] = b;
        }

    }

    for (int i = 0; i < S; ++i) dp[0][i] = -INF;
    dp[0][1000] = 0;     

    for (int i = 1; i < R; ++i) {
        for (int j = 0; j < S; ++j) {
            dp[i][j] = -INF;
            for (int k = 0; k < 3; ++k) {
                int r = i + dr[k], s = j + ds[k];
                if (!check(r, s)) continue;
                if (dp[r][s] + grid[i][j] > dp[i][j]) {
                    dp[i][j] = dp[r][s] + grid[i][j];
                    prev[i][j] = (int) smjer[k] - '0';
                } 
            }
            sol = max(sol, dp[i][j]);
        }
    }

    printf("%d\n", sol);

    int r = 1, s;
    while ((s = find_col(r++)) == -1);
    --r;

    while (prev[r][s] != 0) {
        stog.push(prev[r][s]);
        if (prev[r][s] == 4){ --r; ++s; continue; }
        if (prev[r][s] == 5){ --r; continue; }
        if (prev[r][s] == 6){ --r; --s; continue; }
    }

    while (!stog.empty()) {
        printf("%d", stog.top());
        stog.pop();
    }
    printf("\n");

    return 0;

}
