#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdint>
#include <cstdio>

using namespace std;

const int MAX_N = 200001;

char s[MAX_N];
int main() {
  int n, q;
  scanf("%d %d %s", &n, &q, s);

  for (int i = 0; i < q; i++) {
    int s1, s2, l;
    scanf("%d %d %d", &s1, &s2, &l);

    int t;
    for (t = 0; t < l; t++) {
      if (s[s1+t] != s[s2+t]) {
        printf("NE\n");
        break;
      }
    }
    if (t == l) {
      printf("DA\n");
    }
  }

  return 0;
}
