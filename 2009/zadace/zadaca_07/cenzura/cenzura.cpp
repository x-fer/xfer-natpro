#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#define MOD_HASH 1000007
#define P 31
#define MAX_S 1000001
#define MAX_T 51

using namespace std;

vector <string> blackList;
vector <int> stringsWithAHash[MOD_HASH];
char post[MAX_S];

// vraca hash vrijednost. string mora sadrzavati samo mala slova engleske abecede
int hash(const string& s)
{
    int retVal = 0;

    for (int i = 0; i < s.size(); ++i)
    {
        retVal = (retVal * P) % MOD_HASH;
        retVal = (retVal + (s[i]-'a'+1)) % MOD_HASH;
    }

    return retVal;
}

bool isNeprimjerena(string &s)
{
    sort(s.begin(), s.end());
    int hashVal = hash(s);

    for (int i = 0; i < stringsWithAHash[hashVal].size(); ++i)
    {
        if (blackList[stringsWithAHash[hashVal][i]] == s) return true;
    }

    return false;
}

void load()
{
    int q; scanf("%d\n", &q);
    fgets(post, MAX_S, stdin);

    int n; scanf("%d", &n);
    blackList.resize(n);

    for (int i = 0; i < blackList.size(); ++i)
    {
        char t[MAX_T];
        scanf("%s", t);

        blackList[i] = string(t);
        sort(blackList[i].begin(), blackList[i].end());
        stringsWithAHash[hash(blackList[i])].push_back(i);
    }
}

void solve()
{
    char t[MAX_S], tLen = 0;

    for (int i = 0; ; ++i)
    {
        if (post[i] >= 'a' && post[i] <= 'z')
        {
            t[tLen++] = post[i];
        }else if (tLen)
        {
            t[tLen] = 0;

            string tS(t);

            if (isNeprimjerena(tS))
            {
                for (int j = i-tLen+1; j < i-1; ++j) post[j] = '*';
            }

            tLen = 0;
        }

        if (post[i] == 0) break;
    }
}

void diagnostics()
{
    int pojavljivanja[30] = {0};

    for (int i = 0; i < MOD_HASH; ++i)
        if (stringsWithAHash[i].size() < 30) pojavljivanja[stringsWithAHash[i].size()]++;

    for (int i = 0; i < 30; ++i){
        fprintf(stderr, "%d: %d\n", i, pojavljivanja[i]);
    }
}

int main()
{
    load();
    solve();
    printf("%s\n", post);

    //diagnostics();

    return 0;
}
