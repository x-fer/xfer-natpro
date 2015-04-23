#include <cstdio>
#include <cassert>
#include <ctime>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair< int, int > par;

const int MAXM = 100000;

set< par > pts;
vector< par > ret;

vector< int > to_x;
vector< int > to_y;

set< int > seenx;
set< int > seeny;

int main(int argc, char *argv[]) 
{
  int N = atoi(argv[1]);
  int M = atoi(argv[2]);

  assert(M <= MAXM);
  srand(unsigned(time(NULL)));

  for (int i = 0; i < N + 1; ++i) {
    int x, y;
    par p;
    do {
      x = rand() % M;
      y = rand() % M;
      p = make_pair(x, y);
    } while (pts.find(p) != pts.end());
    pts.insert(p);
  }

  for (int i = 1; i <= MAXM; ++i) {
    to_x.push_back(i);
    to_y.push_back(i);
  }

  random_shuffle(to_x.begin(), to_x.end());
  random_shuffle(to_y.begin(), to_y.end());

  for (set< par >::iterator it = pts.begin(); it != pts.end(); ++it) {
    int x = to_x[it->first];
    int y = to_y[it->second];
    ret.push_back(make_pair(x, y));
  }

  random_shuffle(ret.begin(), ret.end());
  
  printf("%d\n", ret.size() - 1);
  for (int i = 0; i < ret.size(); ++i)
    printf("%d %d\n", ret[i].first, ret[i].second);

  return 0;
}
