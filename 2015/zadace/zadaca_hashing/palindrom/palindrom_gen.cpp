#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;
int n, k;
string s, s2;

char gen_char(void){
    return (rand()%26)+'a';
}

int main (void){
    scanf("%d", &n);
    srand(time(0)*n);
    printf("%d\n", n);
    k=(rand()%(n/5))+(4*n)/5;
    for (int i=0;i<k/8;i++){
        s+=gen_char();
    }
    for (int i=k/8;i<k/2;i++){
        s+='a';
    }
    if (k%2==1){
        s+='a';
    }
    s2=s.substr(0,k/2);
    reverse(s2.begin(),s2.end());
    s+=s2;
    for (int i=k;i<n;i++){
        if (rand()&1){
            s=gen_char()+s;
        }
        else{
            s+=gen_char();
        }
    }
    cout << s << endl;
    return 0;
}
