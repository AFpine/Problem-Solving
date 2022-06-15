#include <bits/stdc++.h>

// 14286 간선 끊어가기 2

// update 220614

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 505;
const int MOD = 1e9+7;

struct Edge
{
	int next, capacity, flow;
	Edge* arcEdge {nullptr};
};

int N,M;
int S,E;
vector<Edge*> adj[MAX];

void addEdge(int u, int v, int cap)
{
	Edge* e1 = new Edge({v,cap,0});
	Edge* e2 = new Edge({u,0,0});
	e1->arcEdge = e2;
	e2->arcEdge = e1;
	adj[u].push_back(e1);
	adj[v].push_back(e2);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>M;

	for(int i = 1;i<=M;++i)
	{
		int u,v,cost;
		cin>>u>>v>>cost;
		addEdge(u,v,cost);
		addEdge(v,u,cost);
	}

	cin>>S>>E;

	long long mincut = 0;
	while(true)
	{
		int prev[MAX];
		Edge* path[MAX];
		queue<int> Q;

		fill(prev,prev+MAX,-1);

		Q.push(S);
		while(!Q.empty() && prev[E] == -1)
		{
			int cur = Q.front();
			Q.pop();
			for(auto &e : adj[cur])
			{
				if(e->capacity-e->flow > 0 && prev[e->next] == -1)
				{
					prev[e->next] = cur;
					path[e->next] = e;
					Q.push(e->next);
					if(e->next == E)
					{
						break;
					}
				}
			}
		}

		if(prev[E] == -1)
		{
			break;
		}

		int flow = INF;
		for(int i = E; i != S; i = prev[i])
		{
			flow = min(flow, path[i]->capacity-path[i]->flow);
		}
		for(int i = E; i != S; i = prev[i])
		{
			path[i]->flow += flow;
			path[i]->arcEdge->flow -= flow;
		}
		mincut += flow;
	}
	
	cout<<mincut;


	return 0;
}