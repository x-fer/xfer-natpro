#include <iostream>
#include <string>
#include <cassert>

using namespace std;

int longest(const string& s, int left, int right) {
  int len = s.size();
  for (; left >= 0 && right < len; left--, right++) {
    if (s[left] != s[right]) break;
  }
  return right - left + 1 - 2;
}

int main() {
  int len;
  string s;
  cin >> len;
  cin >> s;

  assert (len == s.size());
  int ret = 0;
  for (int mid = 0; mid < len; mid++) {
    ret = max(ret, longest(s, mid, mid));
    if (mid != len-1) {
      ret = max(ret, longest(s, mid, mid+1));
    }
  }

  cout << ret << endl;
  return 0;
}
