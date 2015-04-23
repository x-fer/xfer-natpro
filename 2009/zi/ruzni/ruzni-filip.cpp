#include <cstdio>
#include <set>
#include <cassert>
using namespace std;

const long long LLMAX = (unsigned long long)(-1)>>1;

const int p[5] = { 2, 3, 5, 7, 11 };

int main( void ) {

 set<long long> S;
 S.insert(1);

 int n; scanf( "%d", &n );

 for( ; n; --n ) {
    long long num = *S.begin(); S.erase( num );
    for( int i = 0; i < 5; ++i ) {
        assert( num <= LLMAX/p[i] );
        S.insert( num*p[i] );
    }
 }

 printf( "%lld\n", *S.begin() );

 return 0;
}
