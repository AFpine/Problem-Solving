#include <bits/stdc++.h>

// 1102 발전소

// update 220504

using namespace std;

const int INF = 1e9+7;
const int minINF = -2e9-1;
const int MAX = 100001;
const int BMAX = 17;

int N,P;
int dp[1<<BMAX];
int cost[BMAX][BMAX];
vector<int> on, off;
string s;
int result = INF;

int fix(int status, int p)
{
	int &ret = dp[status];

	if(ret != -1)
	{
		return ret;
	}
	if(p <= 0)
	{
		return 0;
	}

	ret = INF;

	for(int i = 1;i<=N;++i)
	{	
		if((status & (1<<i)) == 0)
		{
			continue;
		}
		for(int j = 1;j<=N;++j)
		{
			if((status & (1<<j)) == 0)
			{
				int temp = (status | (1<<j));
				ret = min(ret, fix(temp,p-1) + cost[i][j]);
			}
		}
	}

	return ret;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(dp,-1,sizeof(dp));

	cin>>N;

	for(int i = 1;i<=N;++i)
	{
		for(int j = 1;j<=N;++j)
		{
			cin>>cost[i][j];
		}
	}

	cin>>s;
	int status = 0;
	for(int i = 1;i<=N;++i)
	{
		if(s[i-1] == 'Y')
		{	
			status |= (1<<i);
			on.push_back(i);
		}
		else
		{
			off.push_back(i);
		}
	}

	cin>>P;

	result = fix(status,P-on.size());

	if(result == INF)
	{
		cout<<"-1";
	}
	else
	{
		cout<<result;
	}

	return 0;
}

