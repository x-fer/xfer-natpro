#include <cstdio>
#include <cstring>

const int MAXM = 1000100;
const int MAXN = 1010;

int n, m;
int zarada[MAXM];
int A[MAXN], B[MAXN];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", A+i, B+i);
  }

  memset(zarada, -1, sizeof(zarada));
  zarada[0] = 0;
  int najbolji = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = m-A[i]; j >= 0; --j) {
      if (zarada[j] != -1 && zarada[j+A[i]] < zarada[j] + B[i]) {
        zarada[j+A[i]] = zarada[j] + B[i];
        if (zarada[j+A[i]] > najbolji) {
          najbolji = zarada[j+A[i]];
        }
      }
    }
  }

  printf("%d\n", najbolji);
  return 0;
}
