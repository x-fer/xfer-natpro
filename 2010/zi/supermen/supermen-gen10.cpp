#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair< int, int > par;
vector< par > pts;

int main(void) 
{
  int dx = 40000;
  int dy = 40000;
  int n4 = 25000;

  for (int i = 0; i < n4 - 1; ++i) {
    int x = dx;
    int y = dy + 2 * i;
    pts.push_back(make_pair(x, y));
  }

  for (int i = 0; i < n4 - 2; ++i) {
    int x = dx + 2;
    int y = dy + 2 * i + 1;
    pts.push_back(make_pair(x, y));
  }

  {
    int x = dx - 1;
    int y = dy;
    pts.push_back(make_pair(x, y));
  }
  
  {  
    int x = dx - 2;
    int y = dy + 2;
    pts.push_back(make_pair(x, y));
  }

  {  
    int x = dx + 2;
    int y = dy;
    pts.push_back(make_pair(x, y));
  }
  
  for (int i = 0; i < n4; ++i) {
    int x = dx + 3 + 2 * i;
    int y = dy + (2 * (n4 - 1) + 1) + 1;
    pts.push_back(make_pair(x, y));
  }

  for (int i = 0; i < n4; ++i) {
    int x = dx + 3 + 2 * i + 1;
    int y = dy + (2 * (n4 - 1) + 1) + 3;
    pts.push_back(make_pair(x, y));
  }

  random_shuffle(pts.begin(), pts.end());

  int xs = dx + 1;
  int ys = dy + (2 * (n4 - 1) + 1) + 2;
  
  printf("%d\n", pts.size());
  printf("%d %d\n", xs, ys);
  for (int i = 0; i < pts.size(); ++i)
    printf("%d %d\n", pts[i].first, pts[i].second);

  return 0;
}
