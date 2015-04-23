# include <cstdio>
# include <cstdlib>
# include <ctime>
# include <cstring>

using namespace std;

const int MAXN = 100010;

int my_rand() {
    int x = 0;
    for (int i = 30; i >= 0; --i)
        x |= (1 << i) * (rand() % 2);
    return x;
}

int main(void) {
    int N, M;
    int *a = (int*) malloc(sizeof(int));
    srand(time(0) + (int) a);
    free(a);

    scanf("%d %d", &N, &M);
    printf("%d\n", N);

    while (N--) {
        int start = 1 + my_rand() % (M - 1);
        int end = start + my_rand() % (M - start) + 1;
        printf("%d %d\n", start, end);
    }

    return 0;
}
