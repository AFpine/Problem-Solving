#include <bits/stdc++.h>

// 1574 룩 어택

// update 220524

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 350;

int R,C,N;
vector<int> adj[MAX];
int A[MAX],B[MAX];
bool visited[MAX];
map<pair<int,int>,int> RM, CM;
int cntMatch;

bool dfs(int a)
{
    if(visited[a])
    {
        return false;
    }
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

    cin>>R>>C>>N;

    for(int i = 1;i<=N;++i)
    {
        int x,y;
        cin>>x>>y;
        RM[pair<int,int>(x,y)] = -1;
    }

    for(int i = 1;i<=R;++i)
    {
        for(int j = 1;j<=C;++j)
        {
            if(RM[pair<int,int>(i,j)] < 0)
            {
                continue;
            }
            RM[pair<int,int>(i,j)] = i;
            CM[pair<int,int>(i,j)] = j;
            adj[i].push_back(j);
        }
    }
    


    for(int i = 1;i<=R;++i)
    {
        for(int j = 1;j<=C;++j)
        {
            if(RM[pair<int,int>(i,j)] < 0)
            {
                continue;
            }
            int cur = RM[pair<int,int>(i,j)];
            if(A[cur] == -1)
            {
                fill(visited,visited+MAX,false);
                if(dfs(cur) == true)
                {
                    cntMatch++;
                }
            }
        }
    }

    cout<<cntMatch;

	
	return 0;
}

