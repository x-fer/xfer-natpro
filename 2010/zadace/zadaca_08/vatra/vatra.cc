#include <cstring>
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <utility>
#include <vector>
using namespace std;

#define FR(i,a,b) for(int i=(a);i<(b);++i)
#define FOR(i,n) FR(i,0,n)
#define FORALL(i,v) for(typeof((v).end())i=(v).begin();i!=(v).end();++i)
#define CLR(x,a) memset(x,a,sizeof(x))
#define BEND(v) (v).begin(),(v).end()
#define MP make_pair
#define PB push_back
#define A first
#define B second
#define dump(x) cerr << #x << " = " << (x) << endl
typedef long long ll; typedef long double ld;

const int inf = 0x20202020;

int dr[] = { 0, 1, 0, -1 },
    dc[] = { 1, 0, -1, 0 };

int R,C;
char grid[1000][1000];
int fd[1000][1000];
int jd[1000][1000];
void bfs(deque<pair<int,int> > &q, int (*d)[1000]) {
  while (q.size()) {
    int r = q.front().A, c = q.front().B;
    q.pop_front();

    FOR(k,4) {
      int r2 = r+dr[k], c2 = c+dc[k];
      if (r2<0 || r2>=R || c2<0 || c2>=C) continue;
      if (grid[r2][c2] == '#') continue;

      if (1+d[r][c] < d[r2][c2]) {
	d[r2][c2] = 1+d[r][c];
	q.PB(MP(r2,c2));
      }
    }
  }
}

int main() {
  scanf("%d%d",&R,&C);
  assert(1 <= R && R <= 1000);
  assert(1 <= C && C <= 1000);

  deque<pair<int,int> > fq,jq;
  CLR(fd,0x20);
  CLR(jd,0x20);
  FOR(r,R) {
    FOR(c,C) {
      char ch;
      scanf(" %c",&ch);

      grid[r][c] = ch;
      if (ch=='J') {
	jq.PB(MP(r,c));
	jd[r][c] = 0;
      } else if (ch=='F') {
	fq.PB(MP(r,c));
	fd[r][c] = 0;
      }
    }
  }
  assert(jq.size() == 1);

  bfs(fq,fd);
  bfs(jq,jd);

  int best = inf;
  #define TRYIT(r,c) if (grid[r][c] != '#' && jd[r][c] < fd[r][c]) if(best>jd[r][c]+1) best = jd[r][c]+1
  FOR(r,R) {
    TRYIT(r,0);
    TRYIT(r,C-1);
  }
  FOR(c,C) {
    TRYIT(0,c);
    TRYIT(R-1,c);
  }

  if (best < inf) {
    printf("%d\n",best);
  } else {
    printf("NEMOGUCE\n");
  }
}
