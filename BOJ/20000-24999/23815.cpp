#include <bits/stdc++.h>

// 23815 똥게임

// update 220623

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 100005;

int N;
ll dp[MAX][2];

ll calculate(ll a, char c, int b)
{
	if(c == '+')
	{
		return a + b;
	}
	else if(c == '*')
	{
		return a * b;
	}
	else if(c == '-')
	{
		return a - b;
	}
	else
	{
		return a / b;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	bool incorrect = false;

	cin>>N;

	dp[0][0] = 1;
	dp[0][1] = 1;
	for(int i = 1;i<=N;++i)
	{
		char op1,x1,op2,x2;
		cin>>op1>>x1>>op2>>x2;
		x1 -= '0';
		x2 -= '0';

		dp[i][0] = max(calculate(dp[i-1][0], op1, x1), calculate(dp[i-1][0], op2, x2));
		ll temp = max(calculate(dp[i-1][1], op1, x1), calculate(dp[i-1][1], op2, x2));
		dp[i][1] = max(dp[i-1][0], temp);

		if(dp[i][0] <= 0 && dp[i][1] <= 0)
		{
			incorrect = true;
		}

		if(dp[i][0] <= 0)
		{
			dp[i][0] = -llINF;
		}
		if(dp[i][1] <= 0)
		{
			dp[i][1] = -llINF;
		}
	}

	if(incorrect)
	{
		cout<<"ddong game";
	}
	else
	{
		cout<<max(dp[N][0], dp[N][1]);
	}
	

	return 0;
}