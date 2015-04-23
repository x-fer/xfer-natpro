/*
  Natjecateljsko programiranje
  1. domaca zadaca
  Zadatak DUCAN

  autor rjesenja: Leo Osvald

  Kako bi sve trazene operacije obavljali brzo, tj. u slozenosti amortizirani O(log M) 
  tj. O(log N), koristimo strukturu set. Podatke koji su nam zamiljivi grupiramo po nekom 
  kriteriju i drzimo u odgovarajucem setu. Za prebrojavanje duplikata koristimo mape.
*/
#include <cstdio>
#include <iostream>
#include <set>
#include <map>
#define MAX 11
#define FC(it, c) for( typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it )
#define MAX_ROK "9999-99-99"
using namespace std;

typedef pair<string, string> pss;

map<string, int> cijene;
map<string, int> kol;

map< pair<string, string>, int > isti_rok;

set< pair<int, string> > cijena_sifra;
set<pss> rok_sifra;

struct cmp {
  bool operator()(const pss& a, const pss& b) {
    if( a.first < b.first ) return true;
    if( a.first > b.first ) return false;
    return a.second > b.second;
  }
};

set<pss, cmp> sifra_rok;

int main() {
  int n, m;
  scanf("%d", &n);
  while( n-- ) {
    char sifra[MAX];
    int cijena;
    scanf("%s%d", sifra, &cijena);
    cijene[sifra] = cijena;
  }

  scanf("%d", &m);
  while( m-- ) {
    int cmd, cijena;
    char sifra[MAX], rok[MAX];
    scanf("%d", &cmd);
    if( cmd == 1 ) {
      scanf("%s%s", sifra, rok);
      ++kol[sifra];
      ++isti_rok[ make_pair(sifra, rok) ];
      cijena_sifra.insert( make_pair(cijene[sifra], sifra) );
      rok_sifra.insert( make_pair(rok, sifra) );
      sifra_rok.insert( make_pair(sifra, rok) );

      printf("%d\n", kol[sifra]);
    }
    else if( cmd == 2 ) {
      scanf("%s", rok);
      int removed = 0;
      while( !rok_sifra.empty() ) {
        pss p = *rok_sifra.begin();
        if( p.first >= rok ) break;
        removed += isti_rok[ make_pair(p.second, p.first) ];
        kol[p.second] -= isti_rok[ make_pair(p.second, p.first) ];
        isti_rok[ make_pair(p.second, p.first) ] = 0;
        if( kol[p.second] == 0 )
          cijena_sifra.erase( make_pair(cijene[p.second], p.second) );
        sifra_rok.erase( make_pair(p.second, p.first) );
        rok_sifra.erase(p);
      }

      printf("%d\n", removed);
    }
    else if( cmd == 3 ) {
      scanf("%s%d", sifra, &cijena);
      if( cijena_sifra.find( make_pair(cijene[sifra], sifra) ) 
          != cijena_sifra.end() ) {
        cijena_sifra.erase( make_pair(cijene[sifra], sifra) );
        cijena_sifra.insert( make_pair(cijena, sifra) );
      }
      cijene[sifra] = cijena;
    }
    else {
      string sifra, rok;
      if( cmd == 4 )
        sifra = cijena_sifra.begin()->second;
      else {
        char s[MAX];
        scanf("%s", &s);
        sifra = s;
      }

      rok = sifra_rok.lower_bound( make_pair(sifra, MAX_ROK) )->second;

      if( --isti_rok[ make_pair(sifra, rok) ] == 0 ) {
        sifra_rok.erase( make_pair(sifra, rok) );
      }
      if( --kol[sifra] == 0 ) {
        cijena_sifra.erase( make_pair(cijene[sifra], sifra) );
        rok_sifra.erase( make_pair(rok, sifra) );
      }

      printf("%s %s %d\n", sifra.c_str(), rok.c_str(), kol[sifra]);
    }
  }

  return 0;
}
