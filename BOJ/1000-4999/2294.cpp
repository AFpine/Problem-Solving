#include <bits/stdc++.h>

// 2294 Coin 2

// update 220413

using namespace std;

static const int INF = 1e9+1;

int coin[101];
int countcoin[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,k;
	int a;
	int result = INF;

	cin>>n>>k;

	for(int i = 1;i<=n;++i)
	{
		cin>>coin[i];
	}

	for(int i = 1;i<=100000;++i)
	{
		countcoin[i] = INF;
	}
	
	countcoin[0] = 0;
	for(int i = 1;i<=n;++i)
	{
		for(int j = coin[i];j<=k;++j)
		{
			countcoin[j] = min(countcoin[j], countcoin[j-coin[i]] + 1);
		}
	}	
	
	if(countcoin[k] == INF)
	{
		cout<<"-1";
	}
	else
	{
		cout<<countcoin[k];
	}

	return 0;
}