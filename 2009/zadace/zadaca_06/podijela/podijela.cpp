#include <vector>
#include <iostream>
using namespace std;
  
int main() {
  int n,suma=0; cin >> n;
  vector <int> unos(n);
  for (int i=0;i<n;i++) {
    cin >> unos[i];
    suma += unos[i];
  }
  if (suma&1) { cout << 0 << endl; return 0; }
  suma/=2;
  vector<int> DP(suma+1,0);
  DP[0]=1;
  for (int i=0;i<n;i++)
    for (int j=suma;j>=0;j--)
      if (j+unos[i]<=suma)
        DP[j+unos[i]]= (DP[j+unos[i]]+DP[j])%1000000;
  cout << DP[suma]/2 << endl;
  return 0;
}
