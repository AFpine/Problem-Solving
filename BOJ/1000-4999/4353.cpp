#include <bits/stdc++.h>

// 4354 문자열 제곱

// update 220611

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 1000005;
const int MOD = 1e9+7;

string P;
int N,M;
int fail[MAX];

int KMP(const string &P1, const string &P2)
{
	N = P1.length();
	M = P2.length();

	for(int i = 1, j = 0;i<M;++i)
	{
		while(j > 0 && P2[i] != P2[j])
		{
			j = fail[j-1];
		}
		if(P2[i] == P2[j])
		{
			fail[i] = ++j;
		}
	}

	for(int i = 1, j = 0;i<N;++i)
	{
		while(j > 0 && P1[i] != P2[j])
		{
			j = fail[j-1];
		}
		if(P1[i] == P2[j])
		{
			if(j == M-1)
			{
				return (i-j);
			}
			else
			{
				++j;
			}
		}
	}
	return -1;
}

void init()
{
	fill(fail,fail+MAX,0);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while(true)
	{
		init();
		cin>>P;
		
		if(P == ".")
		{
			break;
		}
		
		int result = KMP(P+P,P);

		cout<<M/result<<"\n";

		// for(int i = N;i>=1;--i)
		// {
		// 	if(fail[N-1] == N-i)
		// 	{
		// 		cout<<N/i<<'\n';
		// 		break;
		// 	}
		// }

	}



	return 0;
}


