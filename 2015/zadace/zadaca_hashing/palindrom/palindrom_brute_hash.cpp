#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
const int maxn=100010;
const int p=3137;
int n;
int pot[maxn];
int h[maxn];
int h2[maxn];
string s;

int hsh(int x,int y){
    return h[y]-h[x-1]*pot[y-x+1];
}

int hsh2(int x,int y){
    return h2[y]-h2[x-1]*pot[y-x+1];
}

bool check(int x){
    string s2;
    for (int i=0;i<=n-x;i++){
        if (hsh(i,i+x-1)==hsh2(n-i-x,n-1-i)){
            s2=s.substr(i,x);
            reverse(s2.begin(),s2.end());
            if (s2==s.substr(i,x)){
                return 1;
            }
        }
    }
    return 0;
}

int solve(void){
    for (int i=n;i>0;i--){
        if (check(i)){
            return i;
        }
    }
    return 0;
}

int main (void){
    scanf("%d", &n);
    cin >> s;
    pot[0]=1;
    for (int i=1;i<n;i++){
        pot[i]=pot[i-1]*p;
    }
    h[0]=s[0];
    for (int i=1;i<n;i++){
        h[i]=h[i-1]*p+s[i];
    }
    reverse(s.begin(),s.end());
    h2[0]=s[0];
    for (int i=1;i<n;i++){
        h2[i]=h2[i-1]*p+s[i];
    }
    reverse(s.begin(),s.end());
    printf("%d\n", solve());
    return 0;
}

