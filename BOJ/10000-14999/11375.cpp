#include <bits/stdc++.h>

// 11375 열혈강호

// update 220521

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 1005;

int N,M;
int A[MAX], B[MAX];
vector<int> adj[MAX];
bool visited[MAX];
int match = 0;

bool dfs(int a)
{
    visited[a] = true;
    for(int &b : adj[a])
    {//A 그룹의 a 정점과 이어진 B그룹의 b 정점들에 대해
        if(B[b] == -1 || (visited[B[b]] == false && dfs(B[b]) == true))
        {//b 정점이 매칭 되어있지 않거나, b정점과 매칭 되어있는 A그룹의 정점이 다른 B그룹의 정점과 매칭이 가능하면
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

    init();
    cin>>N>>M;

    for(int i = 1;i<=N;++i)
    {
        int n;
        cin>>n;
        for(int j = 1;j<=n;++j)
        {
            int wn;
            cin>>wn;
            adj[i].push_back(wn);
        }
    }

    match = 0;

    for(int i = 1;i<=N;++i)
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
    

	return 0;
}

