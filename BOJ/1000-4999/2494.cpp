#include <bits/stdc++.h>

// 2494 숫자 맞추기	

// update 220502

using namespace std;

const int INF = 1e9+7;
const int minINF = -2e9-1;

int N;
string s;
string goal;
int num[10001];
int dp[10001][10];
int result[10001];

int match(int n, int leftspin)
{
	int &ret = dp[n][leftspin];
	if(ret != -1)
	{
		return ret;
	}
	if(n > N)
	{
		return 0;
	}

	int curnum = num[n];
	curnum += leftspin;
	if(curnum >= 10)
	{
		curnum -= 10;
	}
	if(curnum < 0)
	{
		curnum += 10;
	}

	int diff = (goal[n-1]-'0') - curnum;
	int lspin = abs(diff+10) % 10;
	int rspin = abs(diff-10) % 10;

	ret = min(match(n+1,(leftspin+lspin)%10)+lspin, match(n+1,leftspin)+rspin);

	return ret;
}

void tracking(int n, int leftspin)
{
	if(n > N)
	{
		return;
	}

	int curnum = num[n];
	curnum += leftspin;
	if(curnum >= 10)
	{
		curnum -= 10;
	}
	if(curnum < 0)
	{
		curnum += 10;
	}

	int diff = (goal[n-1]-'0') - curnum;
	int lspin = abs(diff+10) % 10;
	int rspin = abs(diff-10) % 10;

	if(dp[n+1][leftspin] + rspin > dp[n+1][(leftspin+lspin)%10] + lspin)
	{
		result[n] = lspin;
		tracking(n+1,(leftspin+lspin)%10);
		return;
	}
	else
	{
		result[n] = -rspin;
		tracking(n+1,leftspin);
		return;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(dp,-1,sizeof(dp));

	cin>>N;
	cin>>s;
	cin>>goal;

	for(int i = 1;i<=N;++i)
	{
		num[i] = (s[i-1])-('0');
	}

	cout<<match(1,0)<<'\n';
	tracking(1,0);

	for(int i = 1;i<=N;++i)
	{
		cout<<i<<" "<<result[i]<<'\n';
	}

	return 0;
}

