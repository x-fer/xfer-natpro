#include <cstdio>

inline long long broji(long long n, int p) {
  return (long long)(n / p);
}

int main() {
  long long n;

  scanf("%lld", &n);
  printf("%lld\n", n - broji(n, 4) - broji(n, 9) - broji(n, 25) + broji(n, 4 * 9) + broji(n, 4 * 25) + broji(n, 9 * 25) - broji(n, 4 * 9 * 25));

  return 0;
}
