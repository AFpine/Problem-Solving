#include <bits/stdc++.h>

// 9525 룩 배치하기

// update 220523

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 10005;

int N;
char chess[105][105];
vector<int> adj[MAX];
int A[MAX],B[MAX];
bool visited[MAX];
map<pair<int,int>,int> RM;
map<pair<int,int>,int> CM;
int R = 1, C = 1;
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

    cin>>N;
    for(int i = 1;i<=N;++i)
    {
        string s;
        cin>>s;
        for(int j = 1;j<=N;++j)
        {
            chess[i][j] = s[j-1];
        }
    }

    for(int i = 1;i<=N;++i)
    {
        for(int j = 1;j<=N;++j)
        {
            if(chess[i][j] == 'X')
            {
                R++;
                continue;   
            }
            else
            {
                RM[pair<int,int>(i,j)] = R;
            }
        }
        R++;
    }

    for(int i = 1;i<=N;++i)
    {
        for(int j = 1;j<=N;++j)
        {
            if(chess[j][i] == 'X')
            {
                C++;
                continue;
            }
            else
            {
                CM[pair<int,int>(j,i)] = C;
                adj[C].push_back(RM[pair<int,int>(j,i)]);
            }
        }
        C++;
    }

    for(int i = 1;i<=N;++i)
    {
        for(int j = 1;j<=N;++j)
        {
            if(chess[i][j] == 'X')
            {
                continue;
            }
            int cur = CM[pair<int,int>(i,j)];
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

