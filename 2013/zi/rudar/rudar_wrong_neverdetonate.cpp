#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

const int inf = 0x3f3f3f3f;

typedef pair<int, int> coord;

typedef pair<int, coord> dijkp;

const int ndirs = 4;
const int dir[][2] = {
	{0, -1},
	{-1, 0},
	{0, 1},
	{1, 0}
};

class rudar
{
	private:
		int r;
		int c;
		vector<string> maze;

		int pathlen;

		char getmc(int i, int j) {
			if ((i < 0) || (j < 0) || (i >= r) || (j >= c)) {
				return '#';
			} else {
				return maze.at(i).at(j);
			}
		}

		bool isempty(int i, int j) {
			char c = getmc(i, j);
			return (c == '.') || (c == 'J') || (c == 'X');
		}

		int movecost(int i, int j, int bdi) {
			switch (getmc(i + dir[bdi][0], j + dir[bdi][1])) {
				case '#':
					return inf;
				case '*':
					return inf;
				case '.':
				case 'J':
				case 'X':
					return 1;
				default:
					return inf;
			}
		}

		coord findjakov() {
			for (int i = 0; i < r; ++i) {
				for (int j = 0; j < c; ++j) {
					if (maze.at(i).at(j) == 'J') {
						return make_pair(i, j);
					}
				}
			}
			return make_pair(-1, -1);
		}

		int dijkstra(const coord &sc) {
			vector<vector<int> > dist(r, vector<int>(c, inf));
			vector<vector<bool> > done(r, vector<bool>(c, false));
			priority_queue<dijkp, vector<dijkp>, greater<dijkp> > dpq;
			dist.at(sc.first).at(sc.second) = 0;
			dpq.push(make_pair(0, sc));
			while (!(dpq.empty())) {
				coord cc = dpq.top().second;
				dpq.pop();
				if (done.at(cc.first).at(cc.second)) {
					continue;
				}
				done.at(cc.first).at(cc.second) = true;
				if (getmc(cc.first, cc.second) == 'X') {
					/*for (int i = 0; i < r; ++i) {
						for (int j = 0; j < c; ++j) {
							printf("%d ", (dist.at(i).at(j) > inf / 2)? -1 : dist.at(i).at(j));
						}
						printf("\n");
					}*/
					return dist.at(cc.first).at(cc.second);
				}
				for (int bdi = 0; bdi < ndirs; ++bdi) {
					coord nc(cc.first + dir[bdi][0], cc.second + dir[bdi][1]);
					if (getmc(nc.first, nc.second) == '#') {
						continue;
					}
					int newcost = dist.at(cc.first).at(cc.second) + movecost(cc.first, cc.second, bdi);
					if (dist.at(nc.first).at(nc.second) > newcost) {
						dist.at(nc.first).at(nc.second) = newcost;
						dpq.push(make_pair(newcost, nc));
					}
				}
			}
			/*for (int i = 0; i < r; ++i) {
				for (int j = 0; j < c; ++j) {
					printf("%d ", (dist.at(i).at(j) > inf / 2)? -1 : dist.at(i).at(j));
				}
				printf("\n");
			}*/
			return -1;
		}

	public:
		rudar() : r(0), c(0), maze(), pathlen(-1) {}

		void input(FILE *infp) {
			fscanf(infp, "%d%d", &r, &c);
			char *buf = new char[c + 2];
			maze.reserve(r);
			for (int i = 0; i < r; ++i) {
				fscanf(infp, "%s", buf);
				maze.push_back(buf);
			}
			delete[] buf;
		}

		int solve() {
			pathlen = dijkstra(findjakov());
			return pathlen;
		}

		void output(FILE *outfp) {
			fprintf(outfp, "%d\n", pathlen);
		}
};

int main(void) {
	rudar task;
	task.input(stdin);
	task.solve();
	task.output(stdout);
	return 0;
}
