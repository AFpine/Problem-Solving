#include <bits/stdc++.h>

// 2631 Line up (LIS)

// update 220416

using namespace std;

static const int INF = 1e9+1;

int line[201];
int dp[201];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int lis=0;
	cin>>N;

	for(int i = 1;i<=N;++i)
	{
		cin>>line[i];
	}

	for(int i = 1;i<=N;++i)
	{
		dp[i] = 1;
		for(int j = 1;j<=i;++j)
		{
			if(line[i] > line[j])
			{
				dp[i] = max(dp[i],dp[j]+1); 
			}
		}
	}

	for(int i = 1;i<=N;++i)
	{
		if(lis < dp[i])
		{
			lis = dp[i];
		}
	}

	cout<<N-lis;

	return 0;
}