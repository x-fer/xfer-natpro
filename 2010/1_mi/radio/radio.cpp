#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int,int> par;

const int mxn = 510;

int pocetak = -1, kraj = -1;
int n;
par niz[mxn];
bool bio[mxn];

inline int dist( const par &a, const par &b ){ return abs(a.first-b.first) + abs(a.second-b.second); }

int R;
void dfs( int x ){
  if( bio[n+1] ) return;
  if( bio[x] ) return;
  bio[x] = 1;

  if( x != n && dist(niz[x], niz[n+1]) <= R ){
    bio[n+1] = 1;
    return;
  }

  int D = 2*R+1;
  if( x == n ) D = R;
  for( int i = 0; i < n; i++ )
    if( dist(niz[x],niz[i]) <= D )
      dfs(i);

}

bool ok( int r ){
  R = r;
  memset( bio, 0, sizeof(bio) );
  if( pocetak == -1 ) dfs(n);
  else dfs(pocetak);
  if( kraj != -1 ) return bio[n+1] || bio[kraj];
  return bio[n+1];
}

int main(){
  int r, s;
  scanf( "%d %d %d", &r, &s, &n );


  for( int i = 0; i < n; i++ ){
    scanf( "%d %d", &niz[i].first, &niz[i].second );
    if( niz[i].first == 1 && niz[i].second == 1 ) pocetak = i;
    if( niz[i].first == r && niz[i].second == s ) kraj = i;
  }
  niz[n] = par(1,1);
  niz[n+1] = par(r,s);

  int lo = 0, hi = r+s;
  while( lo < hi ){
    int mid = (lo+hi)/2;
    if( ok(mid) ) hi = mid;
    else lo = mid+1;
  }
  printf( "%d\n", lo );

  return 0;
}
