#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 500008;
const int BASE = 3407;

int n;
char a[MAXN];

long long pot[MAXN];
long long hash[MAXN];

long long hash_query(int a, int b) {
    if (a == 0) {
	return hash[b];
    }
    return hash[b] - hash[a-1] * pot[b-a+1];
}

int main() {
    scanf("%d", &n);
    scanf("%s", a);

    pot[0] = 1;
    for (int i = 1; i <= n; ++i) {
	pot[i] = pot[i-1] * BASE;
    }

    for (int i = 0; i < n; ++i) {
	long long prev = (i > 0) ? hash[i-1] : 0;
	hash[i] = prev * BASE + a[i]-'a'+1;
    }

    for (int p = 1; p <= n; ++p) {
	int ok = 1;
	long long period_hash = hash_query(0, p-1);
	for (int i = p; i+p-1 < n; i += p) {
	    long long next_hash = hash_query(i, i+p-1);
	    if (next_hash != period_hash) {
		ok = 0;
		break;
	    }
	}
	if (n % p != 0) {
	    long long f_hash = hash_query(0, n%p - 1);
	    long long h = hash_query(n - (n%p), n - 1);
	    if (f_hash != h) {
		ok = 0;
	    }
	}
	if (ok) {
	    printf("%d\n", p);
	    break;
	}
    }

    return 0;
}
