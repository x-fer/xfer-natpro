#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

inline int sgn(int n) {
	return !n ? -1 : 1;
}

int main(void)
{
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  vector<int> x(n), y(n), z(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i] >> z[i];
  }
  
  int ans = INT_MIN;
	for (int mask = 0; mask < 1 << 3; ++mask) {
		int m = INT_MAX;
    int M = INT_MIN;
    int m_id;
    int M_id;

		for (int i = 0; i < n; ++i) {
			int t = 
        sgn(mask & (1 << 0)) * x[i] +
        sgn(mask & (1 << 1)) * y[i] +
        sgn(mask & (1 << 2)) * z[i];
        
			if (t < m) { 
        m = t;
        m_id = i;
      }
			if (t > M) { 
        M = t;
        M_id = i;
      }
		}

		ans = max(ans, 
      abs(x[M_id] - x[m_id]) + 
      abs(y[M_id] - y[m_id]) + 
      abs(z[M_id] - z[m_id]));
	}
  cout << ans << "\n";
  
	return 0;
}
