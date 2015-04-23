#include <cstdio>
#include <ctime>
#include <algorithm>

using namespace std;

int n, q;
const int mx = 1e6;

int main(){
  srand( time(0) );

  scanf( "%d %d", &n, &q );
  int x = rand() % mx + 1;
  printf( "%d %d %d\n", n, q, x );

  for( int i = 0; i < q; i++ ){
    char tip = 'P';
    int A, B;
    if( rand()%3 ) tip = 'I';

    if( tip == 'I' ){
      A = rand() % n + 1; A = 1;
      B = rand() % n + 1;
      if( A > B ) swap(A,B);
      if( A == B ){
	if( A == 1 ) B++;
	else A--;
      }
    } else{
      A = rand() % n + 1;
      B = rand() % mx + 1;
    }

    printf( "%c %d %d\n", tip, A, B );
  }

  return 0;
}
