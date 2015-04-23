#include <iostream>
#include <string>
using namespace std;

int main( void ) {

 int n; cin >> n;

 for( int i = 0; i < n; ++i ) {
        cout << string( n-i-1, 'o' ) + string( 2*i+1, '#' ) + string( n-i-1, 'o' ) << endl;
 }
 cout << string( n-1, 'o' ) + "#" + string( n-1, 'o' ) << endl;

 return 0;
}
