#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>

using namespace std;

const int MAXN = 1e6;
const int MAXK = 1e6;

int a[MAXN], k;
int b[MAXK];

void print() {
    for (int i = 0; i < k; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");
}

int get_next_median(int num, int to_insert) {
    int found = 0;
    for (int i = 0; i < k - 1; i++) {
        if (b[i] == num) {
            found = 1;
        }

        if (found) {
            b[i] = b[i + 1];
        }
    } 

    int pos = 0;
    for (int i = k - 2; i >= 0; i--) {
        if (b[i] < to_insert) {
            pos = i + 1;
            break;
        }
    }

    for (int i = k - 1; i > pos; i--) {
        b[i] = b[i-1];
    }

    b[pos] = to_insert;

//    print();

    return b[(k-1)/2];
}

int main() {
    int n;
    clock_t t1 = clock();
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < k; i++) {
        b[i] = a[i];
    }
//    print();

    sort(b, b + k);
    
    printf("%d\n", b[(k-1)/2]);

    for (int i = 1; i < n - k + 1; i++) {
        printf("%d\n", get_next_median(a[i-1], a[i + k - 1]));
    }
    clock_t t2 = clock();
    float sec = ((float)t2 - (float)t1)/CLOCKS_PER_SEC;
    printf("%f", sec);
    return 0;
}
