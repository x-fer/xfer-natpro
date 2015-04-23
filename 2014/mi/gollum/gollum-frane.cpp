#include <iostream>

using namespace std;

typedef long long llint;

const llint MXN = 101;
llint mem[MXN];

llint best(llint n) {
  if (mem[n]) return mem[n];
  llint ret = n;
  for (llint cut = 1; cut < n; cut++) {
    ret = max(ret, cut * best(n - cut));
  }
  return mem[n] = ret;
}

int main() {
  llint n;
  cin >> n;
  cout << best(n) << endl;
  return 0;
}
