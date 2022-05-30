#include <bits/stdc++.h>

// 9413 제주도 관광

// update 220530

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 605;
const int p = 302;

struct Edge
{
	int next, capacity, flow, cost;
	Edge* arcEdge {nullptr};
};

int T;
int N,M;
vector<Edge*> adj[MAX];
int S = 0;
int E = 604;

void addEdge(int u, int v, int capa, int cost)
{
	Edge* e1 = new Edge({v,capa,0,cost});
	Edge* e2 = new Edge({u,0,0,-cost});
	e1->arcEdge = e2;
	e2->arcEdge = e1;
	adj[u].push_back(e1);
	adj[v].push_back(e2);
}

void init()
{
    for(int i = 1;i<MAX;++i)
    {
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
        
        for(int i = 1;i<=N;++i)
        {
            addEdge(S,i,1,-1);
            addEdge(i,i+p,1,0);
            addEdge(i+p,E,1,0);
        }

        for(int i = 1;i<=M;++i)
        {
            int u,v;
            cin>>u>>v;
            addEdge(u+p,v,1,-1);
        }
        
        int cnt = 0;

        for(int j = 1;j<=2;++j)
        {
            int prev[MAX],dist[MAX];
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

            for(int i = E; i != S; i = prev[i])
            {
                cnt += path[i]->cost;
                path[i]->flow += 1;
                path[i]->arcEdge->flow -= 1;
            }
        }

        cout<<-cnt<<'\n';
    }

	return 0;
}

