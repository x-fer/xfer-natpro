#include <stdio.h>
#include <stdlib.h>
#include <vector>

#define N 10003

struct izborna_jedinica
{
	int bodovi;
	int cijena;
	izborna_jedinica (int _bod, int _cij): bodovi (_bod), cijena (_cij){}
	izborna_jedinica (void) {}
};

std::vector <int> arr (N, 1e8);
std::vector <izborna_jedinica> IJ;

// Potrebno je primjenjivati 0-1 knapsack samo od tot/2 na manje
// zato sto nas zanima samo najmanja vrijednost za tot/2+1 i dalje
// tj. ne trazi se da pronadjemo najmanju cijenu za svaki broj bodova
int solve (int n, int tot)
{
	for (int i = 0; i < n; ++i)
		for (int j = tot/2; j >= 0; --j)
			if (arr [j] + IJ [i].cijena < arr [j + IJ [i].bodovi])
				arr [j + IJ [i].bodovi] = arr [j] + IJ [i].cijena;
	int M = 1e8;
	for (int i = tot/2+1; i <= tot; ++i)
		if (arr [i] != 0)
			M = std::min (M, arr [i]);
	return M;
}

int main (void)
{
	int n, tot = 0;
	arr [0] = 0;
	scanf ("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		int bod, cij;
		scanf ("%d%d", &bod, &cij);
		IJ.push_back (izborna_jedinica (bod, cij));
		tot += bod;
	}
	int sol = solve (n, tot);
	printf ( "%d\n", sol );
	return 0;
}
