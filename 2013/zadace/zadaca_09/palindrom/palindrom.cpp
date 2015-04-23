#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;
const int MAX = 100010;
const int p = 113;

int Hn[ MAX ], Hr[ MAX ], P[ MAX ];
char word[ MAX ];
int N;

inline void init( void )
{
	P[0] = 1;
	Hn[0] = word[0];
	Hr[0] = word[ N - 1 ];

	for (int i = 1; i < N; i++) {
		P[i] = P[i - 1] * p;
		Hn[i] = Hn[i - 1]*p + word[i];
		Hr[i] = Hr[i - 1]*p + word[ N - i - 1 ];
	}
	
	return;
}

int get_hash(int *H, int i, int j )
{
	int ret = H[j];
	if ( i ) {
		ret -= H[i - 1] * P[ j - i + 1 ];
	}
	return ret;
}

int normal_hash(int i, int j)
{
	return get_hash( Hn, i, j );
}

int reverse_hash(int i, int j)
{
	return get_hash( Hr, N - j - 1, N - i - 1 );
}


int parni( int i )
{
	int lo = 0, hi = min( i + 1, N - i ), mid;

	while (lo < hi) {
		mid = ( lo + hi + 1 ) >> 1;
		
		if ( normal_hash( i - mid + 1, i + mid ) == reverse_hash( i - mid + 1, i + mid  ) ) {
			lo = mid;
		} else {
			hi = mid - 1;
		}
	}

	return lo << 1;
}

int neparni( int i )
{
	int lo = 0, hi = min( i, N - i - 1 ), mid;

	while (lo < hi) {
		mid = (lo + hi + 1) >> 1;

		if ( normal_hash( i - mid, i + mid ) == reverse_hash( i - mid, i + mid ) ) {
			lo = mid;
		} else {
			hi = mid - 1;
		}
	}

	return (lo << 1) + 1;
}

int main(int argc, const char *argv[])
{
	scanf( "%d", &N );	scanf( "%s", word );

	init( );
	
	int sol = 0;

	for (int i = 0; i < N - 1; i++) {
		sol = max( sol, parni( i ) );
	}
	

	for (int i = 0; i < N; i++) {
		sol = max( sol, neparni( i ) );
//		printf("%c %d\n", word[i], neparni(i));
	}

	printf("%d\n", sol);
	return 0;
}
