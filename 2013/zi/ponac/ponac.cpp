#include <cstdio>
#include <vector>
using namespace std;

typedef long long llint;

const int dx[8] = {-2,-1,1,2,2,1,-1,-2};
const int dy[8] = {1,2,2,1,-1,-2,-2,-1};

const int mod = 1000007;
const int maxn = 64;

// slozenost log K * O^3 .. O^3 ~ 100000, gdje je O velicina matrice
// N je 50.
// K je 100.

int N; // broj polja , NxN je ploca. N <= 7
int K; // broj koraka, K < 1e9

struct matrica {
  vector< vector<llint> > a;
  int n;

  explicit matrica(int n) : a(n, vector<llint>(n, 0)), n(n) { }

  matrica operator* (const matrica &rhs) const {
    matrica sol(n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        for (int k = 0; k < n; ++k) {
          sol.a[i][j]
            = (sol.a[i][j] + (a[i][k] * rhs.a[k][j]) % mod) % mod;
        }
      }
    }
    return sol;
  }
};

matrica jedan(int n) {
  matrica sol(n);
  for (int i = 0; i < n; ++i)
    sol.a[i][i] = 1;
  return sol;
}

matrica power(matrica b, int pot) {
  matrica sol = jedan(b.n);
  for (;pot; pot/=2) {
    if (pot & 1) sol = sol * b;
    b = b * b;
  }
  return sol;
}

int id(int x, int y) {
  return x * N + y;
}

matrica build() {
  matrica ret(N*N);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int sm = 0; sm < 8; ++sm) {
        int ii = i + dx[sm], jj = j + dy[sm];
        if (ii < 0 || ii >= N) continue;
        if (jj < 0 || jj >= N) continue;
        ret.a[ id(i,j) ][ id(ii, jj) ]++;
      }
    }
  }
  return ret;
}

int main() {
  scanf("%d%d", &N, &K);
  printf("%lld\n", power(build(), K).a[0][0]);
  return 0;
}
