#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 1000005;

int a[MAXN];

int main (int num, char **arg){
  int n, rnd;
  sscanf(arg[1], "%d", &n);
  sscanf(arg[2], "%d", &rnd);
  printf("%d\n", n);
  for (int i = 0; i < n; ++i) a[i] = i + 1;
  srand(rnd);
  for (int i = 0; i < 1 + rand()%50; ++i) random_shuffle(a, a+n);
  for (int i = 0; i < n; ++i)
    printf("%d ", a[i]);
  return 0;
}

