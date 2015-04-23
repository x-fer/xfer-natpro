#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

#define MAXN 100003
#define x first
#define w second
#define mp make_pair
#define pb push_back

typedef pair<int, int> pint;
int n, bio[MAXN], prev[MAXN], c, s;
vector<pint> G[MAXN];
queue<int> q;

int main() {
  scanf("%d %d", &n, &s);
  s--;
  int a, b, d;
  int sum = 0 ;
  for(int i = 1; i < n; ++i) {
    scanf("%d %d %d", &a, &b, &d);
    G[a - 1].pb(mp(b - 1, d));
    G[b - 1].pb(mp(a - 1, d));
    sum += d;
  }

  queue<int> q;
  c++;
  q.push(s);
  q.push(0);
  int best = 0, dist = 0;
  bio[s]  = c;
  while(!q.empty()) {
    int cur = q.front(); q.pop();
    int curd = q.front(); q.pop();
    for(int i = 0; i < G[cur].size(); ++i) {
      if(bio[G[cur][i].x] == c) continue;
      bio[G[cur][i].x] = c;
      if(dist < G[cur][i].w + curd) {
	best = G[cur][i].x;
	dist = G[cur][i].w + curd;
      }
      q.push(G[cur][i].x);
      q.push(G[cur][i].w + curd);
    }
  }


  printf("%d\n", 2 * sum  - dist);
  return 0;
}
  



  

