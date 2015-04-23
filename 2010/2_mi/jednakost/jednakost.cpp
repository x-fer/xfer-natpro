#include <cstdio>

using namespace std;

const int MOD = 1000000007;
const int N = 100000;

typedef long long llint;

llint power_mod(llint a, llint b, llint mod) {
  if (b == 0) return 1;
  if (b & 1) return a * power_mod(a * a % mod, b / 2, mod) % mod;
  return power_mod(a * a % mod, b / 2, mod);
}

int main(void) {

  int a, b, c, d;
  scanf("%d %d %d %d", &a, &b, &c, &d);

  for (int mod = MOD; mod < MOD + N; ++mod) {
    if (power_mod(a, b, mod) != power_mod(c, d, mod)) {
      puts("NE");
      return 0;
    }
  }

  puts("DA");
  return 0;
}
