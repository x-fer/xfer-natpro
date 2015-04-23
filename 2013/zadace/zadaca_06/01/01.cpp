#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define MAXN 20003

int bio[MAXN];
int bit[MAXN];
int parent[MAXN];
int c = 0, n, k;
queue<int> q;

int main() {
  scanf("%d", &n);
  c++;
  while(!q.empty()) q.pop();
  if(n == 1) {
    printf("1\n");
  } else { 

    memset(parent, 0, sizeof parent);
    q.push(1);
    bit[1] = 1;
    bio[1] = c;
    while(!q.empty()) {
      int cur = q.front();
      q.pop();

      int a = (10 * cur) % n;
      int b = (a + 1) % n;

      if(bio[a] != c) {
	bio[a] = c;
	bit[a] = 0;
	parent[a] = cur;
	q.push(a);
      }

      if(bio[b] != c) {
	bio[b] = c;
	bit[b] = 1;
	parent[b] = cur;
	q.push(b);
      }

      if(!a || !b) break;
    }

    int d = 0;
    string s = "";
    do {
      s += ('0' + bit[d]);
      d = parent[d];
    } while(d != 1 );
    s += ('0' + bit[d]);
    s.assign(s.rbegin(), s.rend());
    printf("%s\n", s.c_str());

  }
  return 0;
}


