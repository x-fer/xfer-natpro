#include <cstdio>
#include <vector>
using namespace std;
#define FORC(it, C) for(__typeof((C).begin()) it = (C).begin(); it != (C).end(); ++it) 

const int MAXN = 100100;

int n;
int x[MAXN], y[MAXN];
vector< int > na_x[MAXN], na_y[MAXN];
bool bio[MAXN];
bool obidjeni_x[MAXN], obidjeni_y[MAXN];

void input(void) {
  scanf("%d", &n); ++n; 
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", x+i, y+i);
   }
}

void preprocess(void) {
  for (int i = 0; i < n; ++i) {
    na_x[x[i]].push_back(i);
    na_y[y[i]].push_back(i);
  }
}

void dfs(int i) {
  if (bio[i]) return;
  bio[i] = 1;
  if (!obidjeni_x[x[i]]) {
    obidjeni_x[x[i]] = 1;
    FORC(it, na_x[x[i]]) {
      dfs(*it);
    }
  }
  if (!obidjeni_y[y[i]]) {
    obidjeni_y[y[i]] = 1;
    FORC(it, na_y[y[i]]) {
      dfs(*it);
    }
  }
}

void solve(void) {
  int cnt = 0;

  for (int i = 0; i < n; ++i) {
    if (!bio[i]) {
      dfs(i);
      ++cnt;
    }
  }

  printf("%d\n", cnt - 1);
}

int main(void) {
  input();
  preprocess();
  solve();
  
  return 0;
}

