#include <bits/stdc++.h>

// 3295 단방향 링크 네트워크

// update 220523

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 2010;

int T;
int n,m,u,v;
int A[MAX], B[MAX];
vector<int> adj[MAX];
bool visited[MAX];
int cntMatch;

bool dfs(int a)
{
    visited[a] = true;
    for(auto &b : adj[a])
    {
        if(B[b] == -1 || (visited[B[b]] == false && dfs(B[b]) == true))
        {
            A[a] = b;
            B[b] = a;
            return true;
        }
    }
    return false;
}

void init()
{
    cntMatch = 0;
    for(int i = 0;i<MAX;++i)
    {
        adj[i].clear();
        A[i] = -1;
        B[i] = -1;
        visited[i] = false;
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

        cin>>n>>m;
        for(int i = 1;i<=m;++i)
        {
            cin>>u>>v;
            adj[u].push_back(v);
        }

        for(int i = 0;i<n;++i)
        {
            if(A[i] == -1)
            {
                fill(visited,visited+MAX,false);
                if(dfs(i) == true)
                {
                    cntMatch++;
                }
            }
        }

        cout<<cntMatch<<'\n';
    }

	
	return 0;
}

