#include <bits/stdc++.h>

// 16432 떡장수와 호랑이

// update 220625

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 1000005;
const int MOD = 1e9+7;

int N;
bool is[1005][10];
int dp[1005][10];
int prevv[1005];
vector<int> result;
bool correct = false;

int recur(int n, int cur)
{//n번 째 날에 cur떡을 주는 경우
	int &ret = dp[n][cur];
	if(n == N)
	{
		if(result.empty())
		{
			for(int i = n;i>=1;--i)
			{
				result.push_back(prevv[i]);
			}
		}
		return ret = INF;
	}
	if(ret != -1)
	{
		return ret;
	}

	ret = -INF;
	for(int i = 1;i<=9;++i)
	{
		if(i == cur)
		{
			continue;
		}
		if(is[n+1][i])
		{
			prevv[n+1] = i;
			ret = max(ret, recur(n+1,i));
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
		int t;
		cin>>t;
		for(int j = 1;j<=t;++j)
		{
			int temp;
			cin>>temp;
			is[i][temp] = true;
		}
	}

	int res = recur(0,0);
	if(res == -INF)
	{
		cout<<"-1";
	}
	else
	{
		reverse(result.begin(),result.end());
		for(auto &i : result)
		{
			cout<<i<<"\n";
		}
	}



	return 0;
}

