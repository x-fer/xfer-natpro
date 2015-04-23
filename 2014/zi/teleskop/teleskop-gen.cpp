#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

int n[] = {-1, -1, 7, 8, 8, 13, 14, 15, 16, 16};

int main(void) {

    srand(time(NULL));
    
    for (int t = 3; t <= 10; ++t) {
        
        char filename[20];
        sprintf(filename, "za_evaluator/teleskop.in.%d", t);

        FILE *fout = fopen(filename, "w");

        fprintf(fout, "%d\n" , n[t - 1]);
        for (int i = 0; i < n[t - 1]; ++i) {
            int len = rand() % 250 + 1;
            if (t > 8) len = 250;
            for (int j = 0; j < len; ++j) {
                if (t >= 9 && (j == 0 || j == len - 1)){
                    fprintf(fout, "A");
                } else {
                    fprintf(fout, "%c", 'A' + rand() % 4);
                }
            }
            fprintf(fout, "\n");
        }

        fclose(fout);

    }
    
    return 0;

}
