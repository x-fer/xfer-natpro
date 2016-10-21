#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>

using namespace std;

map <string, int> value;
map <string, set<string> > djeca;

int n;

void print (string str, int value, int indent) {
  for (int i = 0; i < indent; ++i)
    printf("  |");
  if (indent > 0 ) printf(" ");
  printf("%s %d\n", str.c_str(), value);
}

int calc (string str) {
  int ret = value[str];
  for (auto child: djeca[str])
    ret += calc(child);
  return ret;
}

void output (string str, int indent) {
  vector <pair<string, int>> V; 
  print(str, calc(str), indent);
  for (auto child: djeca[str]) {
    output(child, indent + 1);
  }
}

char line[100000];
int main (void){
  scanf("%d", &n);
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    int price;
    scanf("%s%dkn", line, &price);
    const int len = strlen(line);
    string tmp;
    vector <string> tokens;
    for (int i = 0; i < len; ++i) {
      if (line[i] == '-') {
	tokens.push_back(tmp);
	++i;
	tmp = "";
      } else tmp += line[i];
    }
    tokens.push_back(tmp);
    for (int i = 0; i + 2 < tokens.size(); ++i)
      djeca[tokens[i]].insert(tokens[i+1]);
    value[tokens[tokens.size() - 2]] += price;
  }

  output("TROSAK", 0);
  return 0;
}

