#include <iostream>
#include <cstdio>

#define IN "novcici.in.x"
#define OUT "novcici.out.x"

using namespace std;

const int MAX=1000000+1;
const int MAXN=50+1;

int k, l, n, game[MAXN], top;
bool a[MAX];

inline int max(int x, int y){
    return x>y?x:y;
}

int main(){
    freopen(IN, "r", stdin);
    freopen(OUT, "w", stdout);
    scanf("%d %d %d",&k,&l,&n);
    for (int i=0; i<n; i++){
        scanf("%d",&game[i]);
        top=max(top, game[i]);
    }

    a[k]=a[l]=a[1]=true;
    for (int i=1; i<=top; i++)
        if (!a[i]){
            a[i+k]=a[i+l]=a[i+1]=true;
        }

    for (int i=0; i<n; i++)
        printf("%c",a[game[i]]?'A':'B');
    printf("\n");
    return 0;
}
