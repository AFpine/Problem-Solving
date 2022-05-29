#include <bits/stdc++.h>

// 3640 제독

// update 220529

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 2005;
const int p = 1002;

struct Edge
{
	int next, capacity, flow, cost;
	Edge* arcEdge {nullptr};
};

int v,e;
vector<Edge*> adj[MAX];
int totalCanon;

void init()
{
	totalCanon = 0;
	for(int i = 0;i<MAX;++i)
	{
		adj[i].clear();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while(cin>>v>>e)
	{
		init();

		for(int i = 1;i<=v;++i)
		{
			Edge* e1 = new Edge({i+p,1,0,0});
			Edge* e2 = new Edge({i,0,0,0});
			e1->arcEdge = e2;
			e2->arcEdge = e1;
			adj[i].push_back(e1);
			adj[i+p].push_back(e2);
		}

		for(int i = 1;i<=e;++i)
		{
			int a,b,c;
			cin>>a>>b>>c;

			Edge* e1 = new Edge({b,1,0,c});
			Edge* e2 = new Edge({a+p,0,0,-c});
			e1->arcEdge = e2;
			e2->arcEdge = e1;
			adj[a+p].push_back(e1);
			adj[b].push_back(e2);
		}

		int S = 1+p;
		int E = v;
		for(int i = 1;i<=2;++i)
		{
			int prev[MAX], dist[MAX];
			bool inQ[MAX];
			Edge* path[MAX];
			queue<int> Q;
			
			fill(prev,prev+MAX,-1);
			fill(dist,dist+MAX,INF);
			fill(inQ,inQ+MAX,false);

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

			for(int i = E; i!= S; i = prev[i])
			{
				totalCanon += path[i]->cost;
				path[i]->flow += 1;
				path[i]->arcEdge->flow -= 1;
			}
		}

		cout<<totalCanon<<'\n';

	}


	return 0;
}

