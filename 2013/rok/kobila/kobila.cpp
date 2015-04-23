#include <queue>
#include <cstdio>
#include <cstring>
using std::queue;

const int maxn = 101;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int N, M;
char map[maxn][maxn];
char bio[maxn][maxn];

struct stanje {
  int x, y;
  explicit stanje(int x = -1, int y = -1) : x(x), y(y) { }

  bool valid() const {
    if (x < 0 || y < 0 || x >= N || y >= M) return 0;
    if (bio[x][y] || map[x][y] == 'x') return 0;
    return 1;
  }

  void nextify(int sm, queue<stanje> *Q) {
    stanje next(x + dx[sm], y + dy[sm]);
    if (next.valid()) {
      bio[next.x][next.y] = true;
      Q->push(next);
    }
  }

  bool operator== (const stanje &rhs) const {
    return x == rhs.x && y == rhs.y;
  }
};

bool check() {
  memset(bio, 0, sizeof bio);
  queue<stanje> Q;
  for (Q.push(stanje(0, 0)); Q.size(); Q.pop()) {
    stanje &c = Q.front();
    if (c == stanje(N - 1, M - 1))
      return true;
    for (int sm = 0; sm < 4; ++sm)
      c.nextify(sm, &Q);
  }
  return false;
}

void load() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; ++i) {
    scanf("%s", (char*) (map + i));
  }
}

void output() {
  for (int i = 0; i < N; ++i) {
    printf("%s\n", map[i]);
  }
  printf("\n");
}

void solve() {
  for (int i = 0; i < M; ++i) {
    for (int circ = 0; circ < N; ++circ) {
      // printf("* %d\n", circ); output();
      if (check()) {
        printf("%d %d\n", i + 1, circ);
      }
      char tmp = map[N-1][i];
      for (int k = N - 2; k >= 0; --k)
        map[k+1][i] = map[k][i];
      map[0][i] = tmp;
    }
  }
}

int main() {
  load();
  solve();
  return 0;
}
