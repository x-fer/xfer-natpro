#include <algorithm>
#include <functional>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

int n;
int a[100011];
int stk[100011], top = 0;

int main() {
  scanf( "%d", &n ); 
  for( int i = 0; i < n; ++i ) 
    scanf( "%d", &a[i] ); 

  int sol = 0;

  stk[top = 0] = n;
  for (int i = n-1; i >= 0; --i) {
    while (top > 0 && a[stk[top]] < a[i]) {
      sol = max(sol, a[i] ^ a[stk[top]]);
      --top;
    }
    stk[++top] = i;
  }

  stk[top = 0] = -1;
  for (int i = 0; i < n; ++i) {
    while (top > 0 && a[stk[top]] < a[i]) {
      sol = max(sol, a[i] ^ a[stk[top]]);
      --top;
    }
    stk[++top] = i;
  }
  

  printf("%d\n", sol);
  return 0;
}