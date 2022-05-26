#include <bits/stdc++.h>

// 1420 학교 가지마!

// update 220526

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 20210;
const int p = 10005;
// outVertex is i+p

struct Edge
{
    int next;
    int capacity;
    int flow;
    Edge* arcEdge{nullptr};
};

int N,M;
int S,E;
pair<int,int> Start, End;
char classRoom[101][101];
vector<Edge*> adj[MAX];
map<pair<int,int>,int> verNum;
int cntVer;
bool visited[101][101];
bool impossible;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    queue<pair<int,int>> Q;
    cin>>N>>M;

    for(int i = 1;i<=N;++i)
    {
        string s;
        cin>>s;
        for(int j = 1;j<=M;++j)
        {
            classRoom[i][j] = s[j-1];
            if(classRoom[i][j] == '#')
            {
                continue;
            }
            verNum[pair<int,int>(i,j)] = ++cntVer;
            if(classRoom[i][j] == 'K')
            {
                S = cntVer;
                Start = {i,j};
                Q.push({i,j});
            }
            if(classRoom[i][j] == 'H')
            {
                End = {i,j};
                E = cntVer;
            }
        }
    }

    for(int i = 1;i<=cntVer;++i)
    {
        Edge* e1 = new Edge({i+p,1,0});
        Edge* e2 = new Edge({i,0,0});
        e1->arcEdge = e2;
        e2->arcEdge = e1;
        adj[i].push_back(e1);
        adj[i+p].push_back(e2);
    }

    while(!Q.empty())
    {
        pair<int,int> cur = Q.front();
        Q.pop();
        
        if(visited[cur.first][cur.second] == true)
        {
            continue;
        }
        visited[cur.first][cur.second] = true;
        for(int dir = 0;dir<4;++dir)
        {
            int x = cur.first + dx[dir];
            int y = cur.second + dy[dir];

            if(x < 1 || x > N || y < 1 || y > M)
            {
                continue;
            }
            if(classRoom[x][y] == '#')
            {
                continue;
            }
            if(visited[x][y] == false)
            {
                Q.push({x,y});
                int curV = verNum[pair<int,int>(cur.first,cur.second)];
                int nextV = verNum[pair<int,int>(x,y)];

                Edge* e1 = new Edge({nextV,INF,0});
                Edge* e2 = new Edge({curV+p,0,0});
                Edge* e3 = new Edge({curV,INF,0});
                Edge* e4 = new Edge({nextV+p,0,0});
                e1->arcEdge = e2;
                e2->arcEdge = e1;
                e3->arcEdge = e4;
                e4->arcEdge = e3;
                adj[curV+p].push_back(e1);
                adj[nextV].push_back(e2);
                adj[nextV+p].push_back(e3);
                adj[curV].push_back(e4);
            }
            if(classRoom[x][y] == 'H' && cur == Start)
            {
                impossible = true;
            }
        }
    }

    int totalFlow = 0;
    S = S + p;
    while(true)
    {
        int prev[MAX];
        Edge* path[MAX];
        fill(prev,prev+MAX,-1);
        queue<int> Q;

        Q.push(S);

        while(!Q.empty() && prev[E] == -1)
        {
            int cur = Q.front();
            Q.pop();

            for(auto &e : adj[cur])
            {
                if(e->capacity - e->flow > 0 && prev[e->next] == -1)
                {
                    Q.push(e->next);
                    prev[e->next] = cur;
                    path[e->next] = e;
                    if(e->next == E)
                    {
                        break;
                    }
                }
            }
        }

        if(prev[E] == -1)
        {
            break;
        }

        int flow = INF;
        for(int i = E; i != S; i = prev[i])
        {
            flow = min(flow, path[i]->capacity - path[i]->flow);
        }
        for(int i = E; i != S; i = prev[i])
        {
            path[i]->flow += flow;
            path[i]->arcEdge->flow -= flow;
        }
        totalFlow += flow;
    }

    if(impossible)
    {
        cout<<"-1";
    }
    else
    {
        cout<<totalFlow;
    }






	return 0;
}

