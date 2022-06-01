#include <bits/stdc++.h>

// 6241 Dining

// update 220601

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 420;
const int cp = 102;
const int cpp = 204;
const int dp = 306;

int N,F,D;
int S = 0;
int E = 415;
vector<int> adj[MAX];
int c[MAX][MAX];
int f[MAX][MAX];
int level[MAX];
int work[MAX];

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

	cin>>N>>F>>D;

	for(int i = 1;i<=N;++i)
	{
		c[i+cp][i+cpp] = 1;
		adj[i+cp].push_back(i+cpp);
		adj[i+cpp].push_back(i+cp);
	}
	for(int i = 1;i<=F;++i)
	{
		c[S][i] = 1;
		adj[S].push_back(i);
		adj[i].push_back(S);
	}
	for(int i = 1;i<=D;++i)
	{
		c[i+dp][E] = 1;
		adj[i+dp].push_back(E);
		adj[E].push_back(i+dp);
	}
	
	for(int i = 1;i<=N;++i)
	{
		int temp, f, d;
		vector<int> tempf,tempd;
		cin>>f>>d;
		for(int j = 1;j<=f;++j)
		{
			cin>>temp;
			tempf.push_back(temp);
		}
		for(int j = 1;j<=d;++j)
		{
			cin>>temp;
			tempd.push_back(temp);
		}
		for(auto &f : tempf)
		{
			c[f][i+cp] = 1;
			adj[f].push_back(i+cp);
			adj[i+cp].push_back(f);
		}
		for(auto &d : tempd)
		{
			c[i+cpp][d+dp] = 1;
			adj[i+cpp].push_back(d+dp);
			adj[d+dp].push_back(i+cpp);
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

	cout<<totalFlow;

	return 0;
}

