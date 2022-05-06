#include <bits/stdc++.h>

// 11657 타임머신

// update 220506

using namespace std;

const long long INF = 1e18;
const int minINF = -2e9-1;

int N,M;
int A,B,C;
long long dist[501];
vector<pair<int,int>> adj[501];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	bool mcycle = false;

	for(int i = 1;i<=500;++i)
	{
		dist[i] = INF;
	}

	cin>>N>>M;

	for(int i = 1;i<=M;++i)
	{
		cin>>A>>B>>C;
		adj[A].push_back({B,C});
	}

	dist[1] = 0;

	for(int i = 1;i<=N;++i)
	{
		for(int j = 1;j<=N;++j)
		{
			for(auto x : adj[j])
			{
				int next = x.first;
				int cost = x.second;
				if((dist[j] != INF) && (dist[next] > dist[j] + cost))
				{
					dist[next] = dist[j] + cost;
					if(i == N)
					{
						mcycle = true;
					}
				}
			}
		}
	}

	if(mcycle)
	{
		cout<<"-1";
	}
	else
	{
		for(int i = 2;i<=N;++i)
		{	
			if(dist[i] == INF)
			{
				cout<<"-1"<<'\n';
			}
			else
			{
				cout<<dist[i]<<'\n';
			}
		}
	}


	return 0;
}

