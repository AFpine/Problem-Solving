#include <bits/stdc++.h>

// 2306 DNA

// update 220421

using namespace std;

const int INF = 1e9+7;
const int minINF = -2e9-1;

int N;
string S;
int dp[501][501];

int DNA(int s, int e)
{	
	if(s >= e)
	{
		return dp[s][e] = 0;
	}
	if(dp[s][e] != -1)
	{
		return dp[s][e];
	}

	int &ret = dp[s][e];

	ret = minINF;
	
	if((S[s] == 'a' && S[e] == 't') || (S[s] == 'g' && S[e] == 'c'))
	{
		ret = max(ret, DNA(s+1,e-1) + 2);
	}
	for(int i = s;i<e;++i)
	{
		ret = max(ret, DNA(s,i) + DNA(i+1,e));
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for(int i = 0;i<=500;++i)
	{
		for(int j = 0;j<=500;++j)
		{
			dp[i][j] = -1;
		}
	}

	cin>>S;

	cout<<DNA(0,S.length()-1);

	return 0;
}

