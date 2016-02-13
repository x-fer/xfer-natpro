#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 100100;
const int P = 9937;
const int mod1 = 1e9 + 7;

int h1[MAXN];

bool in[MAXN]; // je li trenutno unutra
vector<pair<int, int>> e; // events

int main(void) {
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    e.push_back({a, i});
    e.push_back({b, i});
    e.push_back({c, i});
    e.push_back({d, i});
  }

  h1[0] = 1;
  for (int i = 1; i < N; ++i) {
    h1[i] = (h1[i-1] * 1LL * P) % mod1;
  }

  sort(e.begin(), e.end());
  vector<int> subsets; 
  subsets.push_back(0);// prazan podskup koji cemo kasnije oduzeti

  int cur1 = 0; // hash trenutnog podskupa
  for (auto& p: e) {
    if (in[p.second]) {
      in[p.second] = false;
      cur1 = (cur1 - h1[p.second] + mod1) % mod1;
    } else {
      in[p.second] = true;
      cur1 = (cur1 + h1[p.second]) % mod1;
    }
    subsets.push_back(cur1);
  }

  sort(subsets.begin(), subsets.end());
  subsets.erase(unique(subsets.begin(), subsets.end()), subsets.end());
  printf("%d\n", (int)subsets.size() - 1);
  return 0;
}
