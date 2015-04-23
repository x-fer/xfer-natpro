#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

class Bignum;
typedef long long llint;
typedef vector<vector<Bignum>> Matrix;
const int MODPOWER = 100;

struct Bignum : public vector<int> {
  const static int kBase = 10;

  void Normalise() {
    int carry = 0;
    for (int i = 0; i < (int)size(); ++i) {
      at(i) += carry;
      carry = at(i) / kBase;
      at(i) %= kBase;
      if (i + 1 == (int)size() && carry)
        push_back(0);
    }
    if (size() > MODPOWER) resize(MODPOWER);
    while ((int)size() > 1 && back() == 0)
      pop_back();
  }

  void Print() {
    for (int i = (int)size()-1; i >= 0; --i)
      printf("%1d", at(i));
    printf("\n");
  }

  friend Bignum AddBignums(const Bignum &a, const Bignum &b) {
    Bignum c;
    for (int i = 0; i < (int)max(a.size(), b.size()); ++i) {
      int a1 = i < (int)a.size() ? a[i] : 0;
      int b1 = i < (int)b.size() ? b[i] : 0;
      c.push_back(a1 + b1);
    }
    c.Normalise();
    return c;
  }

  friend Bignum MultiplyBignums(const Bignum &a, const Bignum &b) {
    Bignum c;
    c.resize(a.size() + b.size());
    for (int i = 0; i < (int)a.size(); ++i)
      for (int j = 0; j < (int)b.size(); ++j)
        c[i+j] += a[i] * b[j];
    c.Normalise();
    return c;
  }

  Bignum(int x) {
    while (x) {
      push_back(x % kBase);
      x /= kBase;
    }
    if ((int)size() == 0)
      push_back(0);
  }

  Bignum() {}
};

Matrix MultiplyMatrices(const Matrix &a, const Matrix &b) {
  Matrix c(a.size(), vector<Bignum>(b[0].size(), 0));
  for (int i = 0; i < (int)a.size(); ++i)
    for (int j = 0; j < (int)b[0].size(); ++j)
      for (int k = 0; k < (int)a[0].size(); ++k)
        c[i][j] = AddBignums(c[i][j], MultiplyBignums(a[i][k], b[k][j]));
  return c;
}

int main() {
  llint n;
  scanf("%lld", &n);

  Matrix transition = { 
    {1, 1, 0}, 
    {1, 0, 0},
    {1, 0, 1},
  };
  Matrix result = {
    {1, 0, 0},
    {0, 1, 0},
    {0, 0, 1}
  };
  Matrix starting_vector = {
    {1}, {0}, {0}
  };

  while (n) {
    if (n & 1) result = MultiplyMatrices(result, transition);
    transition = MultiplyMatrices(transition, transition);
    n /= 2;
  }

  starting_vector = MultiplyMatrices(result, starting_vector);
  starting_vector[2][0].Print();

  return 0;
}

