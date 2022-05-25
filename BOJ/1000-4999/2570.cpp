#include <bits/stdc++.h>

// 2570 비숍 2

// update 220525

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 10005;

int N,M;
int cnt1 = 1,cnt2 = 1;
map<pair<int,int>,int> AM,BM;
vector<int> adj[MAX];
int A[MAX], B[MAX];
bool visited[MAX];
int cntMatch;

void setting1(int x, int y)
{
    while(x <= N && y <= N)
    {
        if(AM[pair<int,int>(x,y)] == -1)
        {
            cnt1++;
            x++;
            y++;
            continue;
        }
        AM[pair<int,int>(x,y)] = cnt1;
        x++;
        y++;
    }
    cnt1++;
}

void setting2(int x, int y)
{
    while(x <= N && y >= 1)
    {
        if(BM[pair<int,int>(x,y)] == -1)
        {
            x++;
            y--;
            cnt2++;
            continue;
        }
        BM[pair<int,int>(x,y)] = cnt2;
        x++;
        y--;
    }
    cnt2++;
}

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

    cin>>N>>M;

    for(int i = 1;i<=M;++i)
    {
        int x,y;
        cin>>x>>y;
        AM[pair<int,int>(x,y)] = -1;
        BM[pair<int,int>(x,y)] = -1;
    }

    for(int i = 1;i<=N;++i)
    {
        setting1(1,i);
        setting2(1,i);
    }
    for(int i = 2;i<=N;++i)
    {
        setting1(i,1);
        setting2(i,N);
    }

    for(int i = 1;i<=N;++i)
    {
        for(int j = 1;j<=N;++j)
        {
            if(AM[pair<int,int>(i,j)] < 0)
            {
                continue;
            }
            adj[AM[pair<int,int>(i,j)]].push_back(BM[pair<int,int>(i,j)]);
        }
    }

    fill(A,A+MAX,-1);
    fill(B,B+MAX,-1);
    for(int i = 1;i<=N;++i)
    {
        for(int j = 1;j<=N;++j)
        {
            pair<int,int> cur = pair<int,int>(i,j);
            if(AM[cur] < 0)
            {
                continue;
            }
            if(A[AM[cur]] == -1)
            {
                fill(visited,visited+MAX,false);
                if(dfs(AM[cur]))
                {
                    cntMatch++;
                }
            }
        }
    }

    cout<<cntMatch;

	
	return 0;
}

