#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

const int MAXQ = 100100;

int Q, MAXN;
int A[MAXQ];
int B[MAXQ];

inline int rand32() {
  return (rand() << 15) + rand();
}

int main(void) {

  scanf("%d %d", &Q, &MAXN);
  srand(unsigned(time(NULL)));

  for (int i = 0; i < Q; ++i) {
    A[i] = rand32() % MAXN + 1;
    B[i] = rand32() % MAXN + 1;
    if (B[i] < A[i]) swap(A[i], B[i]);
  }

  printf("%d\n", Q);

  for (int i = 0; i < Q; ++i)
    printf("%d %d\n", A[i], B[i]);

  return 0;
}