#include <ctime>
#include <cstdio>
#include <random>


int main(int argc, char **argv) {
  int n, m;
  double p1, p2, p3;

  sscanf(argv[1], "%d", &n);
  sscanf(argv[2], "%d", &m);
  sscanf(argv[3], "%lf", &p1);
  sscanf(argv[4], "%lf", &p2);
  sscanf(argv[5], "%lf", &p3);

  std::mt19937 rng;
  std::bernoulli_distribution dijamant(p1);
  std::bernoulli_distribution zlato(p2);
  std::bernoulli_distribution kamen(p3);
  std::bernoulli_distribution dolje(0.5);
  rng.seed(time(0));
  char P[n][m+1];

  printf("%d %d\n", n, m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (dijamant(rng)) {
        P[i][j] = 'D';
      } else if (zlato(rng)) {
        P[i][j] = 'Z';
      } else if (kamen(rng)) {
        P[i][j] = '#';
      } else {
        P[i][j] = '.';
      }
    }
    P[i][m] = 0;
  }

  int x = 0;
  int y = 0;

  do {
    if (P[x][y] == '#') {
      P[x][y] = '.';
    }

    if (x != n-1 && dolje(rng)) {
      ++x;
    } else if (y != m-1) {
      ++y;
    }

  } while (x != n-1 || y != m-1);

  if (P[x][y] == '#') {
    P[x][y] = '.';
  }

  for (int i = 0; i < n; ++i) {
    printf("%s\n", P[i]);
  }

	return 0;
}
