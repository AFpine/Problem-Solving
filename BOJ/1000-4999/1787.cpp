#include <bits/stdc++.h>

// 1787 문자열의 주기 예측

// update 220626

using namespace std;
typedef long long ll;
typedef pair<double,double> pii;
#define x first
#define y second

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 1000005;
const long long MOD = 1e9+7;

string S;
int N;
ll dp[MAX];
int fail[MAX];

void getFail(string S)
{//normal fail function
	int len = S.length();
	for(int i = 1, j = 0;i<len;++i)
	{
		while(j > 0 && S[i] != S[j])
		{
			j = fail[j-1];
		}
		if(S[i] == S[j])
		{
			fail[i] = ++j;
		}
	}
}

ll func(int n)
{
	if(n <= 0)
	{
		return llINF;
	}
	ll &ret = dp[n];
	if(ret != -1)
	{
		return ret;
	}
	if(fail[n] == 0)
	{
		return ret = llINF;
	}
	
	//fail[n]-1 :  index
	ret = min((ll)fail[n], func(fail[n]-1));

	if(ret > (n+1)/2)
	{//뒤쪽 문자열이 앞쪽 문자열보다 길면 안된다
		ret = llINF;
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
	cin>>S;

	getFail(S);

	ll result = 0;
	for(int i = 0;i<N;++i)
	{
		ll temp = func(i);

		if(temp != llINF)
		{
			result += i + 1 - temp;
		}
	}

	cout<<result;

	return 0;
}