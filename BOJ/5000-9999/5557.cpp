#include <bits/stdc++.h>

// 5557 1학년

// update 220626

using namespace std;
typedef long long ll;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 105;
const int MOD = 1e9+7;

int N;
int arr[MAX];
ll dp[MAX][21];

ll recur(int n, int cur)
{
	if(n == N)
	{
		if(cur == arr[N])
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	ll &ret = dp[n][cur];
	if(ret != -1)
	{
		return ret;
	}
	
	ret = 0;
	
	if(cur + arr[n] >= 0 && cur + arr[n] <= 20)
	{
		ret += recur(n+1,cur + arr[n]);
	}
	if(cur - arr[n] >= 0 && cur - arr[n] <= 20)
	{
		ret += recur(n+1,cur - arr[n]);
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
		cin>>arr[i];
	}

	ll result = recur(2,arr[1]);

	cout<<result;


	return 0;
}

