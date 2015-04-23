#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define MAX 100010
typedef long long ll;

int n, k;
vector<int> prime;
int pom[MAX + 10];
void fill_prime() {
  for(int i = 2; i <= n; ++i)
    pom[i] = 1;
  for(int i = 2; i <= n; ++i)
    if(pom[i])
      for(ll j =  ((ll) i) * i; j <= n; j += i)
	pom[j] = 0;

  for(int i = 2; i <= n; ++i)
    if(pom[i]) prime.push_back(i);
}

int main() {
  scanf("%d %d", &n, &k);
  fill_prime();
  ll ret = 0;

  int ps = prime.size();
  if(!k) {
    for(int i = 0; i < ps - 1; ++i) {
      ll d = prime[i + 1] - prime[i] - 1;
      ret += d + d * (d - 1) / 2; 
    }
    ret +=  (((ll) n) - prime[ps - 1]) * (((ll) n) - prime[ps - 1] - 1) / 2 + n - prime[ps - 1];
    k++;
  }

  for(int i = 0; i + k - 1 < ps ; ++i) {
    ll left = 1;
    if(i) {
      left += prime[i] - prime[i - 1] - 1;
    }
    ll right = n - prime[i + k - 1] + 1;
    ret += left * right;
  }

  printf("%lld\n", ret);
  return 0;
}

