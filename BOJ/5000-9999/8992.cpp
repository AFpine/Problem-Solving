#include <bits/stdc++.h>

// 8992 집기 게임

// update 220621

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 405;
const int d = 405;

struct Edge
{
	int next, capacity, flow; 
	int cost;
	Edge* arcEdge {nullptr};
};

struct Line
{
	int idx,x1,x2,y1,y2,weight;
};

int T;
int N,M;
int S = 0, E = 404;
int cnt;
vector<Edge*> adj[MAX];
Line rowL[205], colL[205];
long long resultCost, result;

void addEdge(int u, int v, int capval, int costval)
{
	Edge* e1 = new Edge({v,capval,0,costval});
	Edge* e2 = new Edge({u,0,0,-costval});
	e1->arcEdge = e2;
	e2->arcEdge = e1;
	adj[u].push_back(e1);
	adj[v].push_back(e2);
}

void input()
{
	cin>>N>>M;
	for(int i = 1;i<=N;++i)
	{
		int x1,y1,x2,y2,w;
		cin>>x1>>y1>>x2>>y2>>w;
		rowL[i].idx = ++cnt;
		rowL[i].x1 = x1;
		rowL[i].x2 = x2;
		rowL[i].y1 = y1;
		rowL[i].y2 = y2;
		if(rowL[i].x1 < rowL[i].x2)
		{
			swap(rowL[i].x1, rowL[i].x2);
		}
		if(rowL[i].y1 < rowL[i].y2)
		{
			swap(rowL[i].y1, rowL[i].y2);
		}
		rowL[i].weight = w;
		addEdge(S,rowL[i].idx,1,0);
	}
	for(int i = 1;i<=M;++i)
	{
		int x1,y1,x2,y2,w;
		cin>>x1>>y1>>x2>>y2>>w;
		colL[i].idx = ++cnt;
		colL[i].x1 = x1;
		colL[i].x2 = x2;
		colL[i].y1 = y1;
		colL[i].y2 = y2;
		if(colL[i].x1 < colL[i].x2)
		{
			swap(colL[i].x1, colL[i].x2);
		}
		if(colL[i].y1 < colL[i].y2)
		{
			swap(colL[i].y1, colL[i].y2);
		}
		colL[i].weight = w;
		addEdge(colL[i].idx,E,1,0);
	}
}

void solve()
{
	for(int i = 1;i<=N;++i)
	{
		for(int j = 1;j<=M;++j)
		{
			if(rowL[i].x1 < colL[j].x2 || rowL[i].x2 > colL[j].x1)
			{
				continue;
			}
			if(rowL[i].y1 < colL[j].y2 || rowL[i].y2 > colL[j].y1)
			{
				continue;
			}
			addEdge(rowL[i].idx, colL[j].idx, 1, (-rowL[i].weight*colL[j].weight));
		}
	}

	for(int i = 1;i<=N;++i)
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
					if(!inQ[e->next])
					{
						Q.push(e->next);
						inQ[e->next] = true;
					}
				}
			}
		}

		if(prev[E] == -1)
		{
			break;
		}

		for(int j = E; j != S; j = prev[j])
		{
			resultCost += (path[j]->cost);
			path[j]->flow++;
			path[j]->arcEdge->flow--;
		}
		result++;
	}

	cout<<result<<" "<<-resultCost<<'\n';
	
	return;
}

void init()
{
	cnt = 0;
	result = 0;
	resultCost = 0;
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

	cin>>T;
	while(T--)
	{
		init();
		input();
		solve();	
	}

	return 0;
}