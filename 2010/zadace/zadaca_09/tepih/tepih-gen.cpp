#include <cstdio>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdlib>
using namespace std;

int get_rand(int lo, int hi) {
  return lo + rand() % (hi-lo+1);
}

const int GENERIRAJ_SLIKU = 1;
const double SCALE_FACTOR = 0.3;

int main(int argc, char *argv[]) {

  if(argc != 3) {
    puts("Prvi argument mora biti <n>, a drugi <maksimalna koordinata>");
    puts("Generirane koordinate bit ce u rasponu 0...<maksimalna koordinata>");
    return 1;
  }

  srand(time(NULL));

  int n; sscanf(argv[1], "%d", &n);
  int maks_koord; sscanf(argv[2], "%d", &maks_koord);

  if (GENERIRAJ_SLIKU) {
    fprintf(stderr, "<svg width=\"1000\" height=\"1000\" version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">\n");
  }

  printf("%d\n", n);


  for (int i = 0; i < n; ++i) {
    int x1 = get_rand(0, maks_koord-1);
    int y1 = get_rand(0, maks_koord-1);

    int x2 = x1 + get_rand(1, (int)(SCALE_FACTOR*maks_koord));
    int y2 = y1 + get_rand(1, (int)(SCALE_FACTOR*maks_koord));

    x2 = min(x2, maks_koord);
    y2 = min(y2, maks_koord);


    printf("%d %d %d %d\n", x1, y1, x2, y2);

    if (GENERIRAJ_SLIKU) {
      fprintf(stderr,
"<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"red\" stroke=\"black\" stroke-width=\"2\" opacity=\"0.5\"/>\n",
      x1, y1, x2-x1, y2-y1);

    }
  }

  if (GENERIRAJ_SLIKU) {
    fprintf(stderr, "</svg>\n");
  }

return 0;
}
