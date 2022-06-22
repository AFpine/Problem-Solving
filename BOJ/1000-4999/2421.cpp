#include <bits/stdc++.h>

// 2421 저금통

// update 220622

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 1000005;
const long long MOD = 1e9+7;

bool prime[MAX];
long long dp[1005][1005];
int N;

void makePrime()
{
	fill(prime,prime+MAX,true);
	prime[1] = false;
	prime[2] = true;
	for(int i = 4;i<MAX;i+=2)
	{
		prime[i] = false;
	}
	for(int i = 3;i<MAX;++i)
	{
		if(!prime[i])
		{
			continue;
		}
		for(long long j = (long long)i*i;j<MAX;j+=(i*2))
		{
			prime[j] = false;
		}
	}
}

int pw10(int n)
{
	int ret = 1;
	while(n > 0)
	{
		n /= 10;
		ret *= 10;
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N;

	makePrime();

	dp[0][0] = 0;
	dp[0][1] = 0;
	dp[1][0] = 0;
	dp[1][1] = 0;

	for(int i = 1;i<=N;++i)
	{
		for(int j = 1;j<=N;++j)
		{
			if(prime[i*(pw10(j))+j] && (i*(pw10(j))+j != 11))
			{
				dp[i][j] = max(dp[i][j-1], dp[i-1][j]) + 1;
			}
			else
			{
				dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
			}
		}
	}

	cout<<dp[N][N];


	return 0;
}