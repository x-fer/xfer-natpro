#include <algorithm>
#include <functional>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <set>

using namespace std;

const int MAXN = 50234;
const int MAXLEN = 1234;
const int mod = 10007;

typedef unsigned long long hash_t;

int len;
char S[MAXLEN+1];

int n;
int lens[MAXN];
int dp[MAXLEN+1];

set<hash_t> dict;
hash_t prefix[MAXLEN+1];
hash_t potP[MAXLEN+1];

inline bool is_in_dict(int l, int r) {
  return dict.count(prefix[r+1] - potP[r-l+1]*prefix[l]);
}

const int P = 1237;

void prec() {
  prefix[0] = 0;
  potP[0] = 1;
  for (int i = 0; i < len; ++i) {
    potP[i+1] = potP[i]*P;
    prefix[i+1] = prefix[i]*P + S[i] - 'a' + 1;
  }
}

int main(void)
{
  scanf("%s", S); len = strlen(S);
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    static char rijec[MAXLEN];
    scanf("%s", rijec);
    hash_t hash = 0;
    for (char* ptr = rijec; *ptr; ++ptr) {
      hash = hash*P + (*ptr) - 'a' + 1;
    }
    dict.insert(hash);
  }

  prec();
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
