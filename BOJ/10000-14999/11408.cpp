#include <bits/stdc++.h>

// 11408 열혈강호 5

// update 220529

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 805;
const int p = 401;

struct Edge
{
	int next, capacity, flow, cost;
	Edge* arcEdge {nullptr};
};

int N,M;
vector<Edge*> adj[MAX];
int A[MAX], B[MAX];
int S = 0, E = 804;
int workresult = 0;
int costresult = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>M;

	for(int i = 1;i<=N;++i)
	{
		int k;
		cin>>k;

		for(int j = 1;j<=k;++j)
		{
			int w,d;
			cin>>w>>d;

			Edge* e1 = new Edge({w+p,1,0,d});
			Edge* e2 = new Edge({i,0,0,-d});
			e1->arcEdge = e2;
			e2->arcEdge = e1;
			adj[i].push_back(e1);
			adj[w+p].push_back(e2);
		}
	}

	for(int i = 1;i<=N;++i)
	{
		Edge* e1 = new Edge({i,1,0,0});
		Edge* e2 = new Edge({S,0,0,0});
		e1->arcEdge = e2;
		e2->arcEdge = e1;
		adj[S].push_back(e1);
		adj[i].push_back(e2);
	}
	
	for(int i = 1;i<=M;++i)
	{
		Edge* e1 = new Edge({E,1,0,0});
		Edge* e2 = new Edge({i+p,0,0,0});
		e1->arcEdge = e2;
		e2->arcEdge = e1;
		adj[i+p].push_back(e1);
		adj[E].push_back(e2);
	}

	while(true)
	{
		int prev[MAX];
		int dist[MAX];
		bool inQ[MAX];
		Edge* path[MAX];
		queue<int> Q;

		fill(inQ,inQ+MAX,false);
		fill(dist,dist+MAX,INF);
		fill(prev,prev+MAX,-1);

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

		for(int i = E; i!=S; i = prev[i])
		{
			costresult += path[i]->cost;
			path[i]->flow += 1;
			path[i]->arcEdge->flow -= 1;
		}
		workresult += 1;
	}

	cout<<workresult<<'\n'<<costresult;

	return 0;
}

