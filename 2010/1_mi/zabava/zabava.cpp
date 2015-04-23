#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 100;

int N;
int M[MAXN][MAXN];
pair< int, int > grad[MAXN];

int main(void) 
{
	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		int d; scanf("%d", &d);
		grad[i] = make_pair(d, i);
	}

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			scanf("%d", &M[i][j]);

	for (int k = 0; k < N; ++k)
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j) 
				M[i][j] = min(M[i][j], M[i][k] + M[k][j]);

	sort(grad, grad + N);
	for (int i = N - 1; i >= 0; --i) 
		printf("%d%c", grad[i].second + 1, (i - 1 >= 0) ? ' ' : '\n');

	for (int i = N - 1; i >= 1; --i)
		printf("%d\n", M[grad[i].second][grad[i - 1].second]);
	
	return 0;
}