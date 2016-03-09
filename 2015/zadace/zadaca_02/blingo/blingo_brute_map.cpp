#include <cstdio>
#include <map>

using namespace std;

map<int, int> M;

int find(int a, int b, int k) {
    int less = 0;
    for (int i = a; i <= b; i++) {
        int much = M[i];
        if (less < k && k <= (much+less)) {
            return i;
        }
        less += much;
    }
    return -1;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        char c;
        scanf(" %c", &c);
        if (c == 'u') {
            int b;
            scanf("%d", &b);
            int kol = M[b];
            M[b] = (kol + 1);
        } else if (c == 'n') {
            int a, b, k;
            scanf("%d%d%d", &a, &b, &k);
            int result = find(a, b, k);
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
