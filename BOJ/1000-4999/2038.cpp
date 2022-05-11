#include <bits/stdc++.h>

// 2038 골롱 수열

// update 220511

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;

long long n;
vector<long long> dp;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n;
	long long idx = 4;
	long long value = 5;
	dp.push_back(0);		
	dp.push_back(1);
	dp.push_back(3);
	dp.push_back(5);
	//dp[0] = 0, dp[1] = 1, dp[2] = 3, dp[3] = 5

	if(n <= 5)
	{
		idx = (long long)(lower_bound(dp.begin(),dp.end(),n)-dp.begin());
	}
	else
	{
		while(value < n)
		{
			auto tempidx = lower_bound(dp.begin(),dp.end(),idx);
			value = dp[idx-1] + (long long)(tempidx-dp.begin());
			dp.push_back(value);
			idx++;
		}
		idx--;
	}

	cout<<idx;

	return 0;
}

