#include <bits/stdc++.h>

// 2401 최대 문자열 붙여넣기

// update 220612

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 505;
const int MOD = 1e9+7;

int N,L;
string W[505];
int dp[100005];
int fail[501][10001];
int shortj[505];

void getFail(int k)
{
	int m = W[k].size();
	for(int i = 1, j = 0;i<m;++i)
	{
		while(j > 0 && W[k][i] != W[k][j])
		{
			j = fail[k][j-1];
		}
		if(W[k][i] == W[k][j])
		{
			fail[k][i] = ++j;
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string S;
	cin>>S;

	L = S.length();

	cin>>N;
	for(int i = 0;i<N;++i)
	{
		cin>>W[i];
		getFail(i);
	}

	for(int i = 0;i<L;++i)
	{
		dp[i+1] = max(dp[i+1],dp[i]);
		for(int j = 0;j<N;++j)
		{
			while(shortj[j] > 0 && S[i] != W[j][shortj[j]])
			{
				shortj[j] = fail[j][shortj[j]-1];
			}
			if(S[i] == W[j][shortj[j]])
			{
				if(shortj[j] == W[j].size()-1)
				{
					dp[i+1] = max(dp[i+1], dp[i-W[j].size()+1]+shortj[j]+1);
					//짧은 문자열의 길이 : short[j]+1 		// dp[i-W[j].size()+1] : dp[i] 에서 짧은 문자열의 길이 만큼 전의 값 + 1
					shortj[j] = fail[j][shortj[j]];
				}
				else
				{
					shortj[j]++;
				}
			}
		}
	}

	cout<<dp[L];

	return 0;
}


