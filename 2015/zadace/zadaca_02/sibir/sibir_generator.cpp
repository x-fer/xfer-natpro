#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>

#define IN "sibir.in.11"

using namespace std;

int N=1000000, K=N;
const int MAX=1000000;
const int MAXM=1000000000;
const long long MAXA=1000000000000000000;

long long tmp[MAX];
void generiraj(int x) {
    int y=rand()%(x/2)+x/2;
    if (K)
        y=K;

    printf("%d\n%d\n", x, y);
    for (int i=1; i<=y; i++) {
        if (i%3 and i<y) {
            int type=rand()%2;
            if (!type and i<5)
                type=1;

            if (type){
                int t1=rand()%x, t2=rand()%MAXM+1;
                while(t2+tmp[t1]>MAXA)
                    t1=rand()%x;
                tmp[t1]+=t2;
                printf("posadka %d %d\n", t1, t2);
            }
            else {
                int t1=rand()%x, t2=rand()%MAXM+1;
                tmp[t1]-=t2;
                if (tmp[t1]<0)
                    tmp[t1]=0;
                printf("razgruzka %d %d\n", t1, t2);
            }
            continue;
        }
        int t2=rand()%x, t1=t2;
        while(t1==t2 and t2)
            t1=rand()%t2;
        printf("kontora %d %d\n", t1, t2);
    }
}

int main() {
    srand(time(0));
    freopen(IN, "w", stdout);
    generiraj(N);
    return 0;
}
