#include <iostream>
#include <cstring>

using namespace std;

const int MXN = 1001;
int n;
int dp[MXN];
int prev_dp[MXN];

inline int min(int a, int b, int c) {
  return min(min(a, b), c);
}

int main() {
  cin >> n;
  int ret = 0;
  for (int r = 0; r < n; r++) {
    string redak;
    cin >> redak;
    for (int c = 0; c < n; c++) {
      if (redak[c] == '0') {
        dp[c] = min(c ? dp[c - 1] : 0, prev_dp[c], prev_dp[c - 1]) + 1;
      } else dp[c] = 0;
      ret = max(ret, dp[c]);
    }
    memcpy(prev_dp, dp, sizeof(dp));
  }
  cout << ret << endl;
}
