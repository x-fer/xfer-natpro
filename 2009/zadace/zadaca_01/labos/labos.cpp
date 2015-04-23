/*

Natjecateljsko programiranje
1. Domaca zadaca
Zadatak LABOS

autor rjesenja: Filip Pavetic

Definirat cemo 4 skupa klupa: one slobodne, one u kojima sjedi ucenik
koji pise ispit #1, one u kojima sjedi ucenik koji pise ispit #2 i
zauzete. Sve klupe su na pocetku slobodne.

Kada dolazi ucenik koji pise ispit #1, on ce sjesti u minimum od
    a) svih klupa u kojima sjede samo ucenici koji pisu ispit #2 (ako sjeda ovdje, klupa postaje zauzeta)
    b) svih slobodnih klupa (ako sjeda ovdje tu je klupu potrebno premjestiti
                             u skup gdje sjede samo ucenici koji pisu ispit #1)
Analogno se dogadja kada dolazi ucenik koji pise ispit #2

Kada neki od ucenika odlazi:
    a) ako je sjedio sam u klupi, ta se klupa oslobadja
    b) ako je kraj njega sjedio ucenik koji pise drugi ispit, ta je klupa bila zauzeta,
       i sada ju je potrebno prebaciti u skup sa klupama u kojima sjede samo ucenici koji
       pisu "suprotan" ispit

Za brzo manipuliranje sa skupovima koristimo strukturu set, ugradjenu u C++

*/



#include <cassert>
#include <cstdio>
#include <set>
#include <vector>
using namespace std;

#define SLOBODNA 0
#define ISPIT1   1
#define ISPIT2   2
#define ZAUZETA  3

int gdje_sjedi[200000];
int sto_pise[200000];
set<int> klupe[4];

int get_slobodna( int ispit ) {

    int suprotan_ispit;
    if( ispit == 1 ) suprotan_ispit = 2;
    if( ispit == 2 ) suprotan_ispit = 1;

    if( !klupe[ suprotan_ispit ].empty() && *klupe[ suprotan_ispit ].begin() < *klupe[ SLOBODNA ].begin() ) {
        int ret = *klupe[ suprotan_ispit ].begin();
        klupe[ suprotan_ispit ].erase( ret );
        klupe[ ZAUZETA ].insert( ret );
        return ret;
    }

    int ret = *klupe[ SLOBODNA ].begin();
    klupe[ ispit ].insert( ret );
    klupe[ SLOBODNA ].erase( ret );
    return ret;

}

void oslobodi_mjesto( int gdje, int sto ) {
    // sto je 1 ili 2, to su odgovarajuci indeksi za setove "klupe"

    int suprotan_ispit = (sto == 1 ? 2 : 1);

    if( klupe[ sto ].find( gdje ) != klupe[ sto ].end() ) { // pisao je sam

        klupe[ sto ].erase( gdje );
        klupe[ SLOBODNA ].insert( gdje );

    } else { // bili su dvojica u klupi

        klupe[ ZAUZETA ].erase( gdje );
        klupe[ suprotan_ispit ].insert( gdje );

    }

}

int main( void ) {

    int n, d; scanf( "%d%d", &n, &d );
    for( int i = 1; i <= n+1; ++i ) klupe[ SLOBODNA ].insert( i );


    for( int i = 0; i < d; ++i ) {

        char komanda[50];
        scanf( "%s", komanda );

        if( komanda[0] == 'D' ) {

            int ucenik, ispit; scanf( "%d%d", &ucenik, &ispit );
            --ucenik;

            int gdje = get_slobodna( ispit );
            gdje_sjedi[ ucenik ] = gdje;
            sto_pise[ ucenik ] = ispit;
            printf( "%d\n", gdje );

        } else {

            int ucenik; scanf( "%d", &ucenik ); --ucenik;
            oslobodi_mjesto( gdje_sjedi[ ucenik ], sto_pise[ ucenik ] );

        }

    }

return 0;
}
