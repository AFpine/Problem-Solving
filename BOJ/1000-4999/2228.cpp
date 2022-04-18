#include <bits/stdc++.h>

// 2228 구간 나누기 (Dynamic programming)

// update 220418

using namespace std;

const int INF = 1e9+1;
const int minINF = -2000000001;

int N,M;

int dp[101][101];
//dp[i][j] : i번 째 수에서부터 시작해서 j개의 구간의 최대 합 (i번째 수가 어떤 구간에 속해있을 필요는 없다)
int sum[101];
//sum[i] : i번 째 수 까지의 합
int arr[101];

int divide(int s, int n)
{
	int &ret = dp[s][n];	
	if(n == 0)
	{
		return 0;
	}
	if(n < 0 || s > N)
	{
		return minINF;
	}
	if(ret != minINF)
	{
		return ret;
	}


	ret = -1000000007;
	ret = max(ret,divide(s+1,n));
	for(int i = 0;i+s<=N;++i)
	{
		ret = max(ret, divide(i+s+2, n-1) + sum[s+i] - sum[s-1]);
	}
	return ret;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for(int i = 0;i<=100;++i)
	{
		for(int j = 0;j<=60;++j)
		{
			dp[i][j] = minINF;
		}
	}
	
	cin>>N>>M;

	for(int i = 1;i<=N;++i)
	{
		cin>>arr[i];
	}

	sum[0] = 0;
	for(int i = 1;i<=N;++i)
	{
		sum[i] = sum[i-1] + arr[i];
	}

	cout<<divide(1,M);


	return 0;
}

