
/*
HIO 2004
Zadatak MRAVI
*/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>

using namespace std;

multiset<int> pozicije;
int d, v, n, x;
char buff[10];

int main( void ) {
  cin >> d >> v >> n;

  for( int i = 0; i < n; ++i ) {
    cin >> x >> buff;

    if( buff[0] == 'L' ) x -= v; else x += v;

    x %= 2*d;
    if( x < 0 ) x = 2*d + x;
    if( x > d ) x = 2*d - x;

    pozicije.insert( x );
  }

  copy( pozicije.begin(), pozicije.end(), ostream_iterator<int> (cout, " ") );
  cout << endl;

  return 0;
}
