#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <map>

using namespace std;

vector <pair <string, int> > events;

string expand_part(string a) {
//  printf("expandam '%s'\n", a.c_str());
  if (a == "") {
    return "";
  }
  int start = 0;
  int count = 0;
  a += ":";
  string ret = "";
  string tmp;

  for (int i = 0; i < (int)a.size(); ++i) {
    if (a[i] == ':') {
      tmp = a.substr(start, count);
      while (tmp.size() < 4) { tmp = "0" + tmp; }
      if (ret.size()) {
        ret += ":";
      }
      ret += tmp;
      count = 0;
      start = i+1;
      continue;
    }
    ++count;
  }
  return ret;
}

string expand(string a) {
  if (a.find("::") == -1)
    return expand_part(a);
//  printf("bio!\n");

  string first = expand_part(a.substr(0, a.find("::")));
  string second = expand_part(a.substr(a.find("::")+2));

//  printf("bio2! first=%s, second=%s\n", first.c_str(), second.c_str());

  while (first.size() + second.size() < 38) {
    if (first.size()) {
      first += ":";
    }
    first += "0000";
  }
//  printf("bio3\n");

  if (second.size()) {
    first += ":";
  }
//  printf("bio3.5\n");
//  printf("%s    %s", first.c_str(), second.c_str());
  first = first + second;

//  printf("bio4\n");

  return first;
}

string expand2(string a) {
  int dots = count(a.begin(), a.end(), ':');
  string ret, t;

  a = a + ':';

  for (int i = 0; i < a.size(); ++i) {
    if (a[i] == ':' || (a[i] == ':' && i+1 < a.size() && a[i+1] == ':' && t.size())) {
      t = string(4 - t.size(), '0') + t;
      ret = ret + ":" + t;
      t = "";
      continue;
    }
    if (i && a[i-1] == ':' && a[i] == ':') {
      int add_zeros = 6 - dots;
      if (ret.size() == 0) {
        add_zeros++;
      }
      if (i+1 == a.size()) {
        add_zeros++;
      }
      for (int j = 0; j < add_zeros; ++j) {
        ret += ":0000";
      }
      continue;
    }
    if (a[i] != ':') {
      t += a[i];
    }
  }

  return ret.substr(1);
}

void load() {
  char t[150];
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    scanf("%s", t);
    string a = expand(string(t));
//    printf("bio!\n");
//    cout << a << endl;
    scanf("%s", t);
    string b = expand(string(t));
//    cout << b << endl;
    events.push_back(make_pair(a, 1));
    events.push_back(make_pair(b, -1));
  }
}

int main() {
  load();

  sort(events.begin(), events.end());

  int maxsofar = 0;
  string maxfrom, maxto;
  int curranges = 0;
  string startcurrange;
  int sametotal = 0;

  // eliminate same addresses
  for (int i = 1; i < events.size(); ++i) {
    for (int j = 1; i - j >= 0 && i + j - 1 < events.size() && events[i + j - 1].first == events[i - j].first && events[i + j - 1].second == 1 && events[i - j].second == -1; ++j) {
      events[i + j - 1].second = events[i - j].second = 0;
    }
  }

  for (int i = 0; i < events.size(); ++i) {
    if (events[i].second == -1) {
      if (curranges > maxsofar) {
        maxsofar = curranges;
        maxfrom = startcurrange;
        maxto = events[i].first;
        printf("%d\n", maxsofar);
      }
    } else if (events[i].second == 1){
      startcurrange = events[i].first;
    }

    curranges += events[i].second;
  }

  cout << maxfrom << ' ' << maxto << endl;

  return 0;
}
