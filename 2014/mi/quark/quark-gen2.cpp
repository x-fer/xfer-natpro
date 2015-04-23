// nemojte ovo vrtiti pod linuxom, cini mi se moguc overflow na 22 i 27 i 32
#include <cstdio>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

typedef long long llint;

vector<llint> a, p;

int main(void){
  srand(time(0));

  int n; scanf ("%d", &n);
  llint sumP; scanf ("%lld", &sumP);
  llint MOD = sumP / n;
  llint total = 0;
  for (int i=0; i<n; i++){
    llint Ai = 0;
    while(Ai <= 0)
      Ai = ((llint)(rand()) * rand() * rand() * rand()) % MOD;
    a.push_back(Ai);

    llint Pi = 0;
    while(Pi <= 0)
      Pi = ((llint)(rand()) * rand() * rand() * rand()) % MOD;
    p.push_back(Pi);
    total += Pi;
  }

  llint k = ((llint)rand()*rand()*rand()*rand()) % total + 1;

  printf ("%d %lld\n", n, k);
  for (int i=0; i<n; i++)
    printf ("%lld %lld\n", a[i], p[i]);

  return 0;
}
