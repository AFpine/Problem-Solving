#include <bits/stdc++.h>

// 11562 백양로 브레이크

// update 220509

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;

int n,m,k;
int u,v,b;
int s,e;
int dist[251][251];
// vector<pair<int,int>> adj[251];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for(int i = 1;i<=250;++i)
	{
		for(int j = 1;j<=250;++j)
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

	cin>>n>>m;

	for(int i = 1;i<=m;++i)
	{
		cin>>u>>v>>b;		
		if(b == 0)
		{
			dist[u][v] = 0;
			dist[v][u] = 1;
		}
		else
		{
			dist[u][v] = 0;
			dist[v][u] = 0;
		}
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

	cin>>k;
	for(int i = 1;i<=k;++i)
	{
		cin>>s>>e;
		cout<<dist[s][e]<<'\n';
	}


	return 0;
}

