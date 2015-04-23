
/*
  DMIH 2006 - Prvi dan natjecanja
  Srednjoskolska skupina - I. podskupina
  Zadatak KULE

  Neka se brojevi na ploci nalaze u dvodimenzionalnom polju A[MAX][MAX].
  Za pocetak, izracunajmo sumu svakog retka odnosno svakog stupca u nizove
  Row[MAX] odnosno Col[MAX].

  Oznacimo poziciju kula na ploci s (r1,c1) i (r2,c2). Raspored dviju kula na
  ploci mozemo podijeliti u 3 slucaja:

  A) Kule su u istom retku (r1 = r2)
  B) Kule su u istom stupcu (c1 = c2)
  C) Kule su u razlicitim recima i stupcima

  Slucaj A) rjesavamo tako da odaberemo redak r, te stupce c1 i c2 na sve moguce
  nacine i direktnom formulom provjerimo koji od rasporeda daje maksimalan zbroj.
  Formula ocito glasi:
     Zbroj = Row[r] + Col[c1] + Col[c2] - 2*A[r][c1] - 2*A[r][c2]

  Slucaj B) rjesavamo analogno, a formula glasi:
     Zbroj = Col[c] + Row[r1] + Row[r2] - 2*A[r1][c] - 2*A[r2][c]

  Slucaj C) je nesto kompliciraniji.
  Promotrimo prvo kako bi glasila formula za zbroj kada bi znali konacan raspored
  dviju kula:
     Zbroj = Row[r1] + Row[r2] +                   (1)
           + Col[c1] - A[r2][c1] - 2*A[r1][c1] +   (2)
           + Col[c2] - A[r1][c2] - 2*A[r2][c2]     (3)

  (U daljnjem tekstu spominjemo dijelove formule po recima kako je gore oznaceno)

  Prvi redak formule je doprinos koji daju dva odabrana retka r1 i r2.
  Drugi redak formule je doprinos koji daje stupac u kojem se nalazi prva kula.
  Treci redak formule je doprinos koji daje stupac u kojem se nalazi druga kula.

  Primjetite da je polja (r1,c1) i (r2,c2) u svim formulama potrebno dva puta
  oduzeti jer se polja na kojima se nalaze kule ne smije ubrojiti u ukupni zbroj,
  a vec su dvaput ubrojani kroz sume Row[r1], Row[r2], Col[c1] i Col[c2].

  Odaberimo retke r1 i r2 na sve moguce nacine.
  Kako se stupac c1 u formuli pojavljuje samo u 2. retku ocito za c1 trebamo
  odabrati stupac koji maksimizira (2).
  Isto vrijedi za c2 - trebamo odabrati stupac c2 koji maksimizira (3) s tim da
  moramo uzet u obzir da c2 ne smije biti jednak c1.

  Iz gornjeg slijedi algoritam:
  Za svaki r1 od 1 do n
    Za svaki r2 od 1 do n
      Ako r1 != r2
        Odaberi c1 tako da je Col[c1] - A[r2][c1] - 2*A[r1][c1] maksimalno
        Odaberi c2!=c1 tako da je Col[c2] - A[r1][c2] - 2*A[r2][c2] maksimalno

        Provjeri je li pozicija (r1,c1) i (r2,c2) najbolja dosada

  Na prvi pogled moze se ciniti da gornji algoritam nije valjan u slucajevima
  kada kulu u retku r1 (koja ima prioritet u biranju stupca) stavimo u stupac
  gdje bi kula u retku r2 trebala biti da bi suma bila maksimalna, no i taj
  slucaj ce biti isproban u kada r1 i r2 zamijene vrijednosti jer ce tada druga
  kula imati prioritet u biranju stupca.

  Vremenska slozenost je za sva tri slucaja jednaka O(n^3).
*/

#include <cstdio>

#define MAX 300

int n;
int A[MAX][MAX];
int Row[MAX];
int Col[MAX];

const int inf = 1000000000;

int main( void ) {
   scanf( "%d", &n );
   for( int i = 0; i < n; ++i )
      for( int j = 0; j < n; ++j ) {
         scanf( "%d", &A[i][j] );
         Row[i] += A[i][j];
         Col[j] += A[i][j];
      }

   int Rjesenje = 0;

   // Slucaj A)
   for( int r = 0; r < n; ++r )
      for( int c1 = 0; c1 < n; ++c1 )
         for( int c2 = c1+1; c2 < n; ++c2 )
            Rjesenje >?= Row[r] + Col[c1] + Col[c2] - 2*A[r][c1] - 2*A[r][c2];

   // Slucaj B)
   for( int c = 0; c < n; ++c )
      for( int r1 = 0; r1 < n; ++r1 )
         for( int r2 = r1+1; r2 < n; ++r2 )
            Rjesenje >?= Col[c] + Row[r1] + Row[r2] - 2*A[r1][c] - 2*A[r2][c];

   // Slucaj C)
   for( int r1 = 0; r1 < n; ++r1 )
      for( int r2 = 0; r2 < n; ++r2 ) {
         if( r1 == r2 ) continue;

         int c1 = -1, max1 = -inf;
         for( int c = 0; c < n; ++c ) {
            int val = Col[c] - A[r2][c] - 2*A[r1][c];
            if( val > max1 ) { max1 = val; c1 = c; }
         }

         int c2 = -1, max2 = -inf;
         for( int c = 0; c < n; ++c ) {
            int val = Col[c] - A[r1][c] - 2*A[r2][c];
            if( c != c1 && val > max2 ) { max2 = val; c2 = c; }
         }

         Rjesenje >?= Row[r1] + Row[r2]
                    + Col[c1] - A[r2][c1] - 2*A[r1][c1]
                    + Col[c2] - A[r1][c2] - 2*A[r2][c2];
      }

   printf( "%d\n", Rjesenje );

   return 0;
}
