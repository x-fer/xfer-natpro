#include <cstdio>
#include <ctime>
#include <cstdlib>

int R, S; 
int N, Rm, Sm;
int sigma;

char velikaMatrica[1000][1000];
char maleMatrice[1000][100][100];
int iteracija;

int main()
{
    srand(time(0));

    fprintf(stderr, "Upisi R i S: ");
    scanf("%d%d", &R, &S);
    fprintf(stderr, "Upisi N, Rm i Sm: ");
    scanf("%d%d%d", &N, &Rm, &Sm);
    fprintf(stderr, "Upisi velicinu abecede: ");
    scanf("%d", &sigma);
    fprintf(stderr, "Upisi broj iteracija: ");
    scanf("%d", &iteracija);

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < Rm; ++j)
        {
            for (int k = 0; k < Sm; ++k)
            {
                maleMatrice[i][j][k] = (rand()%sigma) + 'a';
            }
        }
    }

    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < S; ++j)
        {
            velikaMatrica[i][j] = (rand()%sigma) + 'a';
        }
    }

    for (int itr = 0; itr < iteracija; ++itr)
    {
        int matrica = rand()%N;
        int x = rand()%(R-Rm+1), y = rand()%(S-Sm+1);

        for (int i = 0; i < Rm; ++i)
        {
            for (int j = 0; j < Sm; ++j)
            {
                velikaMatrica[i+x][j+y] = maleMatrice[matrica][i][j];
            }
        }
    }

    printf("%d %d\n", R, S);

    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < S; ++j)
        {
            printf("%c", velikaMatrica[i][j]);
        }
        printf("\n");
    }

    printf("%d %d %d\n", N, Rm, Sm);

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < Rm; ++j)
        {
            for (int k = 0; k < Sm; ++k)
            {
                printf("%c", maleMatrice[i][j][k]);
            }
            printf("\n");
        }
    }

    return 0;
}
