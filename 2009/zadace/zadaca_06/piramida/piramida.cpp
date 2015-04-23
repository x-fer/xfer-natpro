#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n; cin >> n;
  vector<vector<int> > unos(n);
  for (int i=0;i<n;i++)
    unos[i].insert(unos[i].begin(),i+1,0);
  vector<vector<int> > DP;
  DP=unos;
  for (int i=0;i<n;i++)
    for (int j=0;j<=i;j++)
      cin >> unos[i][j];
  
  DP[0][0]=unos[0][0]; // inicijalno stanje
  for (int i=1;i<n;i++) // krecemo od drugog retka
    for (int j=0;j<=i;j++) {
      if (j-1>=0 && DP[i-1][j-1]+unos[i][j] > DP[i][j])
        DP[i][j] = DP[i-1][j-1]+unos[i][j];
      if (j<i && DP[i-1][j]+unos[i][j] > DP[i][j])
        DP[i][j] = DP[i-1][j]+unos[i][j];
    }

  int rj=0;
  for (int i=1;i<n;i++)
    if (DP[n-1][i] > rj) rj=DP[n-1][i];
  cout << rj << endl;
  return 0;
}
