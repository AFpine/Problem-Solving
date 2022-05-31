#include <bits/stdc++.h>

// 10937 두부 모판 자르기

// update 220531

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 410;
const int p = 202;

struct Edge
{
	int next, capacity, flow;
	Edge* arcEdge {nullptr};
};

int N,M;
int S = 0,E = 408;
int tCost[MAX];
vector<Edge*> adj[MAX];
vector<Edge*> vCutV;
set<int> result;
bool cutVertex[MAX];
bool visited[MAX];

void bfs()
{
    queue<int> Q;
    visited[S] = true;
    Q.push(S);

    while(!Q.empty())
    {
        int cur = Q.front();
        Q.pop();
        for(auto &e : adj[cur])
        {
            if(e->capacity-e->flow > 0 && visited[e->next] == false)
            {
                visited[e->next] = true;
                Q.push(e->next);
            }
        }
    }
}

void addEdge(int u, int v, int capa)
{
	Edge* e1 = new Edge({v,capa,0});
	Edge* e2 = new Edge({u,0,0});
	e1->arcEdge = e2;
	e2->arcEdge = e1;
	adj[u].push_back(e1);
	adj[v].push_back(e2);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin>>N>>M;
    cin>>S>>E;

    for(int i = 1;i<=N;++i)
    {
        cin>>tCost[i];
    }
    for(int i = 1;i<=N;++i)
    {
        addEdge(i,i+p,tCost[i]);
    }

    for(int i = 1;i<=M;++i)
    {
        int u,v;
        cin>>u>>v;
        addEdge(u+p,v,INF);
        addEdge(v+p,u,INF);
    }

    long long maxFlow = 0;
    E = E+p;
    while(true)
    {
        int prev[MAX];
        Edge* path[MAX];
        queue<int> Q;
        fill(prev,prev+MAX,-1);

        Q.push(S);
        while(!Q.empty() && prev[E] == -1)
        {
            int cur = Q.front();
            Q.pop();
            for(auto &e : adj[cur])
            {
                if(e->capacity-e->flow > 0 && prev[e->next] == -1)
                {
                    prev[e->next] = cur;
                    path[e->next] = e;
                    Q.push(e->next);
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
            flow = min(flow, path[i]->capacity-path[i]->flow);
        }
        for(int i = E; i != S; i = prev[i])
        {
            path[i]->flow += flow;
            path[i]->arcEdge->flow -= flow;
        }
        maxFlow += flow;
        // cout<<flow<<'\n';
    }


    bfs();

    for(int i = 1;i<=N;++i)
    {
        if(visited[i] == true && visited[i+p] == false)
        {
            cout<<i<<" ";
        }
    }

	return 0;
}

