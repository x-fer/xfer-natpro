#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <unistd.h>
#include <vector>

using namespace std;
struct stanje;

const int maxn = 128;
const int maxw = 1e6;
const int dx[2] = {-1, 0};
const int dy[2] = {0, -1};
const int dx4[4] = {-1,0,1,0};
const int dy4[4] = {0,1,0,-1};

int N, M;
char tbl[maxn][maxn];
char bio[maxn][maxn];
map<stanje, stanje> parent;

struct stanje {
  int x, y;
  explicit stanje (int x = -1, int y = -1) : x(x), y(y) {}

  stanje move(int sm) const {
    return stanje(x + dx4[sm], y + dy4[sm]);
  }

  void enqueue(queue<stanje> *Q, const stanje &c) const {
    if (x < 0 || y < 0 || x >= N || y >= M) return;
    if (bio[x][y] || tbl[x][y] == 'x') return;
    bio[x][y] = 1;
    Q->push(*this);
    parent[*this] = c;
  }

  bool operator< (const stanje &rhs) const {
    return pair<int, int>(x,y) < pair<int, int>(rhs.x, rhs.y);
  }
  bool operator== (const stanje &rhs) const {
    return !(*this < rhs) && !(rhs < *this);
  }
};

class union_find {
  mutable map<int, int> parent;

  int find(int x) const {
    map<int, int>::iterator it = parent.find(x);
    if (it == parent.end() || it->second == x) return x;
    return parent[x] = find(parent[x]);
  }

 public:
  bool equal(int x, int y) const {
    return find(x) == find(y);
  }
  void merge(int x, int y) {
    x = find(x), y = find(y);
    rand() & 1 ? parent[x] = y : parent[y] = x;
  }
};

struct edge {
  int from, to, weight;

  edge (int m, int x, int y, int sm) :
    from(x * m + y),
    to((x + dx[sm]) * m + (y + dy[sm])),
    weight(rand() % maxw) {}

  bool operator< (const edge &rhs) const {
    return weight < rhs.weight;
  }
};

void build_graph(int n, int m, vector<edge> *graph) {
  for (int i = 1; i < n; ++i)
    graph->push_back(edge(m, i, 0, 0));
  for (int j = 1; j < m; ++j)
    graph->push_back(edge(m, 0, j, 1));
  for (int i = 1; i < n; ++i)
    for (int j = 1; j < m; ++j)
      for (int sm = 0; sm < 2; ++ sm)
        graph->push_back(edge(m, i, j, sm));
}

void calc_mst(const vector<edge> &graph, vector<edge> *mst) {
  union_find UF;
  for (size_t j = 0; j < graph.size(); ++j) {
    const edge &e = graph[j];
    if (!UF.equal(e.from, e.to)) {
      UF.merge(e.from, e.to);
      mst->push_back(e);
    }
  }
}

pair<int, int> getXY(int m, int id) {
  return pair<int, int>(2 * (id / m), 2 * (id % m));
}

void output_labyrinth(int n, int m, const vector<edge> &mst) {
  vector<string> map(n * 2 - 1, string(m * 2 - 1, 'x'));
  for (size_t j = 0; j < mst.size(); ++j) {
    pair<int, int> from = getXY(m, mst[j].from), to = getXY(m, mst[j].to);
    map[from.first][from.second] = '.';
    map[(from.first + to.first) / 2][(from.second + to.second) / 2] = '.';
    map[to.first][to.second] = '.';
  }
  N = n * 2 - 1;
  M = m * 2 - 1;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      tbl[i][j] = map[i][j];
    }
  }
  tbl[0][0] = '.';
}

void build_labyrinth(int n, int m) {
  vector<edge> graph, mst;
  n = (n + 1) / 2, m = (m + 1) / 2;
  build_graph(n, m, &graph);
  sort(graph.begin(), graph.end());
  calc_mst(graph, &mst);
  output_labyrinth(n, m, mst);
}

bool bfs(stanje S, stanje F) {
  queue<stanje> Q;
  for (Q.push(S); Q.size(); Q.pop()) {
    stanje &s = Q.front();
    if (s == F) {
      return true;
    }
    for (int sm = 0; sm < 4; ++sm) {
      s.move(sm).enqueue(&Q, s);
    }
  }
  return false;
}

int target_col_id, target_shift;
deque<char> target_col;

void reconstruct(stanje S, stanje F) {
  for (stanje it = F; !(it == S); it = parent[it]) {
    tbl[it.x][it.y] = '@';
  }
  tbl[S.x][S.y] = '@';
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (j == target_col_id) {
        target_col.push_back(tbl[i][j] == '@' ? '.' : 'x');
      }
    }
  }
}

void output() {
  printf("%d %d\n", N, M);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (j == target_col_id) {
        printf("%c", target_col[i]);
      } else {
        printf("%c", tbl[i][j] == '@' ? '.' : tbl[i][j]);
      }
    }
    printf("\n");
  }
}

void lcirc() {
  for (int j = 0; j < target_shift; ++j) {
    int tmp = target_col.front();
    target_col.pop_front();
    target_col.push_back(tmp);
  }
}

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "usage: %s rows cols\n", *argv);
    return 1;
  }
  int n = -1, m = -1;
  sscanf(argv[1], "%d", &n);
  sscanf(argv[2], "%d", &m);
  if (n < 0 || m < 0 || n > 1000 || m > 1000) {
    fprintf(stderr, "usage: %s rows cols\nn, m <= 1000\n", *argv);
    return 1;
  }
  srand(n * m * getpid());
  build_labyrinth(n, m);
  if (bfs(stanje(0,0), stanje(N-1,M-1)) != 1) {
    fprintf(stderr, "internal: put ne postoji\n");
    return 1;
  }
  target_col_id = -1;
  target_col_id = rand() % M, target_shift = 1 + rand() % (N-1);
  reconstruct(stanje(0,0), stanje(N-1,M-1));
  lcirc();
  fprintf(stderr, "%d %d\n", target_col_id + 1, target_shift);
  output();

  return 0;
}
