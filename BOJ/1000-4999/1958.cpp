#include <bits/stdc++.h>

// 1958 LCS 3

// update 220501

using namespace std;

const int INF = 1e9+7;
const int minINF = -2e9-1;

string s1,s2,s3;
int dp[101][101][101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>s1>>s2>>s3;

	for(int i = 1;i<=s1.length();++i)
	{
		for(int j = 1;j<=s2.length();++j)
		{
			for(int k = 1;k<=s3.length();++k)
			{
				if(s1[i-1] == s2[j-1] && s1[i-1] == s3[k-1])
				{
					dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
				}
				else
				{
					dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][k]);
					dp[i][j][k] = max(dp[i][j][k],dp[i][j-1][k]);
					dp[i][j][k] = max(dp[i][j][k],dp[i][j][k-1]);
				}
			}
		}
	}
	
	cout<<dp[s1.length()][s2.length()][s3.length()];

	return 0;
}

