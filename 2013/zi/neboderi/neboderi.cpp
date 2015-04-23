#include <cstdio>
#include <algorithm>
#include <cassert>
#include <cstring>

using namespace std;

const int MAXN = 500100;
const int MAXM = 1000100;
const int MOD = 1000000007;

struct bridge {
	int start, height, dir;
	bridge(int _start = 0, int _height = 0, int _dir = 0):
		start(_start), height(_height), dir(_dir) {}
};

bool cmp(bridge a, bridge b) {
	if(a.height != b.height) return a.height < b.height;
	if(a.dir != b.dir) return a.dir < b.dir;
	if(a.dir == 0) return a.start > b.start;
	return a.start < b.start;
}

int n, m, s;
int dp[MAXN];
bridge B[MAXM];

int main(void) {

	scanf("%d%d%d", &n, &m, &s);
	for(int i = 1; i <= n; ++i)
		scanf("%*d");

	for(int i = 0; i < m; ++i) {
		int v, z, s; scanf("%d%d%d", &v, &z, &s);
		B[i] = bridge(z, v, s);
	}

	sort(B, B + m, cmp);

	dp[s] = 1;

	for(int i = 0; i < m; ++i) {
		if(i != 0) { 
			assert(cmp(B[i], B[i - 1]) || cmp(B[i - 1], B[i]));
		}
		if(B[i].dir == 0) 
			dp[B[i].start - 1] = (dp[B[i].start - 1] + dp[B[i].start]) % MOD;
		else
			dp[B[i].start + 1] = (dp[B[i].start + 1] + dp[B[i].start]) % MOD;
	}

	for(int i = 1; i <= n; ++i) printf("%d\n", dp[i]);

	return 0;

}
