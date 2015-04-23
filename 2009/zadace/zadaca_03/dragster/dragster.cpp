/*
  Natjecateljsko programiranje
  3. Domaca zadaca
  Zadatak DRAGSTER

  autor rjesenja: Ivo Sluganovic 

  
  U zadatku se od nas trazi da pronademo udaljenost tocke i duzine.
  To mozemo rijesiti ternarnim pretrazivanjem jer je funkcija udaljenosti "dobra"
  za ternarno pretrazivanje - ima samo jedan lokalni minimum, a bas njega trazimo.

  Zadatak se moze rijesiti i cisto analiticki, racunanjem normale na pravac koji odreduje zadana duzina.
*/

#include <cstdio>
#include <cmath>
using namespace std;

struct pt {
  double x, y;
};

double sqr( double x ) { return x * x; }
double dist( const pt& A, const pt& B )
{
  return sqrt( sqr( A.x - B.x ) + sqr( A.y - B.y ) );
}

int main()
{
  pt K, POC, KRA; scanf( "%lf%lf%lf%lf%lf%lf", &K.x, &K.y, &POC.x, &POC.y, &KRA.x, &KRA.y );
  
  double lo = 0, hi = 1.;
  for( int iter = 50; iter--; ) {
    double a = lo + ( hi - lo ) / 3.;
    double b = lo + ( hi - lo ) / 3. * 2;

    pt A, B;
    
    A.x = POC.x + a * ( KRA.x - POC.x );   // ovo smo "ljepse" mogli rijesiti konstruktorom klase pt
    A.y = POC.y + a * ( KRA.y - POC.y );

    B.x = POC.x + b * ( KRA.x - POC.x );
    B.y = POC.y + b * ( KRA.y - POC.y );

    if ( dist( A, K ) < dist( B, K ) ) // ovdje smo mogli usporedivati i kvadrate udaljenosti (jer je preciznije i brze)
      hi = b;
    else
      lo = a;
  }
  pt SOL;

  SOL.x = POC.x + lo * ( KRA.x - POC.x );
  SOL.y = POC.y + lo * ( KRA.y - POC.y );
  
  printf( "%.2lf\n", dist( K, SOL ) );
  return 0;
}
