#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

int main () {
  long long a = 1, b;
  cin >> b;
  int k;
  cin >> k;
  long long lcm = 1;
  for (int i = 1; i < k; ++i) {
    lcm = (lcm * i) / gcd(lcm, i);
  }
  long long sol = b / lcm - (a - 1) / lcm;
  lcm = (lcm * k) / gcd(lcm, k);
  sol -= (b / lcm - (a - 1) / lcm);
  cout << sol << endl;
  return 0;
}
