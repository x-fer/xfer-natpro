#include <cstring>
#include <cstdio>

#include <string>
#include <ctime>
#include <vector>
using namespace std;

const int MAXBUFF = 512;

char buff[MAXBUFF];

vector< string > sol;

int main(int argc, char **argv) {
    srand(time(NULL));

    int N = atoi(argv[1]);

    while(N--) {
        int year = 2000 + rand() % 14;
        int month = 1 + rand() % 12;
        int day = 1 + rand() % 27;

        int hours = rand() % 12;
        int minutes = rand() % 60;
        int seconds = rand() % 60;

        int type = rand() % 3;

        if (type == 0) {
            // AM
            sprintf(buff, "%02d/%02d/%04d %02d:%02d:%02d AM", month, day, year,
                    hours, minutes, seconds);
        } else if (type == 1){
            // PM
            sprintf(buff, "%02d/%02d/%04d %02d:%02d:%02d PM", month, day, year,
                    hours, minutes, seconds);
        } else {
            // normalno
            sprintf(buff, "%02d.%02d.%04d. %02d:%02d:%02d", day, month, year,
                    hours, minutes, seconds);
        }

        if (N > 5) {
            int count = rand() % N;
            for (int i = 0; i < count; ++i) {
                // dupliciraj
                sol.push_back(string(buff));
                N -= 1;
            }
        }

        sol.push_back(string(buff));
    }

    random_shuffle(sol.begin(), sol.end());

    for (vector< string >::iterator it = sol.begin(); it != sol.end(); ++it) {
        printf("%s\n", it->c_str());
    }

    return 0;
}
