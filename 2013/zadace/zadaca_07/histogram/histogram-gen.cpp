#include <cstdio>
#include <cstring>
#include <ctime>
#include <cstdlib>

#define TEST 50
#define IN "histogram.in.x"
#define MAXN 15
#define MAXH 100

bool vis[101];

int main(){
    srand(time(0));
    freopen(IN, "w", stdout);

    for (int i=0; i<TEST; i++){
        memset(vis, 0, sizeof vis);
        int n=rand()%(MAXN-1)+2;
        printf("%d\n", n);
        while(n--){
            int num=0;
            do num=rand()%MAXH+1;
                while(vis[num]);
            vis[num]=true;
            printf("%d", num);
            if (n)
                printf(" ");
            else
                printf("\n");
        }
    }
    printf("0\n");
	return 0;
}
