#include <algorithm>
#include <functional>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>

using namespace std;

const int MAXN = 50234;
const int MAXLEN = 1234;
const int mod = 10007;

int len;
char S[MAXLEN+1];

int n;
char dict[MAXN][MAXLEN+1];
int lens[MAXN];

int dp[MAXLEN+1];

inline bool is_in_dict(int l, int r) {
  for (int i = 0; i < n; ++i) {
    if (lens[i] != r-l+1) continue;
    if (!strncmp(dict[i], S+l, lens[i])) return true;
  }
  return false;
}

int main(void)
{
  scanf("%s", S); len = strlen(S);
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", dict[i]);
    lens[i] = strlen(dict[i]);
  }

  dp[0] = 1;
  for (int r = 0; r < len; ++r) {
    int &ref = dp[r+1];
    ref = 0;
    for (int l = r; l >= 0; --l) {
      if (is_in_dict(l, r)) {
        ref += dp[l];
        if (ref >= mod) ref -= mod;
      }
    }
  }

  printf("%d\n", dp[len] % mod);
  return 0;
}
