#include <stdio.h>
#include <stdlib.h>

int K [10];
int N, M, max;
int mem [1<<20];

void input (void)
{
	scanf ("%d%d", &N, &M);
	for (int i = 0; i < M; ++i)
	{
		scanf ("%d", &K [i]);
		if (max < K [i])
			max = K [i];
	}
	for (int i = 1; i <= max; ++i)
		scanf ("%d", &mem [i]);
}

int f (int n)
{
	if (n <= max)
		return mem [n];
	if (mem [n] != 0)
		return mem [n];
	int sum = 0;
	for (int i = 0; i < M; ++i)
		sum = (sum + f (n - K [i])) % 10000007;
	mem [n] = sum;
	return sum;
}

int main (void)
{
	input ();
	printf ("%d\n", f (N));
	return 0;
}
