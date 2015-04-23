#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>

#define FORC(it, C) for (__typeof((C).begin()) it = (C).begin(); it != (C).end(); ++it)

class ipv6 {
  std::vector< int > dijelovi;

  std::vector< int > parse_fragment(const std::string &S) const {
    std::vector< int > ret;
    std::string curr = "";
    int last = 0;
    unsigned x;

    while (S.find(":", last) != std::string::npos) {
      sscanf(S.substr(last, S.find(":", last)-last).c_str(), "%x", &x);
      last = S.find(":", last) + 1;
      ret.push_back(x);
    }

    if (last < (int)S.size()) {
      sscanf(S.substr(last).c_str(), "%x", &x);
      ret.push_back(x);
    }

    return ret;
  }

  std::vector< int > parse(const std::string &S) const {
    if (S.find("::") != std::string::npos) {
      int pos = S.find("::");
      std::vector< int > part1 = parse_fragment(S.substr(0, pos));
      std::vector< int > part2 = parse_fragment(S.substr(pos+2));
      while (part1.size() + part2.size() < 8) {
        part1.push_back(0);
      }
      FORC(it, part2) {
        part1.push_back(*it);
      }
      return part1;
    }

    return parse_fragment(S);
  }

public:
  ipv6() : dijelovi(std::vector< int >(8, 99999)) {}
  ipv6(const std::string &S) {
    dijelovi = this->parse(S);
  }

  bool operator<(const ipv6 &other) const {
    return this->dijelovi < other.dijelovi;
  }

  bool operator!=(const ipv6 &other) const {
    return this->dijelovi != other.dijelovi;
  }

  void print(const char* end = "") {
    for (int i = 0; i < (int)dijelovi.size(); ++i) {
      printf("%.4x%s", dijelovi[i], i+1 == (int)dijelovi.size() ? end : ":");
    }
  }
};

enum {
  START, END
};

struct event {
  ipv6 when;
  int what;

  event() : when(), what() {}
  event(const std::string &S, int _what) : when(S), what(_what) {}

  bool operator<(const event &other) const {
    if (this->when != other.when) return this->when < other.when;
    return this->what < other.what;
  }
};

int main() {
  int n;
  char A[1024], B[1024];
  std::vector< event > E;

  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf(" %s%s", A, B);
    E.push_back(event(A, 0));
    E.push_back(event(B, 1));
  }

  std::sort(E.begin(), E.end());
  int current_count = 0;
  int best_count = 0;
  ipv6 best_start;
  ipv6 best_end;
  bool in_best = false;

  FORC (it, E) {
    if (it->what == START && ++current_count > best_count) {
      best_count = current_count;
      best_start = it->when;
      printf("%d\n", best_count);
      in_best = true;
    } else if (it-> what == END) {
      --current_count;
      if (in_best) {
        best_end = it->when;
        in_best = false;
      }
    }
  }

  best_start.print(" ");
  best_end.print("\n");

  return 0;
}