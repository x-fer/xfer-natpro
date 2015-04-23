#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;


struct event{
  int where, type, who;

  event( int where_, int type_, int who_ ){ where = where_; type = type_; who = who_; }
};
inline bool operator <( const event &a, const event &b ){
  if( a.where != b.where ) return a.where < b.where;
  return a.type < b.type;
}

struct posjet{
  int t1, t2;
  int wc; //0 ili 1

  posjet( int T, int D, int wc_ ){ t1 = T; t2 = t1+D; wc = wc_; }
};

int main(){
  vector <posjet> P;
  vector <event> E;

  int n1, n2;
  scanf( "%d", &n1 );
  for( int i = 0; i < n1; i++ ){
    int T, D;
    scanf( "%d %d", &T, &D );
    P.push_back(posjet(T,D,0));

    E.push_back(event(T, 0, i));
    E.push_back(event(T+D, 1, i));
  }

  scanf( "%d", &n2 );
  for( int i = 0; i < n2; i++ ){
    int T, D;
    scanf( "%d %d", &T, &D );
    P.push_back(posjet(T,D,1));

    E.push_back(event(T, 0, i+n1));
    E.push_back(event(T+D, 1, i+n1));
  }

  sort(E.begin(), E.end());
  int open[2] = {0,0};
  int prevT = 0, ret = 0;

  for( vector<event>::iterator it = E.begin(); it != E.end(); it++ ){
    if( open[0] > 1 && open[1] > 1 ) ret += it->where - prevT;

    if( it->type == 0 ) open[P[it->who].wc]++;
    else open[P[it->who].wc]--;

    prevT = it->where;
  }

  printf( "%d\n", ret );  
  return 0;
}
