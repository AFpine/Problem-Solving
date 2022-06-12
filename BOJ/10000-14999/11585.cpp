#include <bits/stdc++.h>

// 11585 속타는 저녁 메뉴

// update 220612

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 1000005;
const int MOD = 1e9+7;

int N;
string S,P;
int fail[MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N;

	for(int i = 1;i<=N;++i)
	{
		char temp;
		cin>>temp;
		P += temp;
	}
	for(int i = 1;i<=N;++i)
	{
		char temp;
		cin>>temp;
		S += temp;
	}
	
	for(int i = 1, j = 0;i<N;++i)
	{
		while(j > 0 && P[i] != P[j])
		{
			j = fail[j-1];
		}
		if(P[i] == P[j])
		{
			fail[i] = ++j;
		}
	}

	S = S+S;

	int cnt = 0;
	for(int i = 0, j = 0; i<2*N-1;++i)
	{
		while(j > 0 && S[i] != P[j])
		{
			j = fail[j-1];
		}
		if(S[i] == P[j])
		{
			if(j == N-1)
			{
				cnt++;
				j = fail[j];
			}
			else
			{
				++j;
			}
		}
	}
	
	while(cnt != 1 && N % cnt == 0)
	{
		int temp = gcd(N,cnt);
		N /= temp;
		cnt /= temp;
	}

	cout<<cnt<<"/"<<N;

	
	return 0;
}


