#include <ctime>
#include <cstdio>
#include <random>

int main(int argc, char **argv) {
  int n, m, k;

  sscanf(argv[1], "%d", &n);
  sscanf(argv[2], "%d", &m);
  if (argc > 3) {
    sscanf(argv[3], "%d", &k);
  } else {
    k = m;
  }

  std::mt19937 rng;
  std::uniform_int_distribution<int> distribution(1, k);
  rng.seed(time(0));

  printf("%d %d\n", n, m);
  for (int i = 0; i < n; ++i) {
      int x = distribution(rng);
      printf("%d%c", x, (i+1==n)?'\n':' ');
  }

	return 0;
}
