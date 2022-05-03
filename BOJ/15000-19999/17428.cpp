#include <bits/stdc++.h>

// 17428 K번째 괄호 문자열

// update 220503

using namespace std;

const int INF = 1e9+7;
const int minINF = -2e9-1;

int N;
long long K;
long long dp[51][51];
string ans;

long long paren(int n, int m)
{
	long long& ret = dp[n][m];
	if(ret != -1)
	{
		return ret;
	}
	if(n == 0 || m == 0)
	{
		return 1;
	}
	else if(m > n-m)
	{
		return 0;
	}
	
	ret = paren(n-1,m-1) + paren(n-1,m);

	return ret;
}

void answer(int n, int m, long long k)
{
	if(n == 0)
	{
		return;
	}
	if(m == 0)
	{
		for(int i = 0;i<n;++i)
		{
			ans += ')';
		}
		return;
	}

	long long pivot = paren(n-1,m);
	if(k < pivot)
	{
		ans += ')';
		answer(n-1,m,k);
	}
	else
	{
		ans += '(';
		answer(n-1,m-1,k-pivot);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(dp,-1,sizeof(dp));

	cin>>N>>K;

	paren(N,N/2);

	long long maxparen = paren(N,N/2);
	
	//cout<<maxparen<<'\n';

	if(maxparen < K+1)
	{
		cout<<"-1";
		return 0;
	}

	answer(N,N/2,maxparen-(K+1));

	cout<<ans;

	return 0;
}

