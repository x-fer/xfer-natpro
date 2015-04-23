#include <iostream>

using namespace std;

typedef long long llint;

int main( void ) {
    llint N, A, B, C, D;
    cin >> N;
    cin >> A >> B;
    cin >> C >> D;

    llint v = (C-D+N)%N;
    llint d = (B-A)%N;

    if( v == 0 ) {
        cout << "oo" << endl;
        return 0;
    }

    llint r1 = v, x1 = 1, y1 = 0;
    llint r2 = N, x2 = 0, y2 = 0;

    while( r2 != 0 ) {
        llint q = r1 / r2;
        llint r3 = r1 - q*r2;
        llint x3 = x1 - q*x2;
        llint y3 = y1 - q*y2;

        r1 = r2; x1 = x2; y1 = y2;
        r2 = r3; x2 = x3; y2 = y3;
    }

    if( d%r1 != 0 ) {
        cout << "oo" << endl;
        return 0;
    } else {
        x1 *= d / r1;
        llint ciklus = N / r1;
        llint k = x1 / ciklus;
        x1 -= k*ciklus;
        while( x1 <= 0 ) x1 += ciklus;
        cout << x1 << endl;
    }

    return 0;
}

