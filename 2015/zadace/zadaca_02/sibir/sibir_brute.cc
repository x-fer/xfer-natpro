#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long int lld;

#define MAX_CARGO (1000000000ll)
#define MAX_NUM (1000000)

lld niz[MAX_NUM+1] = {0};

void ukrcaj(lld I, lld M)
{
	niz[I] = min(MAX_CARGO, niz[I] + M);
}


void iskrcaj(lld I, lld M)
{
	niz[I] = max(0ll, niz[I] - M);
}

void provjera(lld Q, lld W)
{
	lld rez = 0;
	
	for(lld i = Q ; i <= W ; ++i)
		rez += niz[i];
	
	printf("%lld\n", rez);
}

void do_command(char *command, lld A, lld B)
{	
	if (strcmp(command, "posadka") == 0)
		ukrcaj(A, B);
	else if (strcmp(command, "razgruzka") == 0)
		iskrcaj(A, B);
	else if (strcmp(command, "kontora") == 0)
		provjera(A, B);
}	

int main(void)
{
	lld N, K, A, B;
	char command[10];

	scanf("%lld", &N);
	scanf("%lld", &K);

	for(lld i = 0 ; i < K ; ++i)
	{
		scanf("%s %lld %lld", command, &A, &B);
		do_command(command, A, B);
	}
	
	return 0;
}
