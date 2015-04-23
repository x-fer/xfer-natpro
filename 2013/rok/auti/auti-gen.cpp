#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <random>


int main(int argc, char *argv[]) {
  int n, m, x;
  sscanf(argv[1], "%d", &n);
  sscanf(argv[2], "%d", &m);
  if (argc > 3) {
    sscanf(argv[3], "%d", &x);
  } else {
    x = m;
  }

  std::default_random_engine generator(time(0));
  std::uniform_int_distribution<int> B(0,x-1);
  printf("%d %d\n", n, m);
  for (int i = 0; i < n; ++i) {
    int b = B(generator);
    std::uniform_int_distribution<int> A(b+1,x);
    int a = A(generator);
    printf("%d %d\n", a, b);
  }
  return 0;
}
