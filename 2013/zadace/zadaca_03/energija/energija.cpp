#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

typedef long long llint;

const int offset = 131072;
const int MAXNODES = 262150;
const llint INF = 1000000000000000000LL;

struct tournament {
	llint tree[MAXNODES];
	int from, to;
	
	tournament() {
		for(int i = 1; i < 2 * offset; ++i)
			tree[i] = INF;
	}
	
	void set(int index, llint val) {
		index += offset;
		tree[index] = val;
		for(index /= 2; index; index /= 2)
			tree[index] = min(tree[2 * index], tree[2 * index + 1]);
	}
	
	llint query(int t, int lo, int hi) {
		if(lo >= to || hi <= from) return INF;
		if(lo >= from && hi <= to) return tree[t];
		int mid = (lo + hi) / 2;
		return min(query(2 * t, lo, mid), query(2 * t + 1, mid, hi));
	}
	
	llint query(int l, int r) {
		from = l; to = r;
		return query(1, 0, offset);
	}
};

tournament T_min, T_max;
set<int> S;

int main(void) {
	
	int L; scanf("%d", &L);

	while(1) {
		char comm[11];
		int a; llint b;
		scanf("%s", comm);
		if(comm[0] == 'E') break;
		if(comm[0] == 'A') {
			scanf("%d%I64d", &a, &b);
			S.insert(a);
			T_min.set(a, b);
			T_max.set(a, -b);
		}
		if(comm[0] == 'D') {
			scanf("%d", &a);
			T_min.set(a, INF);
			T_max.set(a, INF);
			S.erase(a);
		}
		if(comm[0] == 'Q') {
			scanf("%I64d", &b);
			int lo = 0, hi = L, mid;
			while(lo < hi) {
				int mid = (lo + hi + 1) / 2;
				llint diff = - T_max.query(0, mid + 1) - T_min.query(0, mid + 1);
				if(diff <= b / mid) lo = mid; else hi = mid - 1;
			}
			set<int>::iterator it = S.upper_bound(lo);
			--it;
			printf("%d\n", *it);
		}
	}
	
	return 0;
	
}
