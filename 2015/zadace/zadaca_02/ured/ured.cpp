#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

#define MAXN 250000

typedef long long int lint;

const lint inf = 1000000000000000001ll;
lint tree[MAXN];
lint offset;

void insert(lint pos, lint v) {
  pos += offset;
  tree[pos] = v;
  
  for (lint x = pos / 2; x > 0; x /= 2) {
    tree[x] = min(tree[2 * x], tree[2 * x + 1]);  
  }
}

lint query(lint lo, lint hi, lint query_lo, lint query_hi, lint pos) {
  if (lo >= query_hi || hi <= query_lo)
    return inf;
  else if (lo >= query_lo && hi <= query_hi)
    return tree[pos];
  
  lint ret = inf;
  ret = min(ret, query(lo, (lo + hi) / 2, query_lo, query_hi, pos * 2));
  ret = min(ret, query((lo + hi) / 2, hi, query_lo, query_hi, pos * 2 + 1));
  return ret;
}

int main(void) {
  lint n, k;
  scanf ("%lld", &n);
  
  offset = 1;
  while (offset < n)
    offset *= 2;
  
  memset(tree, 0x3f, sizeof tree);
  for (lint i = 0; i < n; ++i) {
    lint v;
    scanf("%lld", &v);
    
    insert(i, v);
  }
  
  scanf("%lld", &k);
  for (lint i = 0; i < k; ++i) {
    char command[20];
    scanf("%s", command);
    if (strcmp(command, "sef") == 0) {
      lint a, b;
      scanf("%lld%lld", &a, &b);
      printf("%lld\n", query(0, offset, a - 1, b, 1));  
    } else {
      lint p, v;
      scanf("%lld%lld", &p, &v);
      insert(p - 1, v);  
    }
  }
  
  return 0;  
}
