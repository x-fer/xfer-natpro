#include<cstdio>
#include<cstring>
#include<set>

using namespace std;

#define MAXN 1005
#define x first
#define y second
typedef long long llint;
typedef pair<int, int> par;

llint A, B, C;
int N;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

llint L[MAXN][MAXN];
llint G[MAXN][MAXN];
llint bio[MAXN][MAXN];
llint dist[MAXN][MAXN];

struct cmp{
  bool operator()(const par &a, const  par &b){
    return dist[a.x][a.y] < dist[b.x][b.y] || dist[a.x][a.y] == dist[b.x][b.y] && a<b;
  }
};

set<par, cmp> pq;

int legal(int i, int j){
  return i >= 0 && i < N && j >= 0 && j < N;
}

llint h(int i, int j){
  return ((i * N + j) * A + B) % C;
}

int main(){
  scanf("%d", &N);
  int xa, ya, xb, yb;
  scanf("%d %d %d %d", &xa, &ya, &xb, &yb);
  xa--;
  ya--;
  xb--;
  yb--;

  scanf("%lld %lld %lld", &A, &B, &C);
  for(int i = 0; i < N; i++)
    for(int j = 0; j < N;j++){
      G[i][j] = h(i,j);
      dist[i][j] = C + 1;
    }

  L[xa][ya] = G[xa][ya];
  dist[xa][ya] = 0;
  pq.clear();
  pq.insert(par(xa, ya));
  bio[xa][ya] = 1;
  while(!pq.empty()){
    int x = pq.begin()->x;
    int y = pq.begin()->y;
    if(x == xb && y == yb){ 
      printf("%lld\n", dist[x][y]+G[x][y]-L[x][y]);
      break;
    }

    bio[x][y] = 1;
    pq.erase(par(x,y));
    for(int i = 0; i < 4; i++){
      int X = x + dx[i];
      int Y = y + dy[i];
      if(!legal(X,Y)|| bio[X][Y]) continue;
      int price = 0;
      if(G[X][Y] < L[x][y]) price = L[x][y] - G[X][Y];
      if(dist[X][Y] > price + dist[x][y]){
	pq.erase(par(X,Y));
	dist[X][Y] = price + dist[x][y];
	L[X][Y] = min(L[x][y],G[X][Y]);
	pq.insert(par(X,Y));
      }
    }
  }

  return 0;
}

