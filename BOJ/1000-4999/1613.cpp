#include <bits/stdc++.h>

// 1613 역사

// update 220506

using namespace std;

const long long INF = 1e18;
const int minINF = -2e9-1;

int N,K,S;
long long dist[401][401];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for(int i = 1;i<=400;++i)
	{
		for(int j = 1;j<=400;++j)
		{
			dist[i][j] = INF;
		}
	}

	cin>>N>>K;

	for(int i = 1;i<=K;++i)
	{
		int u,v;
		cin>>u>>v;
		dist[u][v] = 1;
	}

	for(int k = 1;k<=N;++k)
	{
		for(int i = 1;i<=N;++i)
		{
			for(int j = 1;j<=N;++j)
			{
				if(dist[i][j] > dist[i][k] + dist[k][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	cin>>S;

	for(int i = 1;i<=S;++i)
	{
		int u,v;
		cin>>u>>v;

		if(dist[u][v] == INF && dist[v][u] == INF)
		{
			cout<<"0\n";
		}
		else if(dist[u][v] < dist[v][u])
		{
			cout<<"-1\n";
		}
		else
		{
			cout<<"1\n";
		}
	}
	


	return 0;
}

