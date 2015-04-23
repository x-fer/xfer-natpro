#include <cstdio>

using namespace std;

int m, n;

const double eps = 1e-8;

double fast_pow(double b, int e) {
    double ret = 1;
    while (e > 0) {
        if (e & 1) ret *= b;
        e >>= 1; b *= b;
    }
    return ret;
}

int main(void) {

    scanf("%d%d", &m, &n);

    double sol = 0;
    for (int i = 1; i <= m; ++i) {
        sol += (double) i * (fast_pow((double) i/m, n) - fast_pow((double) (i - 1)/m, n));
    }

    printf("%.8lf\n", sol);

    return 0;

}
