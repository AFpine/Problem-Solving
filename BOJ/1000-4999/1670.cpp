#include <bits/stdc++.h>

// 1670 정상회담 2

// update 220422

using namespace std;

const int INF = 1e9+7;
const int minINF = -2e9-1;

int N;

long long dp[10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N;

	dp[0] = 1;
	dp[2] = 1;
	dp[4] = 2;

	for(int i = 6;i<=N;i+=2)
	{
		for(int j = 0;j<=i-2;j+=2)
		{
			dp[i] += (dp[j]*dp[i-2-j]);
			dp[i] %= 987654321;
		}
	}

	cout<<dp[N];

	return 0;
}

