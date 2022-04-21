#include <bits/stdc++.h>

// 2229 조 짜기 (Dynamic programming (resursion))

// update 220421

using namespace std;

const int INF = 1e9+7;
const int minINF = -2e9-1;

int N;
int arr[1001];
int maxval[1001][1001];
int minval[1001][1001];
int dp[1001][1001];

int making_group(int i, int j)
{
	if(i >= j)
	{
		return 0;
	}
	if(dp[i][j] != -1)
	{
		return dp[i][j];
	}

	int &ret = dp[i][j];

	ret = (maxval[i][j] - minval[i][j]);

	for(int k = i;k<=j;++k)
	{
		ret = max(dp[i][j], making_group(i,k)+making_group(k+1,j));
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N;

	for(int i = 1;i<=1000;++i)
	{
		for(int j = 1;j<=1000;++j)
		{
			dp[i][j] = -1;
		}
	}

	for(int i = 1;i<=N;++i)
	{
		cin>>arr[i];
		maxval[i][i] = arr[i];
		minval[i][i] = arr[i];
	}

	for(int i = 1;i<=N;++i)
	{
		for(int j = i+1;j<=N;++j)
		{
			if(maxval[i][j-1] < arr[j])
			{
				maxval[i][j] = arr[j];
			}
			else
			{
				maxval[i][j] = maxval[i][j-1];
			}
			if(minval[i][j-1] > arr[j])
			{
				minval[i][j] = arr[j];
			}
			else
			{
				minval[i][j] = minval[i][j-1];
			}
		}
	}

	cout<<making_group(1,N);


	return 0;
}

