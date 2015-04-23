#include<iostream>
using namespace std;

int main ()
{
	int N; cin >> N;
	const int mod = 1000000007;

	int dp[5001][2];

	int sad = 1, prije = 0;

	for(int hi=0; hi<=N; hi++)
	{
		for(int n=0; n<=N; n++)
		{
			if( n == 0 ) dp[n][sad] = 1;
			else if( hi == 0 ) dp[n][sad] = 0;
			else if( n < hi ) dp[n][sad] = dp[n][prije];
			else dp[n][sad] = (dp[n][prije] + dp[n-hi][prije]) %mod;
		}
		swap( prije, sad );
	}

	cout << dp[N][prije] << endl;

	return 0;
}
