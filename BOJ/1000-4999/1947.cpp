#include <bits/stdc++.h>

// 1947 Gift delivery (Dynamic programming)

// update 220421

using namespace std;

const int INF = 1e9+7;
const int minINF = -2e9-1;

int N;
int dp[1000001];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N;

	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 2;
	dp[4] = 9;
	dp[5] = 44;

	for(int i = 6;i<=N;++i)
	{
		dp[i] = (((long long)(dp[i-1]+dp[i-2])%1000000000)*(long long)(i-1))%1000000000;
	}

	cout<<dp[N];


	return 0;
}

