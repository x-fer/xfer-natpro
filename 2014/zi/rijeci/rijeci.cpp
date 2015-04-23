#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <assert.h>
#define MAXN 300
using namespace std;

const int inf = 1e9;

string word[MAXN];
int graph[MAXN][MAXN];
int n, q;

int done[MAXN];

bool similar(int x, int y){
  if (abs((int)word[x].size() - (int)word[y].size()) >= 2) return false;

  int i, lx = word[x].size(), ly = word[y].size();
  for (i=0; i<ly && i<lx; i++)
    if (word[x][i] != word[y][i]) break;

  if (i == lx || i == ly) return true;
  if (i+1 == lx && i+1 == ly) return true;
  if (i+1 < lx && i+1 < ly && word[x].substr(i+1) == word[y].substr(i+1)) return true;
  if (i+1 < lx && word[x].substr(i+1) == word[y].substr(i))   return true;
  if (i+1 < ly && word[x].substr(i)   == word[y].substr(i+1)) return true;

  return false;
}

void calc_path(void){
  for (int k=0; k<n; k++)
    for (int i=0; i<n; i++)
      for (int j=0; j<n; j++)
        graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
}

int main(void){
  scanf ("%d%d", &n, &q); for (int i=0; i<n; i++) cin >> word[i];

  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++){
      graph[i][j] = (i == j) ? 0 : inf;
      if (i != j && similar(i, j)) graph[i][j] = 1;
    }

  calc_path();

  for (int i=0; i<q; i++){
    int a, b; scanf ("%d%d", &a, &b); a--; b--;
    assert(a != b);
    printf ("%d\n", graph[a][b]);
  }

  return 0;
}
