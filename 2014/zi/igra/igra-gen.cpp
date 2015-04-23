#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <fstream> 

using namespace std;

int main(void) {

    srand(time(NULL));
    for (int t = 1; t <= 10; ++t) {
    
        char filename[20];
        sprintf(filename, "za_evaluator/igra.in.%d", t);

        FILE *fout = fopen(filename, "w");
        
        int N = rand() % 1000 + 1;
        int K = rand() % 1000 + 1;

        if (t < 5) {
            N %= 25; 
            K %= 25;
        }

        fprintf(fout, "%d %d\n", N, K);
        fclose(fout);

    }
    
    return 0;

}
