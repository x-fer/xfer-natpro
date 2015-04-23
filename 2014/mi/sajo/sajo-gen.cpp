#include "testlib.h"
#include <iostream>
#include <cassert>

using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    assert(argc >= 6);
    int n = atoi(argv[1]);
    int v = atoi(argv[2]);
    int maxv = atoi(argv[3]);
    int maxs = atoi(argv[4]);
    
    cout << n << " " << v << endl;
    for (int i = 0; i < n; ++i)
      cout << rnd.next(1, maxv) << " " << rnd.next(1, maxs) << endl;
    return 0;
}
