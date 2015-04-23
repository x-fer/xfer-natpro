#include <cstdio>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
  return b ? gcd(b, a%b) : a;
}

int main() {
  int n, target_gcd;
  int len = 0, current_gcd = 0, ans = 0;

  scanf("%d%d", &n, &target_gcd);
  for (int i = 0; i < n; ++i) {
    int x; scanf("%d", &x);
    current_gcd = gcd(current_gcd, x);
    if (current_gcd % target_gcd != 0) {
      len = 0;
      current_gcd = 0;
    } else {
      ++len;
    }
    if (current_gcd == target_gcd)
      ans = max(ans, len);
  }

  printf("%d\n", ans);
  return 0;
}

