#include <bits/stdc++.h>

// 1562 stairs number (Dynamic programming, bitmask)
// 아니 나 이거 혼자 풀었다........ 기분 너무 좋다...

// update 220419

using namespace std;

const int INF = 1e9+1;
const int minINF = -1e9-1;

int N;
long long result = 0;
int dp[10][101][1<<11];


int stairnum(int k, int n, int idx)
{
	if(n == 1)
	{
		if((idx & 0b1111111111) == 0b1111111111)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if(dp[k][n][idx] != 0)
	{
		return dp[k][n][idx];
	}

	int &ret = dp[k][n][idx];
	
	ret = 0;

	if(k == 9)
	{
		ret += max(ret,stairnum(k-1,n-1,(idx|(1<<k-1))));
	}
	else if(k == 0)
	{
		ret += max(ret,stairnum(k+1,n-1,(idx|(1<<k+1))));
	}
	else
	{
		ret = (ret + stairnum(k-1,n-1,(idx|(1<<k-1))) ) % 1000000000;
		ret = (ret + stairnum(k+1,n-1,(idx|(1<<k+1))) ) % 1000000000;
	}

	return ret;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N;

	for(int i = 1;i<=9;++i)
	{
		dp[i][N][1<<i] = stairnum(i,N,1<<i);
		//cout<<dp[i][N][1<<i]<<'\n';
	}

	for(int i = 1;i<=9;++i)
	{
		result = (result + dp[i][N][1<<i]) % 1000000000;
	}

	cout<<result;

	return 0;
}

