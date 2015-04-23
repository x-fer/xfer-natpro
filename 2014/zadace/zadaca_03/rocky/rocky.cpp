#include <cstdio>
using namespace std;

int a[1000042];

int main (){
    int n;
    scanf ("%d",&n);
    a[0] = 1;
    for (int i=1;i<=n;++i){
        for (int j=i-3; j<i; ++j){
            if ( j>= 0 ) a[i] += a[j];
        }
        while ( a[i] >= 1000007 ) a[i] -= 1000007;
    }
    printf ("%d\n",a[n]);
    return 0;
}
