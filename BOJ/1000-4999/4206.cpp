#include <bits/stdc++.h>

// 4206 피보나치 단어

// update 220626

using namespace std;
typedef long long ll;
typedef pair<double,double> pii;
#define x first
#define y second

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 100005;
const long long MOD = 1e9+7;

int N;
string P;
string fs[105];
ll dp[105];
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

void baseKMP(string P)
{
	fill(dp,dp+29,0);
	if(P.length() == 0)
	{
		return;
	}
	for(int k = 0;k<=28;++k)
	{
		if(fs[k].length() < P.length())
		{
			continue;
		}
		for(int i = 0, j = 0; i<fs[k].length();++i)
		{
			while(j > 0 && fs[k][i] != P[j])
			{
				j = fail[j-1];
			}
			if(fs[k][i] == P[j])
			{
				if(j == P.length()-1)
				{
					dp[k]++;
					j = fail[j];
				}
				else
				{
					j++;
				}
			}
		}
	}
}

ll KMP(string S, string P)
{	
	if(S.size() == 0 || P.size() == 0)
	{
		return 0;
	}
	if(S.length() < P.length())
	{
		return 0;
	}

	ll result = 0;
	int slen = S.length();
	int plen = P.length();
	for(int i = 0, j = 0; i<slen;++i)
	{
		while(j > 0 && S[i] != P[j])
		{
			j = fail[j-1];
		}
		if(S[i] == P[j])
		{
			if(j == plen-1)
			{
				result++;
				j = fail[j];
			}
			else
			{
				j++;
			}
		}
	}

	return result;
}

string getMid(const string &a, const string &b, int len)
{
	if(len <= 1)
	{
		return "";
	}
	string temp = a+b;
	temp = temp.substr(a.size()-len+1, 2*len-2);
	return temp;
}

ll recur(int n)
{
	ll &ret = dp[n];

	if(ret != -1)
	{
		return ret;
	}

	int plen = P.length();
	if(n % 2)
	{//odd
		ret = recur(n-1)+recur(n-2)+KMP(getMid(fs[26],fs[27],plen),P);
	}
	else
	{//even
		ret = recur(n-1)+recur(n-2)+KMP(getMid(fs[27],fs[27],plen),P);
	}

	return ret;
}

void output(int t, ll n)
{
	cout<<"Case "<<t<<": "<<n<<'\n';
}

void preprocess()
{
	fs[0] = "0";
	fs[1] = "1";
	fs[2] = "10";
	for(int i = 3;i<=28;++i)
	{
		fs[i] = fs[i-1] + fs[i-2];
	}
}

void init()
{
	fill(fail,fail+MAX,0);
	fill(dp,dp+105,-1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int turn = 1;
	preprocess();
	while(cin>>N)
	{
		init();

		cin>>P;

		getFail(P);

		if(N <= 27)
		{
			ll result = KMP(fs[N],P);
			output(turn++,result);
		}
		else
		{
			baseKMP(P);
			output(turn++,recur(N));
		}
	}
	
	

	return 0;
}