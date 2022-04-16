#include <bits/stdc++.h>

// 2011 Password Code

// update 220416

using namespace std;

static const int INF = 1e9+1;

int dp[5001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	int N;
	cin>>s;

	N = s.length();

	dp[0] = 1;
	dp[1] = 1;

	for(int i = 1;i<N;++i)
	{	
		if(s[i] == '0')
		{
			if(s[i-1] != '0' && ((s[i-1]-'0')*10 + (s[i]-'0') <= 26 ))
			{
				dp[i+1] = (dp[i+1] + dp[i-1]) % 1000000;
			}
			else
			{
				dp[N] = 0;
				break;
			}
		}
		else
		{
			dp[i+1] = (dp[i+1] + dp[i]) % 1000000;
			if(s[i-1] != '0' && ((s[i-1]-'0')*10 + (s[i]-'0') <= 26 ))
			{
				dp[i+1] = (dp[i+1] + dp[i-1]) % 1000000;
			}
		}
	}
	if(s[0] == '0')
	{
		dp[N] = 0;
	}
	cout<<dp[N];

	return 0;
}