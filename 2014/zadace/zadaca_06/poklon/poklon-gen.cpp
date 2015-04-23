#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>

using namespace std;

// vjerojatnost pojavljivanja padajuceg objekta -> 1/4
// vjerojatnost da je objekt bomba -> 1/4

int r[] = {5, 50, 125, 250, 375, 550, 725, 850, 1000, 1000};
int s[] = {12, 21, 200, 113, 550, 420, 1200, 1000, 1640, 2000};

int grid[1005][2005];

int main(void) {

    srand(time(NULL));
    for (int t = 1; t <= 10; ++t) {
    
        char filename[25];
        sprintf(filename, "poklon.in.%d", t);

        FILE *fout = fopen(filename, "w");
        memset(grid, 0, sizeof grid);

        int N = 0;
        for (int i = 0; i < r[t - 1]; ++i) {
            for (int j = 0; j < s[t - 1]; ++j){
                if (rand() % 4 == 0) {
                    ++N;
                    if (rand() % 4 == 0) grid[i][j] = -1; else grid[i][j] = rand() % 1000 + 1;
                }
            }
        }

        fprintf(fout, "%d\n", N);
        for (int i = 0; i < r[t - 1]; ++i) {
            for (int j = 0; j < s[t - 1]; ++j) {
                if (grid[i][j] == -1) {
                    fprintf(fout, "bomba %d %d\n", j - s[t - 1] / 2, i + 1);
                }
                if (grid[i][j] > 0) {
                    fprintf(fout, "bodovi %d %d %d\n", j - s[t - 1], i + 1, grid[i][j]);
                }
            }    
        }
    
        fclose(fout);

    }

    return 0;

}
