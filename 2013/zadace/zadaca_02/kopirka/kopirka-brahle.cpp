#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>

int isprobaj(const std::vector< int > &p, const long long po_kanti) {
  int kanti = 1;
  long long trenutno = 0;
  for (auto &x : p) {
    if (x > po_kanti) return -1;
    if (trenutno + x > po_kanti) {
      trenutno = 0;
      ++kanti;
    }
    trenutno += x;
  }
  return kanti;
}

std::vector< std::string > tokeniziraj(
  const std::vector< int > &p,
  const long long po_kanti,
  const int kanti
) {
  long long trenutno = 0;
  int koristeno_kanti = 1;
  char buff[100];
  std::vector< std::string > ret;
  for (int i = p.size()-1; i >= 0; --i) {
    if (trenutno + p[i] > po_kanti) {
      trenutno = 0;
      ret.push_back("/");
      ++koristeno_kanti;
    }
    sprintf(buff, "%d", p[i]);
    ret.push_back(buff);
    trenutno += p[i];
  }
  std::reverse(begin(ret), end(ret));
  int i = 0;
  while (koristeno_kanti < kanti && i+1 < (int)ret.size()) {
    while (i+1 < (int)ret.size() && (ret[i] == "/" || ret[i+1] == "/")) {
      ++i;
    }
    ret.insert(ret.begin()+i+1, "/");
    ++koristeno_kanti;
  }
  return ret;
}

int main() {
  int m, k;
  scanf("%d%d", &m, &k);
  std::vector< int > p(m);
  for (auto &x : p) {
    scanf("%d", &x);
  }

  long long lijevo = 0, desno = 10000000000LL, sredina;

  for (int i = 0; i < 50; ++i) {
    sredina = (lijevo + desno) / 2;
    int rjesenje = isprobaj(p, sredina);
    if (rjesenje != -1 && rjesenje <= k) {
      desno = sredina;
    } else {
      lijevo = sredina;
    }
  }

  std::vector< std::string > rjesenje = tokeniziraj(p, desno, k);
  for (auto &s : rjesenje) {
    printf("%s ", s.c_str());
  }

  return 0;
}
