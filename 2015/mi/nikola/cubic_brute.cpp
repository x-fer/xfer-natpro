#include <cstdio>
#include <cmath>
#include <ctime>

using namespace std;

const int MAXN = 1e6 + 2;
const int MAXK = 1e6 + 2;

int a[MAXN], k;

int check_if_median(int starting, int offset) {
    int candidate = a[starting + offset];
    
    int less = 0;
    int great = 0;
    int same = 0;
    for (int i = starting; i < starting + k; i++) {
        if (a[i] < candidate) {
            less++;
        } else if (a[i] == candidate) {
            same++;
        } else {
            great++;
        }
    }
    return abs(great - less) < same ? 1 : 0;
}

int main() {
    int n;
    clock_t t1 = clock();
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n - k + 1; i++) {
        for (int j = 0; j < k; j++) {
            if (check_if_median(i, j)) {
                printf("%d\n", a[i+j]);
                break;
            }
        }
    }
    clock_t t2 = clock();
    float sec = ((float)t2 - (float)t1)/CLOCKS_PER_SEC;
    printf("%f", sec);
    return 0;
}
