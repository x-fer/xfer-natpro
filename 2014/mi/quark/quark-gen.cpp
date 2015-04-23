#include <cstdio>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

vector<int> a, p;

int main(void){
  srand(time(0));

  int n = rand() % 1000 + 1;
  int total = 0;
  for (int i=0; i<n; i++){
    int Ai = rand(); a.push_back(Ai);
    int Pi = rand() % 1000; p.push_back(Pi);
    total += Pi;
  }

  int k = ((long long)rand()*rand()) % total + 1;

  printf ("%d %d\n", n, k);
  for (int i=0; i<n; i++)
    printf ("%d %d\n", a[i], p[i]);

  return 0;
}
