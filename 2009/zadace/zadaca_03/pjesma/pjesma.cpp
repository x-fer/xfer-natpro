/*
  Natjecateljsko programiranje
  3. Domaca zadaca
  Zadatak PJESMA

  autor rjesenja: Ivo Sluganovic 

  
  Primjetimo da svako potencijalno rjesenje zadovoljava uvjet monotonosti:
  ako mozemo poceti slusati pjesmu u trenutku T, sigurno ju mozemo poceti slusati i u svakom kasnijem trenutku.

  Prema tome, binarnim pretrazivanjem mozemo naci najmanji takav trenutak, pod uvjetom da znamo provjeriti 
  smijemo li pjesmu poceti slusati u trenutku T.
*/

#include <cstdio>
const int MAXN = 100000;

int trajanje[MAXN], skidanje[MAXN];
int n;

bool moze( int poc )
{
  /*
    Potrebno je provjeriti hocemo li u svakom trenutku imati "sto slusati".
    To radimo tako da pamtimo dva vremena: trenutak u kojem krecemo slusati i-tu pjesmu i
    trenutak u kojem pocinjemo skidati i-tu pjesmu.
    Da bismo i-ti dio "uspjesno" mogli odslusati, moramo ga prvo skinuti.
    Ako uvijek imamo "sto slusati", tada je trenutak u kojem smo krenuli slusati sigurno dovoljno kasno.
  */

  int pocslu = poc; // trenutak u kom krecemo slusati i-tu pjesmu
  int pocski = 0;   // trenutak u kom krecemo skidati i-tu pjesmu
  for( int i = 0; i < n; ++i ) 
    if ( pocski + skidanje[i] > pocslu )
      return false;
    else {
      pocski += skidanje[i];
      pocslu += trajanje[i];
    }
  return true;
}

int main()
{
  scanf( "%d", &n );
  for( int i = 0; i < n; ++i )
    scanf( "%d%d", &trajanje[i], &skidanje[i] );

  int l = 0, u = 1000000000;
  for( ; l < u; ) {
    int m = ( l + u ) / 2;
    
    if ( moze( m ) )
      u = m;
    else
      l = m + 1;
  }
  printf( "%d\n", l );
  return 0;
}
