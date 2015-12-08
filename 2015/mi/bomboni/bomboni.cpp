#include <cstdio>

using namespace std;
const int mod=1e9+7;
int n, k;

int pot(int x,int y){
  if (!y){
    return 1;
  }
  if (y==1){
    return x;
  }
  int rek, ost;
  rek=pot(x,y/2);
  ost=pot(x,y%2);
  return ((((long long)rek*rek)%mod)*(long long)ost)%mod;
}

int choose(int x,int y){
  if (y>x/2){
    y=x-y;
  }
  int num=1;
  int den=1;
  for (int i=1;i<=y;i++){
    num=((long long)num*(x-i+1))%mod;
    den=((long long)den*i)%mod;
  }
  return ((long long)num*pot(den,mod-2))%mod;
}

int main (void){
  scanf("%d%d", &n, &k);
  printf("%d\n", choose(n,k));
  return 0;
}
