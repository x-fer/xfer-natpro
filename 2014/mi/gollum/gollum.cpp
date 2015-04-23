#include <cstdio>
using namespace std;

typedef long long llint;

llint pow(int b, int n) {
  llint ret = 1;
  for (int i = 0; i < n; i++)
    ret *= b;
  return ret;
}

int main (){
    int n;
    scanf ("%d",&n);

    if ( n == 1 ){
       printf ("1\n");
       return 0;
    }

    if ( n%3 == 1 ) printf ("%lld\n", pow ( 3 , n / 3  - 1 ) * 4 );
    else if ( n%3 == 2 ) printf ("%lld\n", pow( 3 , n / 3  ) * 2 );
    else printf ("%lld\n", pow( 3 , n / 3  ) );

    return 0;
}
