#include <cstdio>
using namespace std;

int main( void ) {
  int n; scanf("%d", &n);
  int broj_nula = 0;
  for (int p = 5; p <= n; p *= 5)
    broj_nula += n / p;

  int ret = 1;
  for (int i = 1; i <= n; ++i) {
    int k = i;
    while (k % 5 == 0)
      k /= 5;
    while (broj_nula > 0 && k % 2 == 0) {
      k /= 2;
      broj_nula--;
    }
    ret = ret * k;
    ret %= 10;
  }
  printf("%d\n", ret);
  return 0;
}
