#include <algorithm>
#include <cstdio>
#include <cstring>

const int dr[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
const int ds[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };

int R, S;
int a[10][10];
int memo[101][10][10][9];

int rec( int k, int r, int s, int last_d ) {
   if( k < 0 ) return 0;

   int &ret = memo[k][r][s][last_d];
   if( ret >= 0 ) return ret;

   ret = 0;
   for( int d = 0; d < 8; ++d ) {
      int rr = r+dr[d];
      int ss = s+ds[d];
      if( (d^4) == last_d ) continue;
      if( rr < 0 || rr >= R ) continue;
      if( ss < 0 || ss >= S ) continue;
      ret = std::max( ret, a[r][s] + rec( k-1, rr, ss, d ) );
   }
   return ret;
}

int main( void ) {
   scanf( "%d%d", &R, &S );
   for( int r = 0; r < R; ++r )
      for( int s = 0; s < S; ++s )
         scanf( "%d", &a[r][s] );

   int r0, s0, k;
   scanf( "%d%d", &r0, &s0 );
   scanf( "%d", &k );

   memset( memo, -1, sizeof memo );
   printf( "%d\n", rec( k, r0-1, s0-1, 8 ) );

   return 0;
}
