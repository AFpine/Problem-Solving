#include <bits/stdc++.h>

// 8012 한동이는 영업사원!

// update 220427

using namespace std;

const int INF = 1e9+7;
const int minINF = -2e9-1;
const int BMAX = 17;

int N,M;
int Mseq[5001];
int depth[30001];
int rootdist[30001];
int parent[30001][BMAX+1];
vector<int> adj[30001];
int result = 0;

void makeTree(int cur)
{
	for(auto x : adj[cur])
	{
		if(depth[x] == -1)
		{
			depth[x] = depth[cur] + 1;
			parent[x][0] = cur;
			rootdist[x] = rootdist[cur] + 1;
			makeTree(x);
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

	for(int i = 1;i<=30000;++i)
	{
		depth[i] = -1;
	}

	cin>>N;

	for(int i = 1;i<=N-1;++i)
	{
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
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

	Mseq[0] = 1;
	for(int i = 1;i<=M;++i)
	{
		cin>>Mseq[i];
	}

	for(int i = 0;i<M;++i)
	{
		int lca;
		lca = LCA(Mseq[i],Mseq[i+1]);

		result += getDist(Mseq[i],lca) + getDist(Mseq[i+1],lca);
	}

	cout<<result;

	return 0;
}

