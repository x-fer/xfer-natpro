#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair< int, int > par;
vector< par > pts;

int main(void) 
{
  int dx = 100;
  int dy = 100;
  int n3 = 30000;

  for (int i = 0; i < n3; ++i) {
    int x = dx;
    int y = dy + 3 * i;
    pts.push_back(make_pair(x, y));
  }

  for (int i = 0; i < n3; ++i) {
    int x = dx + 1;
    int y = dy + 3 * i + 1;
    pts.push_back(make_pair(x, y));
  }

  for (int i = 0; i < n3; ++i) {
    int x = dx + 2;
    int y = dy + 3 * i + 2;
    pts.push_back(make_pair(x, y));
  }

  {
    int x = dx - 1;
    int y = dy;
    pts.push_back(make_pair(x, y));
  }
  {
    int x = dx - 2;
    int y = dy + 3;
    pts.push_back(make_pair(x, y));
  }
  {
    int x = dx + 3;
    int y = dy + 3;
    pts.push_back(make_pair(x, y));
  }
  {
    int x = dx + 3;
    int y = dy + 4;
    pts.push_back(make_pair(x, y));
  }

  int left = 8996;
  for (int i = 0; i < left; ++i) {
    int x = dx + 3 + i;
    int y = dy + 90000 + i;
    pts.push_back(make_pair(x, y));
  }

  random_shuffle(pts.begin(), pts.end());

  int xs = 99000;
  int ys = dy + 90000 + 2;
  
  printf("%d\n", pts.size());
  printf("%d %d\n", xs, ys);
  for (int i = 0; i < pts.size(); ++i)
    printf("%d %d\n", pts[i].first, pts[i].second);

  return 0;
}
