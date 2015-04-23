#include <cstdio>
#include <queue>
#include <deque>

using namespace std;

int main(void){
    
    int N, M, num;
    priority_queue<int, deque<int>, greater<int> > Q;

    scanf("%d", &N);
    scanf("%d", &M);

    for(int i = 0 ; i < N ; ++i){
        scanf("%d", &num);
        if (Q.size() < M)
            Q.push(num);
        else if (Q.top() < num){
            Q.pop();
            Q.push(num);
        }
        printf("%d\n", Q.top());
    }

    return 0;
}
