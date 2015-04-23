#include <cstdio>
#include <cstring>

#include <sstream>
#include <string>
#include <set>
using namespace std;

const int MAXBUFF = 512;
const int AMERSKI = 22;
const int EUROPSKI = 20;

char buff[MAXBUFF];
char temp[MAXBUFF];

set< string > sol;

int main(int argc, char **argv) {
    int day, month, year;
    int hours, minutes, seconds;
    char am_pm[3];


    while (gets(buff)) {
        if (strlen(buff) == AMERSKI) {
            sscanf(buff, "%d/%d/%d %d:%d:%d %s", &month, &day, &year, &hours,
                    &minutes, &seconds, am_pm);

            if (strncmp(am_pm, "PM", 2) == 0 && hours != 12 ||
                strncmp(am_pm, "AM", 2) == 0 && hours == 12 ) {
                hours = (hours + 12) % 24;;
            }

            sprintf(temp, "%04d.%02d.%02d. %02d:%02d:%02d", year, month, day,
                    hours, minutes, seconds);

        } else if (strlen(buff) == EUROPSKI) {
            sscanf(buff, "%d.%d.%d. %d:%d:%d", &day, &month, &year, &hours,
                    &minutes, &seconds);

            sprintf(temp, "%04d.%02d.%02d. %02d:%02d:%02d", year, month, day,
                    hours, minutes, seconds);

        } else {
            printf("Alo bre!\n%s\n", buff);
            return 1;
        }

        sol.insert(string(temp));
        memset(temp, 0, sizeof temp);
    }

    for (set< string >::iterator it = sol.begin(); it != sol.end(); ++it) {
        sscanf(it->c_str(), "%d.%d.%d. %d:%d:%d", &year, &month, &day, &hours,
                &minutes, &seconds);

        printf("%02d.%02d.%04d. %02d:%02d:%02d\n", day, month, year,
                hours, minutes, seconds);
    }

    goto kraj;

    printf("ae");

kraj: return 0;
}
