#include <bits/stdc++.h>

// 1762 정점들의 거리

// update 220427

using namespace std;

const int INF = 1e9+7;
const int minINF = -2e9-1;
const int BMAX = 17;

int N,M;
int depth[40001];
int rootdist[40001];
int parent[40001][BMAX+1];
vector<pair<int,int>> adj[40001];


void makeTree(int cur)
{
	for(auto x : adj[cur])
	{
		if(depth[x.first] == -1)
		{
			depth[x.first] = depth[cur] + 1;
			parent[x.first][0] = cur;
			rootdist[x.first] = rootdist[cur] + x.second;
			makeTree(x.first);
		}
	}
}

int LCA(int a, int b)
{
	if(depth[a] < depth[b])
	{//always depth[a] >= depth[b]
		swap(a,b);
	}

	int diff = depth[a] - depth[b];

	for(int j = 0;diff != 0; ++j)
	{
		if(diff%2 == 1)
		{
			a = parent[a][j];
		}
		diff /= 2;
	}

	if(a != b)
	{
		for(int i = BMAX; i >= 0; --i)
		{
			if(parent[a][i] != 0 && parent[a][i] != parent[b][i])
			{
				a = parent[a][i];
				b = parent[b][i];
			}
		}
		a = parent[a][0];
	}
	return a;
}	

int getDist(int a, int lca)
{
	return rootdist[a] - rootdist[lca];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for(int i = 1;i<=40000;++i)
	{
		depth[i] = -1;
	}

	cin>>N;

	for(int i = 1;i<=N-1;++i)
	{
		int a,b,c;
		cin>>a>>b>>c;
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
	}

	rootdist[1] = 0;
	depth[1] = 0;
	makeTree(1);

	for(int j = 1;j<=BMAX;++j)
	{
		for(int i = 1;i<=N;++i)
		{
			if(parent[i][j-1] != 0)
			{
				parent[i][j] = parent[parent[i][j-1]][j-1];
			}
		}
	}

	cin>>M;

	while(M--)
	{
		int a,b;
		int lca;
		cin>>a>>b;

		lca = LCA(a,b);

		cout<<getDist(a,lca) + getDist(b,lca)<<'\n';
	}

	return 0;
}

