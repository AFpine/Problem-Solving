#include <bits/stdc++.h>

// 2225 SumDivide

// update 220415

using namespace std;

static const int INF = 1e9+1;

long long dp[201][201];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N,K;

	cin>>N>>K;

	for(int i = 0;i<=N;++i)
	{
		dp[1][i] = 1;
	}

	for(int i = 2;i<=K;++i)
	{
		for(int j = 0;j<=N;++j)
		{
			for(int k = 0;k<=j;++k)
			{
				dp[i][j] = (dp[i][j] + dp[i-1][k]) % 1000000000;
			}
		}
	}

	cout<<dp[K][N] % 1000000000;


	return 0;
}