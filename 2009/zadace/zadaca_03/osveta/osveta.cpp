/*
  Natjecateljsko programiranje
  3. Domaca zadaca
  Zadatak OSVETA

  autor rjesenja: Filip Pavetic

    Organizacijom podataka u sqrt(A) blokova, svaka se operacija moze napraviti u slozenosti O(sqrt(A))
*/

#include <cassert>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXBROJ = 1000000;
const int BLOKOVI = 1000; // sqrt(MAXBROJ)
const int UBLOKU  = MAXBROJ/BLOKOVI+1;

vector<int> brojevi[ BLOKOVI ]; // za svaki blok cuva se popis brojeva
int n, m, p;

inline int getblok( int param ) {
    return param / UBLOKU;
}

inline void dodaj( int param ) {
//printf( "dodajem %d\n", param );

    int blok = getblok( param );
    brojevi[blok].push_back( param );
    int i = brojevi[blok].size()-1;

    for( ; i > 0; --i ) {
        if( brojevi[blok][i] >= brojevi[blok][i-1] ) break;
        swap( brojevi[blok][i], brojevi[blok][i-1] );
    }

}

inline void brisi( int k ) { // brisi k-ti po redu
//printf( "brisem %d.\n", k );

    for( int i = 0; i < BLOKOVI; ++i ) {
            //printf( "k=%d\n", k );
            if( k <= (int)brojevi[i].size() ) { // u ovom je bloku!!!
                brojevi[i].erase( brojevi[i].begin()+k-1 );
                break;
            } else {
                k -= (int)brojevi[i].size();
            }
    }


}

inline int koliko( int param ) {
//printf( "koliko ih je <= %d\n", param );

    int blok = getblok(param);
    int ret = 0;

    for( int i = 0; i < blok; ++i ) ret += (int)brojevi[i].size();
    for( int i = 0; i < brojevi[blok].size(); ++i )
        if( brojevi[blok][i] <= param ) ++ret;


    return ret;

}

int main( void ) {

    scanf( "%d%d%d", &n, &m, &p );
    for( int i = 0; i < n; ++i ) {
        int a; scanf( "%d", &a );
        assert( 0 <= a < MAXBROJ );
        dodaj( a );
    }

    int koliko_m = 0, koliko_p = 0;
    for( int i = 0; i < m+p; ++i ) {

        char komanda[16];
        int param;
        scanf( "%s%d", komanda, &param );

        if( *komanda == 'D' ) {
            ++koliko_p;

            // 0 <= param < MAXBROJ
            assert( 0 <= param && param < MAXBROJ );
            dodaj( param );
        }
        if( *komanda == 'B' ) {
            ++koliko_p;

            // 1 <= param <= ukupan broj brojeva u memoriji
            assert( 1 <= param && param <= koliko( MAXBROJ ) );
            brisi( param );
        }
        if( *komanda == 'K' ) { // 0 <= param < MAXBROJ
            ++koliko_m;
            assert( 0 <= param && param < MAXBROJ );
            printf( "%d\n", koliko( param ) );
        }
    }

    assert( koliko_m == m );
    assert( koliko_p == p );

return 0;
}
