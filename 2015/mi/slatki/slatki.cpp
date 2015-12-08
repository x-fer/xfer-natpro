#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef long long llint;
typedef pair<int, int> pii;

const int inf = 1000000000;

int R, S;
int memo[255][255];

int rek(int r, int s) {
    
    int ret = inf;

    if (r == s) return 1;
    if (memo[r][s] != -1) return memo[r][s];

    for (int i = 1; i < r; ++i) 
        ret = min(ret, rek(i, s) + rek(r - i, s));

    for (int j = 1; j < s; ++j)
        ret = min(ret, rek(r, j) + rek(r, s - j));

    return memo[r][s] = ret;

}

int main(void) {

    memset(memo, -1, sizeof memo);

    scanf("%d%d", &R, &S);
    printf("%d\n", rek(R, S) - 1);

    return 0;

}

