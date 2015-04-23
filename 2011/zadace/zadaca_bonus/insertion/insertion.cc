#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int MAX = 1000010;

struct fenwick{
  long long int a[ MAX ];
  
  void clear( void ){ memset( a, 0 , sizeof a ); }
  
  void set( int i ){ for( ++i; i < MAX; i += i & -i ) a[i]++; }
  long long int get( int i ){ long long int ret = 0; for( ++i; i ; i -= i & -i ) ret += a[i]; return ret; }
  
} loga;

int main( int argc, char **argv ){
    
  int n;  scanf( "%d", &n );
  long long sol = 0;
  
  loga.clear();
  
  for( int i = 0; i < n; ++i ){
    int a;  scanf( "%d", &a );
    sol += i - loga.get( a );
    loga.set( a );
  }
  
  printf( "%lld\n", sol );
  
  return 0;
}
