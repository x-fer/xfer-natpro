#include <cstdio>
#include <ctime>

using namespace std;

const int MAXN = 1e6 + 2;
const int MAXK = 1e6 + 2;
const int MAX_NUM = 1e6 + 2;

int n, k;
int niz[MAXN];

struct fenwick {
    int A[MAX_NUM];

    int get(int index) {
        int ret = 0;
        for (int i = index; i > 0; i -= i&-i) {
            ret += A[i];
        }
        return ret;
    }

    void add(int index, int val) {
        for (int i = index; i < MAX_NUM; i += i&-i) {
            A[i] += val;
        }
    }

    int median(int size) {
        int lo = 1;
        int hi = MAX_NUM - 1;

        while (lo < hi) {
            int mid = (lo+hi)/2;
            int tot = get(mid);

            if (tot >= (size+1)/2) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
} F;

int main() {
    clock_t t1 = clock();
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &niz[i]);
    }
    for (int i = 0; i < k; i++) {
        F.add(niz[i], 1);
    }
    
    printf("%d\n", F.median(k));
    for (int i = 1; i < n - k + 1; i++) {
        F.add(niz[i - 1], -1);
        F.add(niz[i + k - 1], 1);
        printf("%d\n", F.median(k));
    }

    clock_t t2 = clock();
    float sec = ((float)t2 - (float)t1)/CLOCKS_PER_SEC;
    printf("%f", sec);
    return 0;
}
