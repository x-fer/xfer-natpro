#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 505;

int a[MAXN];
bool g[MAXN];
int n, k;

void make(int lo) {
  memset(g, 0, sizeof(g));
  int i = n-1;
  for (int j = 0; j < k; ++j) {
    int sum = 0;
    while (i >= 0 && sum+a[i] <= lo && i >= k-j-1) {
      sum += a[i];
      --i;
    }
    g[i] = 1;
  }
}

bool can(int lo) {
  int i = n-1;
  for (int j = 0; j < k; ++j) {
    int sum = 0;
    while (i >= 0 && sum+a[i] <= lo && i >= k-j-1) {
      sum += a[i];
      --i;
    }
    if (i < 0) return 1;
    if (sum == 0) return 0;
  }
  return 0;
}

int main(void) {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  
  int lo = 0, hi = 2000000000;     
  while (lo < hi) {
    int mid = (lo+hi)/2;
    if(can(mid)) hi = mid; else 
      lo = mid+1;
  }
  
  make(lo);
  for(int i = 0; i < n; ++i) {
    if (i) printf(" ");
    printf("%d", a[i]);
    if (g[i]) printf(" /");
  }
  printf( "\n" );  
  return 0;
}
