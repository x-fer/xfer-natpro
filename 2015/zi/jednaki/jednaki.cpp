#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long llint;
const int MAX_N = 200001;

class string_hash {
public:
  string_hash(const string& s) : prefix_hash(s.size()), len(s.size()) {
    llint hash = 0;
    for (int i = 0; i < len; i++) {
      hash = (hash * base + s[i]) % mod;
      prefix_hash[i] = hash;

      if (i == 0) {
        base_pow.push_back(1);
      } else {
        base_pow.push_back(((llint)base_pow[i-1] * base) % mod);
      }
    }
    base_pow.push_back(((llint)base_pow[len-1] * base) % mod);
  }

  int substr_hash(int start, int substr_len) const {
    llint hash = prefix_hash[start+substr_len-1];
    if (start > 0) {
      hash -= (llint)prefix_hash[start-1] * base_pow[substr_len];
      hash %= mod;
      if (hash < 0) hash += mod;
    }
    return hash;
  }

private:
  vector <int> prefix_hash;
  int len;

  const static int mod = int(1e9) + 7;
  const static int base = 3317;
  vector <int> base_pow;
};

char s[MAX_N];
int main() {
  int n, q;
  scanf("%d %d %s", &n, &q, s);

  string_hash h(s);
  for (int i = 0; i < q; i++) {
    int s1, s2, l;
    scanf("%d %d %d", &s1, &s2, &l);

    if (h.substr_hash(s1, l) == h.substr_hash(s2, l)) {
      printf("DA\n");
    } else {
      printf("NE\n");
    }
  }

  return 0;
}
