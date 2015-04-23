#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long int lld;

#define MAX_CARGO (1000000000)
#define MAX_NUM (1000000)

lld loga[MAX_NUM+1] = {0};


void loga_ubaci(lld i, lld M)
{
	for(; i <= MAX_NUM ; i += i&-i)
		loga[i] += M;
}

void loga_izbaci(lld i, lld M)
{
	loga_ubaci(i, -M);
}

lld loga_upit(lld i)
{
	lld ret = 0;
	
	for(;i > 0 ; i -= i&-i)
		ret += loga[i];

	return ret;
}

lld loga_upit(lld a, lld b)
{
	return loga_upit(b) - loga_upit(a-1);
}

void ukrcaj(lld I, lld M)
{
	I += 1;
	lld trenutno = loga_upit(I, I);
	lld kapacitet = MAX_CARGO - trenutno;
	M = min((lld)M, kapacitet);
	loga_ubaci(I, M);
}


void iskrcaj(lld I, lld M)
{
	I += 1;
	lld trenutno = loga_upit(I, I);
	M = min((lld)M, trenutno);
	loga_izbaci(I, M);
}

void provjera(lld Q, lld W)
{
	Q += 1;
	W += 1;
	lld rez = loga_upit(Q, W);
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
