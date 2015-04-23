/*
    Filip Pavetic, Natjecateljsko programiranje 2010/2011

    Rjesenje je slozenosti O(n^2) - sweepline
    Dogadjaji su:
        - lijeva stranica pravokutnika
        - desna stranica pravokutnika

    Ponasanje na svakom od dogadjaja je slicno - moramo saznati pokrivenost y koordinate (to radimo jednodimenzionalnim sweepom) i pomnoziti ga
    s deltaX-om od prethodnog dogadjaja. Taj umnozak je doprinos povrsini pojedinog dogadjaja. Suma svih doprinosa daje ukupnu povrsinu.
*/

#include <cstdio>
#include <cassert>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
using namespace std;

struct event {
    int x;
    pair<int, int> pokriva;
    bool ulazi;

    bool operator < (const event& A) const {
        return x < A.x;
    }
};

int get_pokrivenost(const multiset< pair<int, int> >& M) {
    int pokriveno = 0;
    int dubina = 0;
    int prvi_x = 0;

    for (multiset<pair<int, int> >::const_iterator it = M.begin(); it != M.end(); ++it) {
            if(it->second == 0) { // ulazi
                if (dubina == 0) prvi_x = it->first;
                ++dubina;
            } else {
                --dubina;
                if (dubina == 0) {
                    pokriveno += it->first - prvi_x;
                }
            }
    }

    return pokriveno;
}

int main(void) {

    int n; scanf("%d", &n);

    vector<event> V;

    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2; scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

        event A;
        A.x = x1;
        A.pokriva = make_pair(y1, y2);
        A.ulazi = true;

        event B;
        B.x = x2;
        B.pokriva = make_pair(y1, y2);
        B.ulazi = false;

        V.push_back(A);
        V.push_back(B);
    }

    sort(V.begin(), V.end());
    int last_x = 0;
    int dubina = 0;

    multiset< pair<int, int> > krajnje_tocke;

    int povrsina = 0;

    for (int i = 0; i < V.size(); ++i) {
        if (V[i].ulazi) {
            if (dubina == 0) {
                last_x = V[i].x;
            }

            int pokriva_y = get_pokrivenost(krajnje_tocke);
            povrsina += (V[i].x - last_x) * pokriva_y;
            last_x = V[i].x;

            krajnje_tocke.insert(make_pair(V[i].pokriva.first, 0));
            krajnje_tocke.insert(make_pair(V[i].pokriva.second,1));
            ++dubina;
        } else {
            int pokriva_y = get_pokrivenost(krajnje_tocke);
            povrsina += (V[i].x - last_x) * pokriva_y;
            last_x = V[i].x;

            krajnje_tocke.erase(krajnje_tocke.find(make_pair(V[i].pokriva.first, 0)));
            krajnje_tocke.erase(krajnje_tocke.find(make_pair(V[i].pokriva.second,1)));
            --dubina;
        }
    }

    printf("%d\n", povrsina);
return 0;
}
