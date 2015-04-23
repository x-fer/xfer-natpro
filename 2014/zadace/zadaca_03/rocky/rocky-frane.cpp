#include <iostream>

using namespace std;

const int MOD = 1000007;

int dp[1000001];

int main() {
  int n;
  cin >> n;
  dp[0] = dp[1] = 1;
  dp[2] = 2;
  for (int i = 3; i <= n; i++) {
    dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    dp[i] %= MOD;
  }
  cout << dp[n] << endl;
  return 0;
}
