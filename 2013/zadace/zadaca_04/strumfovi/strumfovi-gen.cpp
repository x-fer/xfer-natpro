#include <ctime>
#include <cstdio>
#include <random>


int main(int argc, char **argv) {
  int n, m=3;
  double p1;

  sscanf(argv[1], "%d", &n);
  sscanf(argv[2], "%lf", &p1);

  std::mt19937 rng;
  std::bernoulli_distribution d1(p1);
  std::uniform_int_distribution<int> d3(0, m-1);

  rng.seed(time(0));

  char red[4];
  int prolaz = 0;
  int novi_prolaz = 0;

  printf("%d\n", n);
  for (int i = 0; i < n; ++i) {
    if (i == 0 || i+1 == n) {
      printf("...\n");
      continue;
    }
    for (int j = 0; j < m; ++j) {
      if (d1(rng)) {
        red[j] = 'J';
      } else {
        red[j] = 'X';
      }
    }
    novi_prolaz = d3(rng);
    if (prolaz < novi_prolaz) {
      for (int j = prolaz; j <= novi_prolaz; ++j) {
        if (red[j] == 'X') {
          red[j] = '.';
        }
      }
    } else {
      for (int j = novi_prolaz; j <= prolaz; ++j) {
        if (red[j] == 'X') {
          red[j] = '.';
        }
      }
    }

    prolaz = novi_prolaz;
    printf("%s\n", red);
  }

	return 0;
}
