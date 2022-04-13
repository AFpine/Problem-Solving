#include <bits/stdc++.h>

// 5582 LCS

// update 220413

using namespace std;

static const int INF = 1e9+1;

int LCS[4001][4001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int result = 0;
	string a,b;

	cin>>a>>b;

	for(int i = 1;i<=a.length();++i)
	{
		for(int j = 1;j<=b.length();++j)
		{
			if(a[i-1] == b[j-1])
			{
				LCS[i][j] = LCS[i-1][j-1] + 1;
			}
			else
			{
				LCS[i][j] = 0;
			}
		}
	}

	for(int i = 1;i<=a.length();++i)
	{
		for(int j = 1;j<=b.length();++j)
		{
			if(LCS[i][j] > result)
			{
				result = LCS[i][j];
			}
		}
	}

	cout<<result;
	

	return 0;
}