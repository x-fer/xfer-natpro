#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>

using namespace std;

#define P 7
#define MOD 10007

char velikaMatrica[1000][1000];
int hashColumn[1000][1000];

char maleMatrice[1000][100][100];
vector<int> hashTable[MOD];

int R, S, N, Rm, Sm;

int sol[1000];

int pow(int a, int p)
{
    int retVal = 1, t = a;

    for ( ; p; p >>= 1)
    {
        if (p&1) retVal = ((long long)retVal*t) % MOD;
        t = ((long long)t*t) % MOD;
    }

    return retVal;
}

void load()
{
    scanf("%d%d", &R, &S);

    for (int i = 0; i < R; ++i) scanf("%s", velikaMatrica[i]);

    scanf("%d%d%d", &N, &Rm, &Sm);
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < Rm; ++j) scanf("%s", maleMatrice[i][j]);
    }
}

void calculateHashTable()
{
    for (int i = 0; i < N; ++i)
    {
        int hash = 0;
        for (int j = 0; j < Rm; ++j)
        {
            for (int k = 0; k < Sm; ++k)
            {
                hash = (hash*P + maleMatrice[i][j][k]-'a'+1) % MOD;
            }
        }
        hashTable[hash].push_back(i);
    }
}

void calculateHashColumns()
{
    for (int i = 0; i+Rm <= R; ++i)
    {
        for (int j = 0; j < S; ++j)
        {
            if (i == 0)
            {
                hashColumn[i][j] = 0;
                for (int k = 0; k < Sm; ++k)
                {
                    hashColumn[i][j] = ((long long)hashColumn[i][j]*pow(P, Sm) + velikaMatrica[i+k][j]-'a'+1) % MOD;
                }
            }else
            {
                hashColumn[i][j] = (hashColumn[i-1][j] - ((long long)velikaMatrica[i-1][j]-'a'+1)*pow(P, Sm*(Rm-1)) % MOD + MOD) % MOD;
                hashColumn[i][j] = ((long long)hashColumn[i][j]*pow(P, Sm) + velikaMatrica[i+Rm-1][j]-'a'+1) % MOD;
            }
        }
    }
}

bool check(int x, int y, int k)
{
    for (int i = 0; i < Rm; ++i)
    {
        for (int j = 0; j < Sm; ++j)
        {
            if (velikaMatrica[x+i][y+j] != maleMatrice[k][i][j]) return false;
        }
    }
    
    return true;
}

void solve()
{
    memset(sol, 0, sizeof sol);

    int tHash = 0;

    for (int i = 0; i+Rm <= R; ++i)
    {
        for (int j = 0; j+Sm <= S; ++j)
        {
            if (j == 0)
            {
                tHash = 0;
                for (int k = 0; k < Sm; ++k){
                    tHash = (tHash*P + hashColumn[i][j+k]) % MOD;
                }
            }else{
                tHash = (tHash - (((long long)hashColumn[i][j-1]*pow(P, Sm-1)) % MOD) + MOD) % MOD;
                tHash = ((long long)tHash*P + hashColumn[i][j+Sm-1]) % MOD;
            }

            for (int k = 0; k < hashTable[tHash].size(); ++k)
            {
                if (check(i, j, hashTable[tHash][k])) 
                {
                    ++sol[hashTable[tHash][k]];
                }
            }
        }
    } 
}

int main()
{
    load();
    calculateHashTable();
    calculateHashColumns();
    solve();

    for (int i = 0; i < N; ++i) printf("%d\n", sol[i]);

    return 0;
}
