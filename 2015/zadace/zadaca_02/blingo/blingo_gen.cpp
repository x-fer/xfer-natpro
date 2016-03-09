#include <ctime>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 5*1e6;
const int MAXQ = 1e5;

int main (int argc, char** argv) {
    if (argc < 2) {
      srand(15);
    }
    else {
      srand(*(argv[1]));
    }
    int t = rand()%MAXQ;
    int ubacivanja = 1;
    printf("%d\n", t);
 
    for (int i = 0; i < t; i++) {
        
        int version = rand()%2;
        
        if (version) {
            ubacivanja++;
            printf("u ");
            int b = rand()%MAXN;
            printf("%d\n", b + 1);
        } else {
            printf("n ");
            int lo = rand()%MAXN;
            int hi = rand()%MAXN;
            if (hi < lo) swap(lo, hi);
            int diff = hi - lo + 1;
            if (diff > 1000) {
                diff/=1000;
            }

            int k = rand()%diff;
            printf("%d %d %d\n", lo + 1, hi + 1, k + 1);
        }
    }
    return 0;
}
