#include <bits/stdc++.h>

// 1348 주차장

// update 220524

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 3010;

int R,C;
int cntV;
char PL[51][51];
bool visited[51][51];
bool dfsVisited[MAX];
int dist[51][51];
int A[MAX], B[MAX];
vector<pair<int,int>> adj[MAX];
vector<int> AV;
map<pair<int,int>, int> M;
int result;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void bfs(pair<int,int> &a)
{   
    queue<pair<int,int>> Q;

    memset(visited,false,sizeof(visited));
    memset(dist,0,sizeof(dist));

    Q.push(a);
    visited[a.first][a.second] = true;
    dist[a.first][a.second] = 0;

    while(!Q.empty())
    {
        pair<int,int> cur = Q.front();
        Q.pop();

        for(int dir = 0;dir<4;++dir)
        {
            int x = cur.first + dx[dir];
            int y = cur.second + dy[dir];

            if(x < 1 || x > R || y < 1 || y > C)
            {
                continue;
            }
            if(PL[x][y] == 'X')
            {
                continue;
            }
            if(visited[x][y] == false)
            {
                visited[x][y] = true;
                dist[x][y] = dist[cur.first][cur.second] + 1;
                if(PL[x][y] == 'P')
                {
                    adj[M[a]].push_back({M[pair<int,int>(x,y)],dist[x][y]});
                }
                Q.push({x,y});
            }
        }
    }
}

bool dfs(int a, int k)
{
    dfsVisited[a] = true;
    for(auto &b : adj[a])
    {
        if(b.second > k)
        {
            continue;
        }
        if(B[b.first] == -1 || dfsVisited[B[b.first]] == false && dfs(B[b.first],k))
        {
            B[b.first] = a;
            A[a] = b.first;
            return true;
        }
    }
    return false;
}

bool dfsMatching(int k)
{
    int cntMatch = 0;

    fill(A,A+MAX,-1);
    fill(B,B+MAX,-1);

    for(auto &a : AV)
    {
        if(A[a] == -1)
        {
            fill(dfsVisited,dfsVisited+MAX,false);
            if(dfs(a, k))
            {
                cntMatch++;
            }
        }
    }
    if(cntMatch == AV.size())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    queue<pair<int,int>> Q;
    
    cin>>R>>C;

    for(int i = 1;i<=R;++i)
    {
        string s;
        cin>>s;
        for(int j = 1;j<=C;++j)
        {
            PL[i][j] = s[j-1];
            M[pair<int,int>(i,j)] = ++cntV;
            if(PL[i][j] == 'C')
            {
                AV.push_back(M[pair<int,int>(i,j)]);
                Q.push({i,j});
            }
        }
    }

    if(AV.empty())
    {
        cout<<"0";
        return 0;
    }

    while(!Q.empty())
    {
        bfs(Q.front());
        Q.pop();
    }
    
    int l = 0, r = MAX;
    int mid;
    result = -1;
    while(l <= r)
    {
        mid = (l+r)/2;
        if(dfsMatching(mid))
        {//시간을 줄여본다
            r = mid-1;
            result = mid;
        }
        else
        {//시간을 늘려본다
            l = mid+1;
        }
    }

    cout<<result;
	
	return 0;
}

