#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>

#define MAXN 100000
#define modulo 1000007
using namespace std;
int N, M;
typedef pair<int, long long> par;
struct trol
{
    int loc;
    par mem [30];
    trol ( int _loc ): loc ( _loc )
    {
        for ( int i = 0; i < 30; ++i ) { mem [i].first = -1; mem [i].second = 0; };
    }
};

vector <trol> trolovi;

void input ( void )
{
    scanf ( "%d%d", &N, &M );
    trolovi.push_back ( 0 );
    for ( int i = 0; i < N; ++i )
    {
        int x;
        scanf ( "%d", &x );
        trolovi.push_back ( x );
    }
}

int dva_na ( int x )
{
    int s = 1;
    for ( int i = 0; i < x; ++i )
        s *= 2;
    return s;
}

par rekurzija ( int curr, int korak )
{
    
    if ( trolovi [curr].mem [korak].first != -1 ) return trolovi [curr].mem [korak];
    trolovi [curr].mem [korak].first = 1;
    int cnt = 0;
    int wrk = curr + 1;
    while ( trolovi [wrk].loc <= trolovi [curr].loc + M / dva_na ( korak )  &&  wrk < trolovi.size () )
    {
        cnt++;
        par tmp = rekurzija ( wrk, korak+1 );
        if ( tmp.first > trolovi [curr].mem [korak].first )
        {
            trolovi [curr].mem [korak].first = tmp.first;
            trolovi [curr].mem [korak].second = tmp.second; 
        }
        else if ( tmp.first == trolovi [curr].mem [korak].first )
        {
            trolovi [curr].mem [korak].second = ( trolovi [curr].mem [korak].second + tmp.second ) % modulo;
        }
        ++wrk;
    }
    if ( cnt == 0 ) trolovi [curr].mem [korak].second = 1;
    else trolovi [curr].mem [korak].first ++;
    return trolovi [curr].mem [korak];
}

int main ( void )
{
    input ();
    par sol = rekurzija ( 0, 0 );
    printf ( "%d %d\n", sol.first-1, sol.second );
    return 0;
}
