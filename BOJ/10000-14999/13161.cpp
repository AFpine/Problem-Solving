#include <bits/stdc++.h>

// 13161 분단의 슬픔

// update 220601

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 505;

struct Edge
{
	int next, capacity, flow;
	Edge* arcEdge {nullptr};
};

int N;
int S = 0;
int E = 504;
vector<int> adj[MAX];
int c[MAX][MAX];
int f[MAX][MAX];
int level[MAX];
int work[MAX];
bool visited[MAX];

// void addEdge(int u, int v, int capa)
// {
// 	Edge* e1 = new Edge({v,capa,0});
// 	Edge* e2 = new Edge({u,0,0});
// 	e1->arcEdge = e2;
// 	e2->arcEdge = e1;
// 	adj[u].push_back(e1);
// 	adj[v].push_back(e2);
// }

bool bfs()	//make level graph in dinic's algorithm
{
	queue<int> Q;
	fill(level,level+MAX,-1);
	
	level[S] = 0;
	Q.push(S);
	while(!Q.empty())
	{
		int cur = Q.front();
		Q.pop();
		
		for(auto &e : adj[cur])
		{
			if(c[cur][e] - f[cur][e] > 0 && level[e] == -1)
			{
				level[e] = level[cur] + 1;
				Q.push(e);
			}
		}
	}

	if(level[E] == -1)
	{
		return false;
	}
	return true;
}

int dfs(int cur, int dest, int flow)	//maximum flow in dinic's algorithm
{
	if(cur == dest)
	{
		return flow;
	}

	for(int &i = work[cur]; i < adj[cur].size(); i++)
	{
		int next = adj[cur][i];

		if(level[next] == level[cur] + 1 && c[cur][next]-f[cur][next] > 0)
		{
			int df = dfs(next,dest,min(flow,c[cur][next]-f[cur][next]));

			if(df > 0)
			{
				f[cur][next] += df;
				f[next][cur] -= df;
				return df;
			}
		}
	}
	
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N;
	for(int i = 1;i<=N;++i)
	{
		int temp;
		cin>>temp;
		if(temp == 1)
		{
			c[S][i] = INF;
			adj[S].push_back(i);
			adj[i].push_back(S);
			// addEdge(S,i,INF);
		}
		else if(temp == 2)
		{
			c[i][E] = INF;
			adj[i].push_back(E);
			adj[E].push_back(i);
			// addEdge(i,E,INF);
		}
	}

	for(int i = 1;i<=N;++i)
	{
		for(int j = 1;j<=N;++j)
		{
			int cost;
			cin>>cost;
			if(i == j)
			{
				continue;
			}
			// addEdge(i,j,cost);
			c[i][j] = cost;
			adj[i].push_back(j);
			adj[j].push_back(i);
		}
	}

	int totalFlow = 0;
	
	while(bfs())
	{
		fill(work,work+MAX,0);
		
		while(true)
		{
			int flow = dfs(S,E,INF);
			if(flow == 0)
			{
				break;
			}
			totalFlow += flow;
		}
	}

	queue<int> Q;

	Q.push(S);
	visited[S] = true;

	while(!Q.empty())
	{
		int cur = Q.front();
		Q.pop();
		for(auto &e : adj[cur])
		{
			if(visited[e] == false && c[cur][e]-f[cur][e] > 0)
			{
				visited[e] = true;
				Q.push(e);
			}
		}
	}

	cout<<totalFlow<<'\n';
	for(int i = 1;i<=N;++i)
	{
		if(visited[i])
		{
			cout<<i<<" ";
		}
	}
	cout<<'\n';
	for(int i = 1;i<=N;++i)
	{
		if(!visited[i])
		{
			cout<<i<<" ";
		}
	}
	cout<<'\n';	

	return 0;
}

