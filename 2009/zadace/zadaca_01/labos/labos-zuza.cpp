/*

Natjecateljsko programiranje
1. Domaca zadaca
Zadatak LABOS

autor rjesenja: Goran Zuzic

Za svaku vrstu ispita cuvat cemo popis slobodnih klupa.

Kada ucenik dolazi, pogledamo koji ispit on pise i dodijelimo mu prvu slobodnu klupu.
Kada ucenik odlazi, njegovu klupu vratimo u popis slobodnih klupa.

Da bismo ove operacije izveli brzo, koristimo strukturu set, ugradjenu u C++.

*/

#include <algorithm>
#include <functional>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <set>
#include <vector>
#include <string>

using namespace std;

const int MAXN = 200100;

char buff[ 100 ];

set< int > S[ 2 ];

int Gdje[ MAXN ];
int Koji[ MAXN ];

int main( void )
{
int n, q; scanf( "%d %d", &n, &q );

for( int i = 0; i < n; ++i ) {
S[0].insert( i );
S[1].insert( i );
}

for( int i = 0; i < q; ++i ) {
scanf( "%s", buff );

if( buff[0] == 'D' ) {
int ind, x; scanf( "%d %d", &ind, &x ); --ind, --x;
Koji[ind] = x;
Gdje[ind] = *S[x].begin(); S[x].erase( S[x].begin() );
printf( "%d\n", Gdje[ind] + 1 );
}
else {
int ind; scanf( "%d", &ind ); --ind;
S[ Koji[ind] ].insert( Gdje[ind] );
}
}

return (0-0);
}


