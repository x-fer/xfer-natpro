#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector< string > words;

int main(void) 
{
  cin >> N;
  words.resize(N);

  for (int i = 0; i < N; ++i) {
    cin >> words[i];
    for (int j = 0; j < words[i].size(); ++j)
      words[i][j] = tolower(words[i][j]);
  }

  sort(words.begin(), words.end());
  
  int ret = 0;
  for (int i = 0; i < N; ++i) {
    int cnt = 1;
    for (; i + 1 < N && words[i] == words[i + 1]; ++i)
      ++cnt;
    ret += !(cnt & 1) * cnt;
  }

  printf("%d\n", ret);
  return 0;
}
