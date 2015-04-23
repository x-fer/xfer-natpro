#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

const int MAXN = 100100;

typedef pair< int, int > par;
#define x first
#define y second

vector< par > pts;
vector< int > ptsx[MAXN];
vector< int > ptsy[MAXN];

bool seen[MAXN];
bool seenx[MAXN];
bool seeny[MAXN];

inline void dfs(int id) {
  if (seen[id]) return;
  seen[id] = true;

  int x = pts[id].x;
  int y = pts[id].y;
  
  if (!seenx[x]) {
    seenx[x] = true;
    for (int i = 0; i < ptsx[x].size(); ++i)
      dfs(ptsx[x][i]);
  }
  
  if (!seeny[y]) {
    seeny[y] = true;
    for (int i = 0; i < ptsy[y].size(); ++i)
      dfs(ptsy[y][i]);
  }
}

int main(void) 
{
  int N;
  scanf("%d", &N);
  
  for (int i = 0; i < N + 1; ++i) {
    par p;
    scanf("%d %d", &p.x, &p.y);
    pts.push_back(p);
    ptsx[p.x].push_back(i);
    ptsy[p.y].push_back(i);
  }
  
  int C = 0;
  for (int i = 0; i < N + 1; ++i)
    if (!seen[i]) {
      ++C;
      dfs(i);
    }
  
  printf("%d\n", C - 1);
  return 0;
}
