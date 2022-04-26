#include <bits/stdc++.h>

// 11438 LCA2

// update 220426

using namespace std;

const int INF = 1e9+7;
const int minINF = -2e9-1;
const int BINARY_MAX = 17;

int N,M;
int u,v;
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
    for(int i = 0;i<=N;++i)
    {
        depth[i] = -1;
    }

    depth[1] = 0;

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

    cin>>M;

    while(M--)
    {
        cin>>u>>v;

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
            for(int j = BINARY_MAX; j >= 0; --j)
            {
                if(parent[u][j] != -1 && parent[u][j] != parent[v][j])
                {
                    u = parent[u][j];
                    v = parent[v][j];
                }
            }
            u = parent[u][0];
        
        }


        cout<<u<<'\n';
    }


	return 0;
}

