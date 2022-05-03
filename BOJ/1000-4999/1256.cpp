#include <bits/stdc++.h>

// 1256 Dictionary

// update 220503

using namespace std;

const int INF = 1e9+7;
const int minINF = -2e9-1;

int N,M;
long long K;
long long dp[101][101];
string ans;

long long dict(int n, int m)
{
	long long &ret = dp[n][m];
	if(ret != -1)
	{
		return ret;
	}
	if(n == 0 || m == 0)
	{
		return 1;
	}

	ret = min((long long)1000000001,dict(n-1,m) + dict(n,m-1));

	return ret;
}

void result(int n, int m, long long k)
{
	if(n == 0)
	{
		for(int i = 0;i<m;++i)
		{
			ans += 'z';
		}
		return;
	}
	if(m == 0)
	{
		for(int i = 0;i<n;++i)
		{
			ans += 'a';
		}
		return;
	}
	long long pivot = dict(n-1,m);
	if(k <= pivot)
	{
		ans += 'a';
		result(n-1,m,k);
	}
	else
	{
		ans += 'z';
		result(n,m-1,k-pivot);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(dp,-1,sizeof(dp));

	cin>>N>>M>>K;

	dict(N,M);

	long long maxdict = dict(N,M);

	if(maxdict < K)
	{
		cout<<"-1";
		return 0;
	}

	result(N,M,K);

	cout<<ans;

	return 0;
}

