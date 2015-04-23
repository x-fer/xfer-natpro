
/*
DMIH 2003, Prvi dan natjecanja
Srednjoskolska skupina, II. podskupina
Zadatak SUMA, Programski jezik C++
*/

#include <algorithm>
#include <complex>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int n;
class vektor {
   public:
   int x, y;
   double kut;

   vektor() { kut = x = y = 0; }
   vektor( int xx, int yy ) {
      x = xx; y = yy;
      kut = atan2( yy, xx );
   }

   friend bool operator < ( const vektor &a, const vektor &b ) {
      return a.kut < b.kut;
   }

   vektor & operator += ( const vektor &a ) {
      x += a.x; y += a.y;
      return *this;
   }

   vektor & operator -= ( const vektor &a ) {
      x -= a.x; y -= a.y;
      return *this;
   }

   long long operator ~ () {
      return (long long) x*x + (long long) y*y;
   }
};
vector<vektor> v;
long long rez;

void input() {
   int i, x, y;
   scanf( "%d", &n );
   for( i = 0; i < n; ++i ) {
      scanf( "%d%d", &x, &y );
      v.push_back( * new vektor( x, y ) );
   }
   sort( v.begin(), v.end() );
}

void solve() {
   int i = 0, j = 0, krug = 0;
   vektor t;

   rez = ~(t += v[0]);
   for( ;; ) {
      if( ++j == n ) { j = 0; krug++; }
      while( v[j].kut + krug*2*PI - v[i].kut > PI ) {
         rez >?= ~(t -= v[i]);
         if( ++i == n ) return;
      }
      rez >?= ~(t += v[j]);
   }
}

int main( void ) {
   freopen( "suma.in", "rt", stdin );
   freopen( "suma.out", "wt", stdout );

   input();
   solve();
   cout << rez << endl;

   fclose( stdout );
   fclose( stdin );
   return 0;
}
