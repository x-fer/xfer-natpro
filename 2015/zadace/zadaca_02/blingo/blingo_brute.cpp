#include <cstdio>
#include <ctime>
#include <vector>

using namespace std;

vector<int> V;

int find(int a, int b, int k) {
    for (int i = a; i <= b; i++) {
        int much = 0;
        int less = 0;
        for (vector<int>::iterator it = V.begin(); it != V.end(); it++) {
            if ((*it) == i) much++;
            if ((*it) < i && ((*it) >= a && (*it) <= b)) less++;
        }
        if (less < k && k <= (much+less)) {
            return i;
        }
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
            V.push_back(b);
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
