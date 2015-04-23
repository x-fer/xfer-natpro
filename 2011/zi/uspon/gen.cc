#include<cstdio>
#include<cstring>
#include<ctime>
#include<iostream>
#include<set>

using namespace std;

int main(int argc, char **argv)
{
	srand(time(NULL));
	
	int maxV, maxS, maxK;
	int V, S, K, X, Y;
	set<pair<int, int> > koordinate;
	
	
	if ( argc < 5 ) 
	{	
		printf("Ime testa, V, S, K\n");
		exit( 1 );
	}
	sscanf(argv[2], "%d", &maxV);
	sscanf(argv[3], "%d", &maxS);
	sscanf(argv[4], "%d", &maxK);
	
	
	FILE *f = fopen(argv[1], "w");
	
	V = rand() % maxV + 1;
	S = rand() % maxS + 1;
	K = rand() % maxK + 1;
	
	fprintf(f, "%d %d\n", V, S);
	fprintf(f, "%d\n", K);
	
	for(int i = 0 ; i < K ; ++i)
	{
		do
		{
			X = rand() % S;
			Y = rand() % V;
		}while( koordinate.find( make_pair(X, Y) ) != koordinate.end()  );
		fprintf(f, "%d %d\n", X, Y);
	}

	fclose(f);
	
	return 0;
}
