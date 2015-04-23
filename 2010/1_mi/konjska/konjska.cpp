#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct node{ 
  int mx1, mx2; //svaki cvor pamti dva najveca u svome podstablu

  node(){ mx1 = mx2 = 0; }
  node( int val_ ){ mx1 = val_; mx2 = 0; }

  int sum(){ return mx1+mx2; }

  node friend operator +( const node &a, const node &b ){
    node ret;
    ret.mx1 = max(a.mx1,b.mx1);

    if( a.mx1 > b.mx1 ) ret.mx2 = max(a.mx2,b.mx1);
    else ret.mx2 = max(a.mx1,b.mx2);

    return ret;
  }
};

struct tournament{
  vector <node> data;
  int size; //prva potencija broja 2 koja je veca ili jednaka stvarnom broju elemenata

  tournament(){ size = 1; }
  tournament( vector <int> niz ){ //inicijalizacija tournamenta na pocetni niz, rekurzivno
    for( size = 1; size < (int)niz.size(); size *= 2 ); //inicijalizacija size-a
    for( ; (int)niz.size() < size; niz.push_back(0) ); //prosirivanje niza do size
    data.resize(2*size);
    init(1,0,size,niz);
  }

  void init( int i, int lo, int hi, vector <int> &niz ){ //i je indeks cvora u kojem se nalazim, [lo,hi> intervali koji on pamti u originalnom nizu, &niz je referenca na niz
    if( hi - lo == 1 ){ //kada dodejm do listova u stablu (nemaju djece)
      data[i] = node(niz[lo]);
      return;
    }

    init(2*i,lo,(lo+hi)/2, niz); init(2*i+1,(lo+hi)/2, hi, niz);
    data[i] = data[2*i] + data[2*i+1];
  }

  node rek( int i, int lo, int hi, int A, int B ){ //[A,B> interval u kojem trazimo dva najveca, i,lo,hi identicno kao u init-u
    if( lo >= B || hi <= A ) //ako ovo podstablo prati interval koji je u potpunosti izvan [A,B>
      return node(); //ne utjece na rezultat
    if( lo >= A && hi <= B ) //ako je podstablo u potpunosti unutar trazenog intervala [A,B>
      return data[i];

    //inace se rekuzivno sirim
    return rek( 2*i, lo, (lo+hi)/2, A, B ) + rek( 2*i+1, (lo+hi)/2, hi, A, B );
  }

  void set( int i, int val ){
    i += size;
    data[i] = node(val);
    for( i /= 2; i > 0; i /= 2 ) data[i] = data[2*i] + data[2*i+1];
  }

};

int main(){
  int n, q;
  scanf( "%d %d", &n, &q );
  vector <int> niz;
  for( int i = 0; i < n; i++ ){
    int x;
    scanf( "%d", &x );
    niz.push_back(x);
  }

  tournament konji(niz);
  for( int i = 0; i < q; i++ ){
    char op[5];
    int A, B;
    scanf( "%s %d %d", op, &A, &B );
    
    if( op[0] == 'I' ) printf( "%d\n", konji.rek(1,0,konji.size,A-1,B).sum() );
    else konji.set(A-1,B);
  }

  return 0;
}
