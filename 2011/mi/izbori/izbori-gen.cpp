#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main (void)
{
	int n, a, b, A, B;
	srand ((unsigned) time (NULL));
	scanf ("%d%d%d%d%d", &n, &a, &b, &A, &B);
	printf ("%d\n", n);
	for (int i = 0; i < n; ++i)
		printf ("%d %d\n", rand()%(b-a)+a, rand()%(B-A)+A);
	return 0;
}
