#include <bits/stdc++.h>

// 14938 Sugang ground

// update 220325

using namespace std;

static const int INF = 100000000;

int dist[101][101];
int item[101];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,m,r;
	int a,b,l;
	int result = 0;
	int sum = 0;

	cin>>n>>m>>r;

	for(int i = 1;i<=n;++i)
	{
		for(int j = 1;j<=n;++j)
		{
			if(i == j)
			{
				dist[i][j] = 0;
			}
			else
			{
				dist[i][j] = INF;
			}
		}
	}
	for(int i = 1;i<=n;++i)
	{
		cin>>item[i];
	}

	for(int i = 1;i<=r;++i)
	{
		cin>>a>>b>>l;
		dist[a][b] = l;
		dist[b][a] = l;
	}

	for(int k = 1;k<=n;++k)
	{
		for(int i = 1;i<=n;++i)
		{
			for(int j = 1;j<=n;++j)
			{
				if(dist[i][j] > dist[i][k] + dist[k][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	for(int i = 1;i<=n;++i)
	{
		sum = 0;
		for(int j = 1;j<=n;++j)
		{
			if(dist[i][j] <= m)
			{
				sum += item[j];
			}
		}
		if(sum > result)
		{
			result = sum;
		}
	}

	cout<<result<<'\n';

	return 0;
	
}