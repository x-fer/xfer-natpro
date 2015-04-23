# include <cstdio>
# include <iostream>
# include <vector>
# include <algorithm>
# include <queue>

using namespace std;

const int MAXN = 100010;

struct event {
    int where, type, index;
    event(int w, int t, int i): where(w), type(t), index(i) {}

    friend bool operator <(const event &a, const event &b) {
        if (a.where != b.where) return a.where < b.where;
        if (a.type != b.type) return a.type < b.type;
        if (a.type) return a.index < b.index;
        return a.index > b.index;
    }
};

struct poster {
    int start, end;
    bool was_ever_on_top, open;
    poster(int s, int e): start(s), end(e) {
        was_ever_on_top = false;
        open = false;
    }
};

int N, T;

int main(void) {
    //scanf("%d", &T);
    T = 1;

    while (T--) {
        vector<event> Events;
        vector<poster> Posters;
        int t1, t2;

        scanf("%d", &N);
        for (int i = 0; i < N; ++i) {
            scanf("%d %d", &t1, &t2);

            Posters.push_back(poster(t1, t2));
            Events.push_back(event(t1, 0, i));
            Events.push_back(event(t2 + 1, 1, i));
        }

        sort(Events.begin(), Events.end());

        priority_queue<int> PQ;

        for (int i = 0; i < (int) Events.size(); ++i) {
            if (Events[i].type == 0) {
                PQ.push(Events[i].index);
                Posters[Events[i].index].open = true;
            } else {
                Posters[Events[i].index].open = false;
            }

            while (!PQ.empty() && Posters[PQ.top()].open == false)
                PQ.pop();

            if (!PQ.empty())
                Posters[PQ.top()].was_ever_on_top = true;
        }

        int sol = 0;

        for (int i = 0; i < N; ++i) {
            sol += Posters[i].was_ever_on_top ? 1 : 0;
        }

        printf("%d\n", sol);
    }
    return 0;
}
