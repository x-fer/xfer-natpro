#include <algorithm>
#include <functional>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <vector>
#include <string>

using namespace std;

const int MAXN = 30;

int n;
int X;

double A[ MAXN ];

int main( void )
{
    scanf( "%d", &n );
    for( int i = 0; i < n; ++i ) 
        scanf( "%lf", &A[i] );
    scanf( "%d", &X );

    double dolje;
    double gore;

    {
        double l = 1, r = 1000000.;

        for( int preciznost = 0; preciznost < 100; ++preciznost ) {
            double mid = ( l + r ) / 2;

            double sum = 0;
            for( int i = 0; i < n; ++i )
                sum = floor( ( sum + A[i] ) * mid );

            if( sum < X ) l = mid;
            else r = mid;
        }

        printf( "%.9lf ", dolje = l - 1 );
    }

    {
        double l = 1, r = 1000000.;

        for( int preciznost = 0; preciznost < 100; ++preciznost ) {
            double mid = ( l + r ) / 2;

            double sum = 0;
            for( int i = 0; i < n; ++i )
                sum = floor( ( sum + A[i] ) * mid );

            if( sum > X ) r = mid;
            else l = mid;
        }

        printf( "%.9lf", gore = l - 1 );
    }

    printf( " -> apsolutna razlika = %g\n", gore-dolje );

    return (0-0);
}
