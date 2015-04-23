#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>

const int MAXN = 200+1;
const int MAXP = 256;
int inf = 0x3f3f3f3f;
bool bool_true = true;

int r, s;
char polje[MAXN][MAXN];
int udaljenost[MAXN][MAXN];
bool posjetio[MAXN][MAXN];
int sol;
int broj_teladi = 0;

enum POLJA {
  PRAZNO = '.',
  TELE = 't',
  STALA = 's',
  NEPRELAZNO = '#'
};

struct coor {
  int _x, _y;
  coor();
  coor(int, int);

  coor operator +(const coor&);
  const bool operator ==(const coor &B) const;

  bool isValid() const;
  char polje() const;
  int& udaljenost() const;
  bool& posjetio() const;
  coor izlaz() const;
  void posjeti(int) const;
};

const coor delta[] = { coor(0, -1), coor(1, 0), coor(0, 1), coor(-1, 0) };
std::queue< coor > Q;
std::pair< coor, coor > izlaz[MAXP];

int main() {
  scanf("%d%d", &r, &s);
  for (int i = 0; i < r; ++i) {
    scanf(" %s", polje[i]);
  }

  coor pocetak;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < s; ++j) {
      char p = polje[i][j];
      if (p == STALA) {
        pocetak = coor(i, j);
      } else if (p != TELE && p != NEPRELAZNO && p != PRAZNO) {
        if (izlaz[(int)p].first._x == -1) {
          izlaz[(int)p].first = coor(i, j);
        } else {
          izlaz[(int)p].second = coor(i, j);
        }
      }
      if (p == TELE) {
        ++broj_teladi;
      }
    }
  }
  fprintf(stderr, "imam ukupno %d teleta\n", broj_teladi);
  memset(udaljenost, 0x3f, sizeof(udaljenost));
  pocetak.udaljenost() = 0;

  for (Q.push(pocetak); !Q.empty(); Q.pop()) {
    coor tren = Q.front();
    for (int i = 0; i < 4; ++i) {
      coor tmp = tren + delta[i];
      tmp.posjeti(tren.udaljenost() + 1);
    }
  }

  printf("%d\n", sol);
  fprintf(stderr, "ostalo je %d teleta nepronadjeno\n", broj_teladi);
  assert(broj_teladi == 0);

  return 0;
}

coor::coor() : _x(-1), _y(-1) {}

coor::coor(int x, int y) : _x(x), _y(y) {}

bool coor::isValid() const {
  return _x >= 0 && _x < r && _y >= 0 && _y < s;
}

coor coor::operator +(const coor &B) {
  return coor(_x+B._x, _y+B._y);
}

const bool coor::operator ==(const coor &B) const {
  return B._x == _x && B._y == _y;
}

char coor::polje() const {
  if (!this->isValid()) {
    return '#';
  }
  return ::polje[_x][_y];
}

int& coor::udaljenost() const {
  if (!this->isValid()) {
    return inf;
  }
  return ::udaljenost[_x][_y];
}

bool& coor::posjetio() const {
  if (!this->isValid()) {
    return bool_true;
  }
  return ::posjetio[_x][_y];
}

coor coor::izlaz() const {
  char polje = this->polje();
  if (polje == NEPRELAZNO) {
    return coor(inf, inf);
  }
  if (polje == TELE || polje == PRAZNO || polje == STALA) {
    return *this;
  }
  if (::izlaz[(int)polje].first == *this) {
    return ::izlaz[(int)polje].second;
  }
  return ::izlaz[(int)polje].first;
}

void coor::posjeti(int korak) const {
  char polje = this->polje();
  if (polje == NEPRELAZNO) {
    return;
  }
  if (this->posjetio()) {
    return;
  }
  this->posjetio() = true;
  if (polje == TELE) {
    ::sol = std::max(korak, ::sol);
    --broj_teladi;
  }
  this->udaljenost() = korak;
  Q.push(*this);
  if (!(this->izlaz() == *this)) {
    this->izlaz().udaljenost() = korak;
    Q.push(this->izlaz());
  }
}


