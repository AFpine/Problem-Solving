#include <bits/stdc++.h>

// 15480 LCA와 쿼리

// update 220511

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int BINARY_MAX = 17;

int N,M;
int r,u,v;
int parent[100001][BINARY_MAX+1];
int depth[100001];
vector<int> adj[100001];

void makeTree(int cur)
{
    for(auto x : adj[cur])
    {
        if(depth[x] == -1)
        {
            parent[x][0] = cur;
            depth[x] = depth[cur] + 1;
            makeTree(x);
        }
    }
}

int getLCA(int u, int v)
{
	if(depth[u] < depth[v])
	{
		swap(u,v);
	}

	int dif = depth[u] - depth[v];

	for(int j = 0;dif;++j)
	{
		if(dif % 2)
		{
			u = parent[u][j];
		}
		dif /= 2;
	}

	if(u != v)
	{
		for(int j = BINARY_MAX;j>=0;--j)
		{
			if(parent[u][j] != -1 && parent[u][j] != parent[v][j])
            {
                u = parent[u][j];
                v = parent[v][j];
            }
		}
		u = parent[u][0];
	}
	return u;
}

int maxlca(int a, int b, int c)
{
	if(depth[a] > depth[b] && depth[a] > depth[c])
	{
		return a;
	}
	else if(depth[b] > depth[a] && depth[b] > depth[c])
	{
		return b;
	}
	else
	{
		return c;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin>>N;

    for(int i = 1;i<=N-1;++i)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(parent,-1,sizeof(parent));
	memset(depth,-1,sizeof(depth));
    
	depth[1] = 0;
	//root is node 1
    makeTree(1);

    for(int j = 1;j<=BINARY_MAX;++j)
    {
        for(int i = 1;i<=N;++i)
        {
            if(parent[i][j-1] != -1)
            {
                parent[i][j] = parent[parent[i][j-1]][j-1];
            }
        }
    }
	//sparse table

    cin>>M;
    while(M--)
    {
		cin>>r>>u>>v;
		
		int uv = getLCA(u,v);
		int ru = getLCA(r,u);
		int rv = getLCA(r,v);
		cout<<maxlca(uv,ru,rv)<<'\n';
    }	


	return 0;
}


