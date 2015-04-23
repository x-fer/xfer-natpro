#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long llint;
const int mxn = 1001;

int n;
llint x[mxn], y[mxn];
llint r;

bool bio[mxn];
void dfs( int mina ){
  if( bio[mina] ) return;
  bio[mina] = 1;

  for( int i = 0; i < n; i++ ){
    llint dist = (x[i]-x[mina])*(x[i]-x[mina]) + (y[i]-y[mina])*(y[i]-y[mina]);
    
    if( dist <= r ) dfs(i);
  }
}

int main(){
  scanf( "%d %lld", &n, &r );
  r *= r;

  for( int i = 0; i < n; i++ )
    scanf( "%lld %lld", &x[i], &y[i] );

  int ret = 0;
  for( int i = 0; i < n; i++ ){
    if( !bio[i] ){
      dfs(i);
      ret++;
    }
  }

  printf( "%d\n", ret );
  
  return 0;
}
