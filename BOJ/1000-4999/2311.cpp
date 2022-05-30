#include <bits/stdc++.h>

// 2311 왕복 여행

// update 220530

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 1005;

struct Edge
{
	int next, capacity, flow, cost;
	Edge* arcEdge {nullptr};
};

int N,M;
int S = 0;
int E = 1004;
vector<Edge*> adj[MAX];

void addEdge(int u, int v, int capa, int cost)
{
	Edge* e1 = new Edge({v,capa,0,cost});
	Edge* e2 = new Edge({u,0,0,-cost});
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
		int a,b,c;
		cin>>a>>b>>c;
		addEdge(a,b,1,c);
		addEdge(b,a,1,c);
	}
	addEdge(S,1,2,0);
	addEdge(N,E,2,0);

	int totalCost = 0;
	while(true)
	{
		int prev[MAX], dist[MAX];
		bool inQ[MAX];
		Edge* path[MAX];
		queue<int> Q;
		fill(prev,prev+MAX,-1);
		fill(dist,dist+MAX,INF);

		dist[S] = 0;
		inQ[S] = true;
		Q.push(S);
		while(!Q.empty())
		{
			int cur = Q.front();
			Q.pop();
			inQ[cur] = false;
			for(auto &e : adj[cur])
			{
				if(e->capacity-e->flow > 0 && dist[e->next] > dist[cur] + e->cost)
				{
					dist[e->next] = dist[cur] + e->cost;
					prev[e->next] = cur;
					path[e->next] = e;
					if(inQ[e->next] == false)
					{
						inQ[e->next] = true;
						Q.push(e->next);
					}
				}
			}
		}

		if(prev[E] == -1)
		{
			break;
		}
		for(int i = E; i != S; i = prev[i])
		{
			totalCost += path[i]->cost;
			path[i]->flow += 1;
			path[i]->arcEdge->flow -= 1;
		}

	}

	cout<<totalCost;

	return 0;
}

