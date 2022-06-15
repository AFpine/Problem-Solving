#include <bits/stdc++.h>

// 14283 간선 이어가기

// update 220615

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 1005;
const int MOD = 1e9+7;

struct Edge
{
	int next,capacity,flow;
	Edge* arcEdge {nullptr};
};

int N,M;
int S,E;
int total = 0;
vector<Edge*> adj[55];
int U[MAX], V[MAX], CAP[MAX];

void addEdge(int u, int v, int cap)
{
	Edge* e1 = new Edge({v,cap,0});
	Edge* e2 = new Edge({u,0,0});
	e1->arcEdge = e2;
	e2->arcEdge = e1;
	adj[u].push_back(e1);
	adj[v].push_back(e2);
}

int solve(int n)
{
	for(int i = 0;i<55;++i)
	{
		adj[i].clear();
	}

	for(int i = 1;i<=M;++i)
	{
		if(i != n)
		{
			addEdge(U[i],V[i],CAP[i]);
			addEdge(V[i],U[i],CAP[i]);
		}
	}

	int mincut = 0;
	while(true)
	{
		int prev[55];
		Edge* path[55];
		queue<int> Q;

		fill(prev,prev+55,-1);
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

	bool visited[55];
	queue<int> Q;
	fill(visited,visited+55,false);
	Q.push(S);
	visited[S] = true;

	while(!Q.empty())
	{
		int cur = Q.front();
		Q.pop();
		for(auto &e : adj[cur])
		{
			if(visited[e->next] == false && e->capacity-e->flow > 0)
			{
				visited[e->next] = true;
				Q.push(e->next);
			}
		}
	}

	if(visited[U[n]] != visited[V[n]])
	{
		return total - mincut;
	}
	else
	{
		return -1;
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>M;

	for(int i = 1;i<=M;++i)
	{
		cin>>U[i]>>V[i]>>CAP[i];
		total += CAP[i];
	}

	cin>>S>>E;
	int result = 0;
	for(int i = 1;i<=M;++i)
	{
		result = max(result, solve(i));
	}
	
	cout<<result;

	return 0;
}