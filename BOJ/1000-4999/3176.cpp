#include <bits/stdc++.h>

// 3176 도로 네트워크

// update 220601

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 100005;
const int BMAX = 18;

int N,K;
int parent[MAX][BMAX+1];
int maximum[MAX][BMAX+1];
int minimum[MAX][BMAX+1];
int depth[MAX];
vector<pair<int,int>> adj[MAX];

void makeTree(int cur)
{
	for(auto &p : adj[cur])
	{
		if(depth[p.first] == -1)
		{
			depth[p.first] = depth[cur] + 1;
			parent[p.first][0] = cur;
			maximum[p.first][0] = p.second;
			minimum[p.first][0] = p.second;
			makeTree(p.first);
		}
	}
}

void lca(int u, int v, int &maxV, int &minV)
{
	maxV = -1;
	minV = INF;

	if(depth[u] < depth[v])
	{
		swap(u,v);
	}
	int diff = depth[u] - depth[v];

	for(int i = 0;diff;i++)
	{
		if(diff % 2 == 1)
		{
			maxV = max(maxV,maximum[u][i]);
			minV = min(minV,minimum[u][i]);
			u = parent[u][i];
		}
		diff /= 2;
	}

	if(u != v)
	{
		for(int i = BMAX-1; i >= 0; --i)
		{
			if(parent[u][i] != 1 && parent[u][i] != parent[v][i])
			{
				maxV = max(maxV,maximum[u][i]);
				maxV = max(maxV,maximum[v][i]);
				minV = min(minV,minimum[u][i]);
				minV = min(minV,minimum[v][i]);
				u = parent[u][i];
				v = parent[v][i];
			}
		}
		maxV = max(maxV,maximum[u][0]);
		maxV = max(maxV,maximum[v][0]);
		minV = min(minV,minimum[u][0]);
		minV = min(minV,minimum[v][0]);
		u = parent[u][0];
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill(depth,depth+MAX,-1);
	memset(parent,-1,sizeof(parent));
	memset(maximum,-1,sizeof(maximum));
	memset(minimum,INF,sizeof(minimum));

	cin>>N;
	
	for(int i = 1;i<N;++i)
	{
		int a,b,c;
		cin>>a>>b>>c;
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
	}
	
	depth[1] = 0;
	makeTree(1);

	for(int k = 1;k<=BMAX;++k)
	{
		for(int i = 2;i<=N;++i)
		{
			if(parent[i][k-1] != -1)
			{
				parent[i][k] = parent[parent[i][k-1]][k-1];
				maximum[i][k] = max(maximum[i][k-1], maximum[parent[i][k-1]][k-1]);
				minimum[i][k] = min(minimum[i][k-1], minimum[parent[i][k-1]][k-1]);
			}
		}
	}

	cin>>K;
	while(K--)
	{
		int D,E;
		int maxresult, minresult;
		cin>>D>>E;

		lca(D,E,maxresult,minresult);

		cout<<minresult<<" "<<maxresult<<'\n';
	}


	return 0;
}

