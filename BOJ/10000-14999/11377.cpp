#include <bits/stdc++.h>

// 11377 열혈강호 3

// update 220523

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 2010;

int N,M,K;
int A[MAX], B[MAX];
vector<int> adj[MAX];
bool visited[MAX];
int cntMatch = 0;

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


int main()
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    fill(A,A+MAX,-1);
    fill(B,B+MAX,-1);

    cin>>N>>M>>K;
    for(int i = 1;i<=N;++i)
    {
        int w;
        cin>>w;
        for(int j = 1;j<=w;++j)
        {
            int s;
            cin>>s;
            adj[i*2].push_back(s);
            adj[i*2-1].push_back(s);
        }
    }

    for(int i = 2;i<=2*N;i+=2)
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
    
    int pluscnt = 0;
    for(int i = 1;i<=2*N-1;i+=2)
    {
        if(A[i] == -1)
        {
            fill(visited,visited+MAX,false);
            if(dfs(i) == true)
            {
                cntMatch++;
                pluscnt++;
            }
        }
        if(pluscnt == K)
        {
            break;
        }
    }

    cout<<cntMatch;
	
	return 0;
}

