#include <cstdio>
#include <algorithm>
#include <ctime>

const int MAXN = 100;
const int MAXD = 1000;
const int MAXC = 1000;

int N;
int M[MAXN][MAXN];

int main(void) 
{
	srand(unsigned(time(NULL)));
	
	scanf("%d", &N);
	printf("%d\n", N);

	for (int i = 0; i < N; ++i) {
		int D = (rand() % MAXD) + 1;
		printf("%d%c", D, (i + 1 < N) ? ' ' : '\n');
	}

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < i; ++j) 
			M[i][j] = (rand() % MAXC) + 1;

	for (int i = 0; i < N; ++i)
		for (int j = N - 1; j > i; --j) M[i][j] = M[j][i]; 
	
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) 
			printf("%d%c", M[i][j], (j + 1 < N) ? ' ' : '\n');
	
	return 0;
}