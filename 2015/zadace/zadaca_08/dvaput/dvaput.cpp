#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#define pii pair<int,int>
#define x first
#define y second

using namespace std;
const int maxn=200010;
const int p=3137;
int n;
int pot[maxn];
string s;

vector <pii> v;

bool check(int x){
    v.clear();
    int h;
    h=s[0];
    for (int i=1;i<x;i++){
        h*=p;
        h+=s[i];
    }
    v.push_back(make_pair(h,0));
    for (int i=x;i<n;i++){
        h-=s[i-x]*pot[x-1];
        h*=p;
        h+=s[i];
        v.push_back(make_pair(h,i-x+1));
    }
    sort(v.begin(),v.end());
    int v_size=v.size();
    for (int i=0;i<v_size-1;i++){
        if (v[i].x==v[i+1].x){
            if (s.substr(v[i].y,x)==s.substr(v[i+1].y,x)){
                return 1;
            }
        }
    }
    return 0;
}

int solve(void){
    int l=0,r=n,mid;
    while (l!=r){
        mid=(l+r+1)/2;
        if (check(mid)){
            l=mid;
        }
        else{
            r=mid-1;
        }
    }
    return l;
}

int main (void){
    scanf("%d", &n);
    cin >> s;
    pot[0]=1;
    for (int i=1;i<n;i++){
        pot[i]=pot[i-1]*p;
    }
    printf("%d\n", solve());
    return 0;
}
