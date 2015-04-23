#include <cstdio>
#include <stack>
using namespace std;

int main(void)
{
	const int MOD = 1000000001;
	int N, h;
	int sum = 0;
	stack<int> S;

	scanf("%d", &N);

	for(int i = 1 ; i <= N ; ++i)
	{
		scanf("%d", &h);
		if (S.empty() || S.top() != h)
		{
			S.push(h);
		}
		else
		{
			S.pop();
			sum = (sum + i) % MOD;
		}
	}

	printf("%d\n", sum);

	return 0;
}