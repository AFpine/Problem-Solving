#include <bits/stdc++.h>

// 2248 이진수 찾기

// update 220502

using namespace std;

const int INF = 1e9+7;
const int minINF = -2e9-1;

int N,L;
long long I;
long long dp[33][33];
string result;

long long searchbinary(int n, int l)
{
	long long &ret = dp[n][l];
	if(ret != -1)
	{
		return ret;
	}
	if(n == 0 || l == 0)
	{
		return 1;
	}

	ret = searchbinary(n-1,l) + searchbinary(n-1,l-1);

	return ret;
}

void ansfunc(int n, int l, long long i)
{
	if(n == 0)
	{
		return;
	}
	if(l == 0)
	{
		for(int i = 0;i<n;++i)
		{
			result += '0';
		}
		return;
	}

	long long pivot = searchbinary(n-1,l);

	if(i <= pivot)
	{
		result += '0';
		ansfunc(n-1,l,i);
	}
	else
	{
		result += '1';
		ansfunc(n-1,l-1,i-pivot);
	}
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(dp,-1,sizeof(dp));

	cin>>N>>L>>I;

	searchbinary(N,L);

	ansfunc(N,L,I);

	cout<<result;

	return 0;
}

