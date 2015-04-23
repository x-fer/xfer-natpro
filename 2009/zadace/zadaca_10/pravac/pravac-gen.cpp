#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>
#include <iostream>

using namespace std;


set< pair<int,int> > ubacene;

int main(int argc, char* argv[]) {
  int n, maxx, maxy, nx, ny;
  pair<int,int> tmp;

  n = atoi(argv[1]);
  maxx = atoi(argv[2]);
  maxy = atoi(argv[3]);
  
  srand(time(0)+n-maxx+maxy);

  printf("%d\n", n);
  for(int i = 0; i < n; ++i) {
    do {
      nx = rand()%maxx+1;
      ny = rand()%maxy+1;
      tmp = make_pair(nx,ny);
    } while( ubacene.find(tmp) != ubacene.end() );
    
    printf("%d %d\n", nx, ny);
    ubacene.insert(tmp);
  }
  
  return 0;
}
