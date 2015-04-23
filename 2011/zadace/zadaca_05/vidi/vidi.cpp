#include <cstdio>

int euler_phi(int n) {
	int sol = 1;
  for (int zalpha, alpha, k; n > 1; n /= zalpha) {
    /* alpha = nd[n] */
		for (alpha = 2; n % alpha; ++alpha);
    /* zalpha = alpha ^ k , nd[n] ^ k | n */
		for (zalpha = 1, k = 0; n % (zalpha * alpha) == 0; zalpha *= alpha, k++);
    /* do the math */
		sol *= zalpha - (zalpha / alpha);
	}
	return n ? sol : 0;
}

const int M = 1000;
int memo[M][M];
int gcd(int a, int b) {
  if (!a) return b == 1;
  if (!b) return a == 1;
  if (a < M && b < M) {
    if (memo[a][b]) return memo[a][b];
    return memo[a][b] = (a % b ? gcd(b, a % b) : b);
  } else {
    return a % b ? gcd(b, a % b) : b;
  }
}

int main() {
  int x, y, t;
  scanf("%d%d", &x, &y);
  if (x > y) {t = x, x = y, y = t;}
  t = 0;
  if (!x && !y) {
    printf("0\n");
    return 0;
  }
  for (int i = 0; i <= x; ++i)
    t += euler_phi(i) * 2;
  for (int i = 0; i <= x; ++i)
    for (int j = x + 1; j <= y; ++j)
      if (gcd(i,j) == 1)
        t += 1;
  printf("%d\n", 1 + t);
  return 0;
}
