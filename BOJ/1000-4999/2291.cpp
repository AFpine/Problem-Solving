#include <bits/stdc++.h>

// 2291 Sequence

// update 220503

using namespace std;

const int INF = 1e9+7;
const int minINF = -2e9-1;

int N,M;
long long K;
long long dp[11][221][221];
vector<int> ans;

long long f(int n, int m, int prev)
{//n is sequence, m is remain number, prev is previous number
	long long &ret = dp[n][m][prev];
	if(ret != -1)
	{
		return ret;
	}
	if(n == 0)
	{
		if(m == 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	ret = 0;
	for(int i = prev;i<=m;++i)
	{
		ret += f(n-1,m-i,i);
	}

	return ret;
}

void tracking(int n, int m, int prev, long long k)
{
	if(n == 1)
	{
		ans.push_back(m);
		return;
	}

	for(int i = prev;i<=m;++i)
	{
		if(dp[n-1][m-i][i] == -1)
		{
			continue;
		}
		if(k > dp[n-1][m-i][i])
		{
			k -= dp[n-1][m-i][i];
			continue;
		}
		ans.push_back(i);
		tracking(n-1,m-i,i,k);
		return;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(dp,-1,sizeof(dp));

	cin>>N>>M>>K;

	f(N,M,1);

	tracking(N,M,1,K);

	for(auto x : ans)
	{
		cout<<x<<" ";
	}

	return 0;
}

