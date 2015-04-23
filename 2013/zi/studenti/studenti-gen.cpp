#include <cstdio>
#include <cstdlib>
#include <unistd.h>

typedef long long llint;

int gen_glasni() {
  int maxn = 1e5;
  llint maxg = 1e6;
  printf("%d\n", maxn);
  for (int j = 0; j < maxn; ++j) {
    printf("0 %lld %lld %lld\n", maxg, maxg, maxg);
  }
  return 0;
}

int gen(int N, llint maxT, llint maxG) {
  printf("%d\n", N);
  for (int j = 0; j < N; ++j) {
    int from = rand() % (maxT + 1);
    int to = from + rand() % (maxT - from + 1);
    llint poc = -maxG + rand() % (2*maxG+1);
    llint amp = -maxG + rand() % (2*maxG+1);
    printf("%d %d %lld %lld\n", from, to, poc, amp);
  }
  return 0;
}


int main(int argc, char **argv) {
  srand(getpid());

  if (argc != 2) {
    fprintf(stderr, "%s [broj od 1..10]\n", *argv);
    return 1;
  }

  int casen;
  if (sscanf(argv[1], "%d", &casen) != 1 || casen < 0 || casen > 10) {
    fprintf(stderr, "%s [broj od 1..10]\n", *argv);
    return 1;
  }

  if (casen == 1 || casen == 2) {
    return gen(100, 100, 100);
  }
  if (casen == 3 || casen == 4) {
    return gen(1000, 1e6, 1e6);
  }
  if (casen < 10) {
    return gen(1e5, 1e6, 1e6);
  }
  return gen_glasni();
}
