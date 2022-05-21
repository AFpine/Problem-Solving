#include <bits/stdc++.h>

// 9576 책 나눠주기

// update 220521

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 1005;

int T;
int N,M;
int A[MAX], B[MAX];
vector<int> adj[MAX];
bool visited[MAX];
int match = 0;

bool dfs(int a)
{
    visited[a] = true;
    for(int &b : adj[a])
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
    for(int i = 0;i<MAX;++i)
    {
        A[i] = -1;
        B[i] = -1;
        visited[i] = false;
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
        
        cin>>N>>M;

        for(int i = 1;i<=M;++i)
        {
            int a,b;
            cin>>a>>b;
            for(int j = a;j<=b;++j)
            {
                adj[i].push_back(j);
            }
        }

        match = 0;

        for(int i = 1;i<=M;++i)
        {
            if(A[i] == -1)
            {
                fill(visited,visited+MAX,false);
                if(dfs(i) == true)
                {
                    match++;
                }
            }
        }

        cout<<match<<'\n';
    }    
    

	return 0;
}

