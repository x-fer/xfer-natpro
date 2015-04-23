#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

typedef pair<int,int> pii;

int n;
vector<pii> point;

void load() {
  scanf("%d", &n);

  for(int i = 0; i < n; ++i) {
    int tx, ty;
    scanf("%d%d", &tx, &ty);
    point.push_back(pii(tx,ty));
  }
}

// n^2*log n

const double pi = acos(-1);
double kut(const pii& p1, const pii& p2) {
  int vx = p2.first - p1.first;
  int vy = p2.second - p1.second;
  
  if(vx == 0) 
    return vy > 0 ? pi/2 : -pi/2;
  
  double ret = atan((double)vy/vx);
  if(vx < 0)
    ret += pi;

  return ret;
}

inline bool eq(double b1, double b2) {
  return fabs(b1-b2) < 1e-9;
}

int solve1() {
  vector< pair<double,pii> > kopija;
  int sol = 0;

  for(int i = 0; i < n; ++i) 
    kopija.push_back( make_pair( 0.0, point[i] ) );
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) 
      if(kopija[j].second == point[i]) 
	kopija[j].first = -100;
      else 
	kopija[j].first = kut(point[i], kopija[j].second);
      
    sort(kopija.begin(), kopija.end());
    /*
    printf("%d %d\n", point[i].first, point[i].second);
	printf("%d %d: %lf\n", kopija[j].second.first, kopija[j].second.second, kopija[j].first);
    */
    int last = 1;
    for(int j = 1; j < n; ++j) {
      if(!eq(kopija[last].first, kopija[j].first)) {
	sol = max(sol, j-last);
	last = j;
      }
    }
  }
  
  return sol+1;
}

int main() {
  load();
  printf("%d\n", solve1());

  return 0;
}
