#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

struct Event {
    int type;
    int x;

    Event() {}

    Event(int t, int _x)
        : type(t), x(_x) {}

    bool operator <(const Event &e) const {
        if (x == e.x) {
            return type < e.type;
        } else {
            return x < e.x;
        }
    }
};

int solve(FILE* f) {
    int sol = 0;
    int n, x, r;
    int max_y = 0;
    vector< Event > e;

    fscanf(f, "%d", &n);

    for (int i = 0; i < n; ++i) {
        fscanf(f, "%d%d", &x, &r);

        e.push_back(Event(0, x - r));
        e.push_back(Event(1, x + r));
    }

    sort(e.begin(), e.end());

    int aktivno = 0;
    for (int i = 0; i < e.size(); ++i) {
        if (e[i].type == 0) { // pocetak
            if (aktivno == 0) {
                sol += 1;
            }

            aktivno += 1;
        } else { // kraj
            aktivno -= 1;
        }
    }

    return sol;
}

int main(int argc, char **argv) {
    printf("%d\n", solve(stdin));
    return 0;
}
