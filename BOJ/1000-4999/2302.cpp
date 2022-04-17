#include <bits/stdc++.h>

// 2302 극장 좌석

// update 220417

using namespace std;

static const int INF = 1e9+1;

int dp[41];
bool VIP[41];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N,M;
	int vip;

	cin>>N>>M;

	for(int i = 0;i<M;++i)
	{
		cin>>vip;
		VIP[vip] = true;
	}
	
	dp[0] = 1;
	dp[1] = 1;

	for(int i = 2;i<=N;++i)
	{
		if(VIP[i] == true || VIP[i-1] == true)
		{
			dp[i] += dp[i-1];
		}
		else
		{
			dp[i] += dp[i-1]+dp[i-2];
		}
	}

	cout<<dp[N];

	return 0;
}