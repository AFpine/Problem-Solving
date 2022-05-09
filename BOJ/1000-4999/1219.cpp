#include <bits/stdc++.h>

// 1219 오민식의 고민

// update 220509

using namespace std;

const int INF = 2e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;

struct Edge
{
	int dest, cost;
};

int N,M,S,E;
int u,v,c;
long long dist[51];
int earn[51];
bool cyclevert[51];
bool cyclevisited[51];
vector<Edge> adj[51];

void checkcycle(int cur)
{
	if(cyclevisited[cur] == true)
	{
		return;
	}
	cyclevisited[cur] = true;
	for(auto &e : adj[cur])
	{
		checkcycle(e.dest);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for(int i = 0;i<=50;++i)
	{
		dist[i] = llINF;
	}

	bool cycle = false;

	cin>>N>>S>>E>>M;

	for(int i = 1;i<=M;++i)
	{
		cin>>u>>v>>c;
		adj[u].push_back({v,c});
	}

	for(int i = 0;i<N;++i)
	{
		cin>>earn[i];
	}

	dist[S] = earn[S];
	for(int i = 0;i<N;++i)
	{
		for(int j = 0;j<N;++j)
		{
			if(dist[j] == llINF)
			{
				continue;
			}
			for(auto &e : adj[j])
			{
				if((dist[e.dest] == llINF) || (dist[e.dest] < dist[j]-e.cost+earn[e.dest]))
				{
					dist[e.dest] = dist[j]-e.cost+earn[e.dest];
					if(i == N-1)
					{
						cyclevert[e.dest] = true;
						cycle = true;
					}
				}
			}
		}
	}

	if(cycle)
	{
		for(int i = 0;i<N;++i)
		{
			if(cyclevert[i] == true)
			{
				checkcycle(i);
			}
		}
	}
	if(cycle && cyclevisited[E])
	{
		cout<<"Gee";
	}
	else if(dist[E] == llINF)
	{
		cout<<"gg";
	}
	else
	{
		cout<<dist[E];
	}

	return 0;
}

