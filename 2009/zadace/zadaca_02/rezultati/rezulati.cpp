/*
  Natjecateljsko programiranje
  2. Domaca zadaca
  Zadatak REZULTATI

  autor rjesenja: Ivo Sluganovic


  Bitno je primjetiti da mijenjanjem poretka timova ne mijenjamo rezultat.
  Vrlo cesto je u takvim slucajevima korisno podatke poredati po nekom kriteriju, jer nam to olaksava rjesavanje.
  U ovom slucaju, nakon sortiranja uzlazno mozemo binarnim pretrazivanjem pronaci prvi rezultat koji je veci ili jednak broju X.
  Trazeno rjesenje dobivamo tako da od ukupnog broja timova oduzmemo indeks prvog veceg ili jednakog rezultata.
*/

#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 100000;

int A[MAXN];

int main()
{
  int n, q; scanf( "%d%d", &n, &q );
  for( int i = 0; i < n; ++i )
    scanf( "%d", &A[i] );

  A[n++] = 1001; // dodajem stozerni element, kako bi uvijek postojao tim s boljim rezultatom
  sort( A, A + n );

  // trazim najmanji rezultat koji je veci ili jednak od X
  // rjesenje je broj timova - indeks nadenog

  for( ; q--; ) {
    int x; scanf( "%d", &x );

    int l = 0, u = n - 1;
    for( ; l < u; ) {
      int m = ( l + u ) / 2;

      if ( A[m] >= x ) // ako je A[m] veci ili jednak od X, tada se rjesenje sigurno ne nalazi "desno"
	u = m;
      else
	l = m + 1; // u ovom slucaju, ni A[m] nije kandidat za rjesenje jer je manji od X
    }

    printf( "%d\n", n - l - 1 );
  }
  return 0;
}
