#include <bits/stdc++.h>

// 1786 찾기

// update 220611

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 1000005;
const int MOD = 1e9+7;

string T,P;
int N,M;
int fail[MAX];
vector<int> result;

void makeFail()
{
	for(int i = 1, j = 0;i<M;++i)
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
}

void KMP()
{

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	getline(cin,T);
	getline(cin,P);

	N = T.length();
	M = P.length();

	makeFail();

	for(int i = 0, j = 0;i<N;++i)
	{
		while(j > 0 && T[i] != P[j])
		{
			j = fail[j-1];
		}
		if(T[i] == P[j])
		{
			if(j == M-1)
			{
				result.push_back(i-(M-1)+1);
				j = fail[j];
			}
			else
			{
				++j;
			}
		}
	}	

	cout<<result.size()<<"\n";
	for(auto &i : result)
	{
		cout<<i<<" ";
	}

	return 0;
}


