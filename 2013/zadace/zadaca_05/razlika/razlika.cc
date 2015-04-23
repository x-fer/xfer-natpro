#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> parse(string s) {
  vector<int> ret;
  for (int i = s.size() - 1; i >= 0; --i)
    if (s[i] != '-')
      ret.push_back(s[i] - '0');
  return ret;
}

vector<int> razlika(vector<int> a, vector<int> b) {
  vector<int> ret(a.size());
  while (b.size() < a.size()) b.push_back(0);
  int carry = 0;
  for (int i = 0; i < a.size(); ++i) {
    ret[i] = a[i] - b[i] - carry;
    if (ret[i] < 0) {
      ret[i] += 10;
      carry = 1;
    }
    else carry = 0;
  }
  while (ret.back() == 0) ret.pop_back();
  return ret;
}

vector<int> zbroj(vector<int> a, vector<int> b) {
  vector<int> ret(a.size());
  while (b.size() < a.size()) b.push_back(0);
  int carry = 0;
  for (int i = 0; i < a.size(); ++i) {
    ret[i] = a[i] + b[i] + carry;
    if (ret[i] >= 10) {
      ret[i] -= 10;
      carry = 1;
    }
    else carry = 0;
  }
  if (carry) ret.push_back(1);
  return ret;
}

int main () {
  string A, B;
  cin >> A >> B;
  
  bool zbroji = false;
  if (A[0] == '-') {
    cout << "-";  // rezultat je sigurno negativan
    if (B[0] != '-')
      zbroji = true;  // negativan minus pozitivan, zbrajamo
    else zbroji = false;  // negativan minus negativan, oduzimamo
  }
  else {  // znaci, A je pozitivan, rezultat pozitivan
    if (B[0] == '-')
      zbroji = true;  // pozitivan minus negativan, zbrajamo
    else zbroji = false;  // pozitivan minus pozitivan, oduzimamo
  }

  vector<int> a = parse(A);
  vector<int> b = parse(B);
  vector<int> r = (zbroji? zbroj(a, b) : razlika(a, b));

  for (int i = r.size() - 1; i >= 0; i--)
    cout << r[i];
  cout << endl;
  return 0;
}
