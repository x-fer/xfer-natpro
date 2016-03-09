#include <cstdio>

using namespace std;

const int MAXN = 5*1e6 + 5;
const int MAXQ = 5*1e5 + 5;

struct fenwick {
    int L[MAXN];

    void add(int i, int val) {
        for (; i < MAXN; i += i&-i)
            L[i] += val;
    } 

    int query(int i) {
        int ret = 0;
        for (; i > 0; i -= i&-i)
            ret += L[i];
        return ret;
    }
} F;

int get_lower(int x, int a) {
    int lessa = F.query(a - 1);
    int lessx = F.query(x);
    return lessx - lessa;    
}

int binary(int lo, int hi, int k) {
    int a = lo;
    int b = hi;
    while (lo < hi) {
        int mid = (lo + hi)/2;
        int curr = get_lower(mid, a);
        if (curr >= k) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    int much_x = get_lower(lo, a);
    int lower = get_lower(lo - 1, a);
    return (lower < k && k <= much_x) ? lo : -1;
}

int main () {
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; ++i) {
        char c;
        scanf(" %c", &c);
        
        if (c == 'u') {
            int b;
            scanf("%d", &b);
            F.add(b, 1);
        } else if (c == 'n') {
            int a, b, k;
            scanf("%d%d%d", &a, &b, &k);
            int result = binary(a, b, k);
            if (result == -1) {
                printf("NEMA\n");
            } else {
                printf("%d\n", result);
            }
        } else {
            printf("NEPOZNAT UNOS");
            return 1;
        }
    }
    return 0;
}
