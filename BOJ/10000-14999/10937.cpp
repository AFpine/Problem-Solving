#include <bits/stdc++.h>

// 10937 두부 모판 자르기

// update 220531

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 155;

struct Edge
{
	int next, capacity, flow, cost;
	Edge* arcEdge {nullptr};
};

int N;
int cntDofu = 0;
char dofu[12][12];
int S = 0;
int E = 150;
vector<Edge*> adj[MAX];
map<pair<int,int>,int> M;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void addEdge(int u, int v, int capa, int cost)
{
	Edge* e1 = new Edge({v,capa,0,cost});
	Edge* e2 = new Edge({u,0,0,-cost});
	e1->arcEdge = e2;
	e2->arcEdge = e1;
	adj[u].push_back(e1);
	adj[v].push_back(e2);
}

void makeEdge(int i, int j)
{
    char curC = dofu[i][j];
    for(int dir = 0; dir<4; ++dir)
    {
        int x = i + dx[dir];
        int y = j + dy[dir];
        if(x < 1 || x > N || y < 1 || y > N)
        {
            continue;
        }
        char nextC = dofu[x][y];
        if(curC == 'A')
        {
            if(nextC == 'A')
            {
                addEdge(M[{i,j}],M[{x,y}],1,-100);
            }
            else if(nextC == 'B')
            {
                addEdge(M[{i,j}],M[{x,y}],1,-70);
            }
            else if(nextC == 'C')
            {
                addEdge(M[{i,j}],M[{x,y}],1,-40);
            }
            else
            {
                addEdge(M[{i,j}],M[{x,y}],1,0);
            }
        }
        else if(curC == 'B')
        {
            if(nextC == 'A')
            {
                addEdge(M[{i,j}],M[{x,y}],1,-70);
            }
            else if(nextC == 'B')
            {
                addEdge(M[{i,j}],M[{x,y}],1,-50);
            }
            else if(nextC == 'C')
            {
                addEdge(M[{i,j}],M[{x,y}],1,-30);     
            }
            else
            {
                addEdge(M[{i,j}],M[{x,y}],1,0); 
            }
        }
        else if(curC == 'C')
        {
            if(nextC == 'A')
            {
                addEdge(M[{i,j}],M[{x,y}],1,-40);
            }
            else if(nextC == 'B')
            {
                addEdge(M[{i,j}],M[{x,y}],1,-30);
            }
            else if(nextC == 'C')
            {
                addEdge(M[{i,j}],M[{x,y}],1,-20);
            }
            else
            {
                addEdge(M[{i,j}],M[{x,y}],1,0);
            }
        }
        else
        {
            addEdge(M[{i,j}],M[{x,y}],1,0);
        }
    }
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin>>N;
    for(int i = 1;i<=N;++i)
    {
        string s;
        cin>>s;
        for(int j = 1;j<=N;++j)
        {
            dofu[i][j] = s[j-1];
            M[pair<int,int>(i,j)] = ++cntDofu;
            if(i % 2 == 1)
            {
                if(j % 2 == 1)
                {
                    addEdge(S,cntDofu,1,0);
                }
            }
            else
            {
                if(j % 2 == 0)
                {
                    addEdge(S,cntDofu,1,0);
                    // addEdge(cntDofu,E,1,0);
                }
            }
            addEdge(cntDofu,E,1,0);
        }
    }

    for(int i = 1;i<=N;++i)
    {
        for(int j = 1;j<=N;++j)
        {
            if(i % 2 == 1)
            {
                if(j % 2 == 1)
                {
                    makeEdge(i,j);
                }
            }
            else
            {
                if(j % 2 == 0)
                {
                    makeEdge(i,j);
                }
            }
        }
    }

    int totalCost = 0;
    int cnt = 0;
    while(true)
    {
        int prev[MAX], dist[MAX];
        bool inQ[MAX];
        Edge* path[MAX];
        queue<int> Q;

        fill(prev,prev+MAX,-1);
        fill(dist,dist+MAX,INF);
        fill(inQ,inQ+MAX,false);

        dist[S] = 0;
        inQ[S] = true;
        Q.push(S);

        while(!Q.empty())
        {
            int cur = Q.front();
            Q.pop();
            inQ[cur] = false;
            for(auto &e : adj[cur])
            {
                if(e->capacity-e->flow > 0 && dist[e->next] > dist[cur] + e->cost)
                {
                    dist[e->next] = dist[cur] + e->cost;
                    prev[e->next] = cur;
                    path[e->next] = e;
                    if(inQ[e->next] == false)
                    {
                        inQ[e->next] = true;
                        Q.push(e->next);
                    }
                }
            }
        }

        if(prev[E] == -1)
        {
            break;
        }

        for(int i = E; i != S; i = prev[i])
        {
            totalCost += path[i]->cost;
            path[i]->flow += 1;
            path[i]->arcEdge->flow -= 1;
        }
    }

    cout<<-totalCost;
	
	return 0;
}

