#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

void generate(int n, int k) {

  srand(time(NULL) + (int)&n);

  char symbol[26];
  for( int i = 0; i < 26; ++i ) 
    symbol[i] = 'A' + i;
  
  for( int i = 0; i < 1000; ++i )
    swap(symbol[rand()%26], symbol[rand()%26]);


  printf("%d\n", n);
  for( int i = 0; i < n; ++i ) {
    char row[4];
    for( int j = 0; j < 3; ++j ) 
      row[j] = symbol[rand()%k];
    row[3] = 0;
    printf("%s\n", row);
  }
}

int main(int argc, char **argv) {
  generate(atoi(argv[1]), atoi(argv[2]));

  return 0;
}
