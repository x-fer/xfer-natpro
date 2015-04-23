#include <cstdio>

using namespace std;

#define MAXI 1000002

typedef long long int lint;

lint loga[MAXI] = {0};

void add(int i, int val)
{
	for(; i<MAXI ; i+=i&-i)
		loga[i] ^= val; 
}

lint query(int i)
{
	lint ret = 0;

	for(; i > 0 ; i-=i&-i)
		ret ^= loga[i];

	return ret;
}

lint query(int A, int B)
{
	return query(A-1)^query(B);
}

int main(void)
{
	int N, M, poz, A, B;
	lint key;
	char c[2];

	scanf("%d", &N);
	scanf("%d", &M);

	for(int i = 0 ; i < M ; ++i)
	{
		scanf("%s", c);
		
		if ( c[0] == 'F' )
		{
			scanf("%d %d", &A, &B);
			printf("%lld\n", query(A,B));
		}
		else
		{
			scanf("%d %lld", &poz, &key);
			add(poz, key);
		}
	}
}
