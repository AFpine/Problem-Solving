#include <bits/stdc++.h>

// 2157 Travel

// update 220421

using namespace std;

const int INF = 1e9+7;
const int minINF = -2e9-1;

struct City
{
	vector<int> edge;
};

int N,M,K;
int result = 0;
City city[301];
int food[301][301];
int dp[301][301];

int dynamicprogramming(int s, int m)
{
	if(m > M)
	{
		return minINF;
	}
	if(s == N)
	{
		return 0;
	}
	if(dp[s][m] != -1)
	{
		return dp[s][m];
	}

	int &ret = dp[s][m];

	ret = minINF;
	for(int i = s;i<=N;++i)
	{
		if(food[s][i] > 0)
		{
			dp[s][m] = max(dp[s][m], dynamicprogramming(i,m+1) + food[s][i]);
		}
	}

	return ret;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>M>>K;

	for(int i = 1;i<=300;++i)
	{
		for(int j = 1;j<=300;++j)
		{
			dp[i][j] = -1;
		}
	}

	for(int i = 1;i<=K;++i)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if(food[a][b] < c)
		{
			food[a][b] = c;
		}
	}

	result = dynamicprogramming(1,1);

	for(int i = 2;i<=M;++i)
	{
		if(result < dp[N][i])
		{
			result = dp[N][i];
		}
	}

	cout<<result;



	return 0;
}

