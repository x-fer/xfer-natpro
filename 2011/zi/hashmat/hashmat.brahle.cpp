#include <cstdio>

const int MAXL = 100020;

long long A, B, M, K, N;
char S[MAXL];

int main() {
  scanf("%lld%lld%lld%lld %s%lld", &A, &B, &M, &K, S, &N);
  A %= M;

  int start = 0;
  long long current_hash = 0;
  long long faktor = A;

  for (int i = K-1; i >= 0; --i) {
    current_hash = (current_hash + faktor * (S[i] + B)) % M;
//    printf("%d * %d (%c)\n", faktor, (S[i] + B), S[i]);
    faktor = (faktor * A) % M;
  }
  printf("%d\n", current_hash);

  for (int i = 0; S[K+i]; ++i) {
    current_hash *= A;
    current_hash %= M;
    current_hash -= (faktor * (S[i] + B)) % M;
    current_hash += M;
    current_hash %= M;
    current_hash += (A * (S[K+i] + B)) % M;
    current_hash %= M;
    printf("%d\n", current_hash);
  }

  return 0;
}
