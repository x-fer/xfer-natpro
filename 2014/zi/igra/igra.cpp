#include <cstdio>

using namespace std;

int N, K;

double fastpow(double b, int e) {
    double ret = 1; 
    while (e > 0) {
        if (e & 1) ret *= b;
        e >>= 1; b *= b;
    }
    return ret;
}

int main(void) {

    scanf("%d%d", &N, &K);
    double p = (double) 1 / K;
    
    for (int i = 1; i <= N; ++i) {
        printf("%.6lf\n", (p * fastpow(1 - p, i - 1)) / (1 - fastpow(1 - p, N)));
    }

    return 0;

}
