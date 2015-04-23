#include <cstdio>
#include <cassert>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

const int MAXN = 305; // nek ima do 300 rijeci
const int MAXL = 15; // rijeci duljine do 10 nek su...

const int inf = 1000000000;

bool similar(string a, string b) {
  int na = (int)a.size();
  int nb = (int)b.size();

  if (na == nb) { // razlika mora biti u jednom slovu
    int cnt = 0;
    REP(i, na) if (a[i] != b[i]) ++cnt;
    return cnt == 1;
  }

  if (na > nb) {
    swap(na, nb);
    swap(a, b);
  }

  REP(i, nb) // koje slovo izbacim iz dulje
    if (b.substr(0, i) + b.substr(i + 1, (int)b.size() - i - 1) == a)
      return true;

  return false;
}

string s[MAXN];
int adj[MAXN][MAXN];

int main(void)
{
  int N, M;
  cin >> N >> M;

  REP(i, N) cin >> s[i];

  REP(i, N) REP(j, N) {
    if (i == j) adj[i][j] = 0;
    else if (similar(s[i], s[j]))
      adj[i][j] = 1;//, printf("similar %d %d\n", i, j);
    else
      adj[i][j] = inf;
  }

  REP(k, N) REP(i, N) REP(j, N)
    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

  REP(i, M) {
    int a, b;
    cin >> a >> b; a--; b--;
    cout << adj[a][b] << endl;
  }

  return 0;
}
