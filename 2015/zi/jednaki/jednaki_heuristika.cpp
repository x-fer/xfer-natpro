#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdint>

using namespace std;

typedef long long llint;
const int MAX_N = 200001;
const int MAX_ITER = 1000;

uint16_t rand_index;
int rand_nums[UINT16_MAX];

int main() {
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);

  for (rand_index = 0; rand_index < UINT16_MAX; rand_index++) {
    rand_nums[rand_index] = rand();
  }

  int n, q;
  string s;
  cin >> n >> q >> s;

  for (int i = 0; i < q; i++) {
    int s1, s2, l;
    cin >> s1 >> s2 >> l;

    if (l <= MAX_ITER) {
      int t;
      for (t = 0; t < l; t++) {
        if (s[s1+t] != s[s2+t]) {
          cout << "NE" << endl;
          break;
        }
      }
      if (t == l) {
        cout << "DA" << endl;
      }
      continue;
    }

    if (s[s1] != s[s2] || s[s1+l-1] != s[s2+l-1]) {
      cout << "NE" << endl;
      continue;
    }

    bool ne = false;
    for (int t = 0; t < MAX_ITER; t++) {
      int pos = rand_nums[rand_index++] % l;
      if (s[s1] != s[s2]) {
        cout << "NE" << endl;
        ne = true;
        break;
      }
    }

    if (!ne) {
      cout << "DA" << endl;
    }
  }

  return 0;
}
