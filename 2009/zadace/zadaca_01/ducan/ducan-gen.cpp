#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cassert>

#define MAX 11
#define MAX_N 100000
#define MOD 100000007
#define MAX_ROK "9999-99-99"

using namespace std;
typedef long long LL;
typedef pair<string, int> par;

int n, m, range_rok, range_cijena = 5;
int offset_cijena, type2step;
int pool_cijena[MAX_N];
string sifre[MAX_N];


typedef pair<string, string> pss;

map<string, int> cijene;
map<string, int> kol;

map< pair<string, string>, int > isti_rok;

set< pair<int, string> > cijena_sifra;
set<pss> rok_sifra;

struct sr {
  string sifra;
  string rok;
  sr(string sifra, string rok) 
    : sifra(sifra), rok(rok) { }
  friend bool operator==(const sr& a, const sr& b) {
    return a.sifra == b.sifra && a.rok == b.rok;
  }
};

struct cmp {
  bool operator()(const sr& a, const sr& b) {
    if( a.sifra < b.sifra ) return true;
    if( a.sifra > b.sifra ) return false;
    return a.rok > b.rok;
  }
};

set<sr, cmp> sifra_rok;


long long random(long long max) {
  long long ret = 0;
  for( int i = 0; i < 18; ++i )
    ret = ret*10 + (rand()%10);
  return ret%max;
}

string random_rok() {
  char s[MAX];
  int r = random(range_rok);
  int year = r / (28*12);
  r %= (28*12);
  int month = r / 28;
  r %= 28;
  sprintf(s, "%04d-%02d-%02d", year, month+1, r+1);
  return s;
}

int random_cijena() {
  return pool_cijena[random(range_cijena)];
}

string gen_sifra() {
  string ret;
  for( int i = 0; i < 10; ++i ) {
    char c = 'A' + rand()%36;
    if( c > 'Z' ) c = c-'Z'-1+'0';
    ret.push_back(c);
  }
  return ret;
}

void random_one() {
  int id = random(n);
  string sifra = sifre[id];
  string rok = random_rok();

  ++kol[sifra];
  ++isti_rok[ make_pair(sifra, rok) ];
  cijena_sifra.insert( make_pair(cijene[sifra], sifra) );
  rok_sifra.insert( make_pair(rok, sifra) );
  sifra_rok.insert( sr(sifra, rok) );

  printf("1 %s %s\n", sifra.c_str(), rok.c_str());
}
void random_two() {
  string rok = random_rok();
  while( !rok_sifra.empty() ) {
    pss p = *rok_sifra.begin();
    if( p.first >= rok ) break;
    isti_rok[ make_pair(p.second, p.first) ];
    kol[p.second] -= isti_rok[ make_pair(p.second, p.first) ];
    isti_rok[ make_pair(p.second, p.first) ] = 0;
    if( kol[p.second] == 0 )
      cijena_sifra.erase( make_pair(cijene[p.second], p.second) );
    sifra_rok.erase( sr(p.second, p.first) );
    rok_sifra.erase(p);
  }
  printf("2 %s\n", rok.c_str());
}
void random_three() {
  string sifra = sifre[random(n)];
  int cijena = random_cijena();
  if( cijena_sifra.find( make_pair(cijene[sifra], sifra) ) 
      != cijena_sifra.end() ) {
    cijena_sifra.erase( make_pair(cijene[sifra], sifra) );
    cijena_sifra.insert( make_pair(cijena, sifra) );
  }
  cijene[sifra] = cijena;
  printf("3 %s %d\n", sifra.c_str(), cijena);
}
int random_four() {
  if( cijena_sifra.empty() ) return 0;

  string sifra = cijena_sifra.begin()->second;
  
  set<sr, cmp>::iterator it = sifra_rok.lower_bound( sr(sifra, MAX_ROK) );
  assert( it != sifra_rok.end() );
  string rok = it->rok;
  
  if( --isti_rok[ make_pair(sifra, rok) ] == 0 ) {
    sifra_rok.erase( sr(sifra, rok) );
  }
  if( --kol[sifra] == 0 ) {
    cijena_sifra.erase( make_pair(cijene[sifra], sifra) );
    rok_sifra.erase( make_pair(rok, sifra) );
  }

  printf("4\n");
  return 1;
}
int random_five() {
  if( sifra_rok.empty() ) return 0;

  string rsifra = sifra_rok.begin()->sifra;
  
  set<sr, cmp>::iterator it = sifra_rok.lower_bound( sr(rsifra, MAX_ROK) );
  if( it == sifra_rok.end() ) 
    --it;
  string sifra = it->sifra, rok = it->rok;

  assert( isti_rok[ make_pair(sifra, rok) ] > 0 );
  assert( kol[sifra] > 0 );
  
  if( --isti_rok[ make_pair(sifra, rok) ] == 0 ) {
    sifra_rok.erase( sr(sifra, rok) );
  }
  if( --kol[sifra] == 0 ) {
    cijena_sifra.erase( make_pair(cijene[sifra], sifra) );
    rok_sifra.erase( make_pair(rok, sifra) );
  }

  printf("5 %s\n", sifra.c_str());
  return 1;

}

void gen_cijene() {
  for( int i = 0; i < range_cijena; ++i )
    pool_cijena[i] = random(999999999)+1;
  printf("%d\n", n);
  for( int i = 0; i < n; ++i ) {
    cijene[sifre[i]] = random_cijena();
    printf("%s %d\n", sifre[i].c_str(), cijene[sifre[i]]);
  }
}

void gen_products() {
  int hit = 0;
  set<string> s;
  offset_cijena = 1000000000 - range_cijena;
  for( int i = 0; i < n; ++i ) {
    while( s.find(sifre[i] = gen_sifra()) != s.end() ) {
      ++hit;
    }
    s.insert(sifre[i]);
  }
  //fprintf(stderr, "Collisions: %d\n", hit);
  gen_cijene();
}

void generate() {
  int seed;
  srand(time(NULL) + (int) &seed);
  gen_products();
  printf("%d\n", m);
  while( m ) {
    int cmd;
    if(random(type2step) == 0)
      cmd = 2;
    else if( rand()%10 == 0 ) cmd = 3;
    else if( rand()%3 ) cmd = 1; 
    else {
      cmd = 4 + rand()%2;
      if( cijena_sifra.empty() ) continue;
    }
    if( cmd == 1 ) random_one();
    else if( cmd == 2 ) random_two();
    else if( cmd == 3 ) random_three();
    else if( cmd == 4 && !random_four() ) continue;
    else if( cmd == 5 && !random_five() ) continue;
    m--;
  }
}

int main(int argc, char** argv) {
  if( argc <= 5 ) {
    fprintf(stderr, "Usage: N M ROK_RANGE CIJENA_RANGE TYPE2_STEP\n");
    return 1;
  }
  
  n = atoi(argv[1]);
  m = atoi(argv[2]);
  range_rok = atoi(argv[3]);
  range_cijena = atoi(argv[4]);
  type2step = atoi(argv[5]);

  generate();


  return 0;
}
