#include <bits/stdc++.h>

// 1305 광고

// update 220612

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 1000005;
const int MOD = 1e9+7;

int L;
string S;
int fail[MAX];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>L;

	cin>>S;

	for(int i = 1, j = 0;i<L;++i)
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

	cout<<L-fail[L-1];

	return 0;
}


