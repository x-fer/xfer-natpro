#include <cstdio>
#include <map>
#include <string>
using namespace std;
#define FORC(it, C) for(__typeof((C).begin()) it = (C).begin(); it != (C).end(); ++it) 

const int MAXL   = 110;
const int MOD    = 124823;
const int FAKTOR = 41;

char buff[MAXL];
int n;
map< string, int > tablica[MOD];

void clean_up(char *S) {
  for (int i = 0; S[i]; ++i) {
    if (S[i] >= 'A' && S[i] <= 'Z')
      S[i] += 'a' - 'A';
  }
}

int get_hash(char *S) {
  int res = 0;
  for (int i = 0; S[i]; ++i) {
    res = ( res * FAKTOR + S[i] ) % MOD;
  }
  return res;
}

int main(void) {
  scanf("%d", &n); 
  for (int i = 0; i < n; ++i) {
    scanf(" %s", buff);
    clean_up(buff);
    ++tablica[get_hash(buff)][buff];
  }

  int cnt = 0;
  for (int i = 0; i < MOD; ++i)  {
    FORC (it, tablica[i]) {
      cnt += ((it->second) & 1)*(it->second);
    }
  }

  printf("%d\n", n-cnt);
  
  return 0;
}

