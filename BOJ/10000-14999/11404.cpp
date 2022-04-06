#include <bits/stdc++.h>

using namespace std;
// 11404 Floyd (Floyd-Warshall)

// update 220316

int dist[101][101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m;
	int a,b,c;

	for(int i = 0;i<=100;++i)
	{
		for(int j = 0;j<=100;++j)
		{
			if(i == j)
			{
				dist[i][j] = 0;
			}
			else
			{
				dist[i][j] = 100000000;
			}
		}
	}
	
	cin>>n;
	cin>>m;

	for(int i = 0;i<m;++i)
	{
		cin>>a>>b>>c;
		if(dist[a][b] > c)
		{
			dist[a][b] = c;
		}
	}

	for(int i = 1;i<=n;++i)
	{
		for(int j = 1;j<=n;++j)
		{
			for(int k = 1;k<=n;++k)
			{
				if(dist[j][k] > dist[j][i] + dist[i][k])
				{
					dist[j][k] = dist[j][i] + dist[i][k];
				}
			}
		}
	}

	for(int i = 1;i<=n;++i)
	{
		for(int j = 1;j<=n;++j)
		{
			if(dist[i][j] == 100000000)
			{
				dist[i][j] = 0;
			}
			cout<<dist[i][j]<<" ";
		}
		cout<<"\n";
	}



}