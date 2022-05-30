#include <bits/stdc++.h>

// 1585 경찰

// update 220530

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 210;
const int v = 52;
const int p = 105;

struct Edge
{
	int next, capacity, flow, cost;
	Edge* arcEdge {nullptr};
};

int N,T,F;
vector<Edge*> adj[MAX];
vector<Edge*> reverseAdj[MAX];
int in[MAX], out[MAX];
int S = 0;
int E = 208;

void addEdge(int u, int v, int capa, int cost)
{
	Edge* e1 = new Edge({v,capa,0,cost});
	Edge* e2 = new Edge({u,0,0,-cost});
	e1->arcEdge = e2;
	e2->arcEdge = e1;
	adj[u].push_back(e1);
	adj[v].push_back(e2);
}

void reverseAddEdge(int u, int v, int capa, int cost)
{
    Edge* e1 = new Edge({v,capa,0,cost});
	Edge* e2 = new Edge({u,0,0,-cost});
	e1->arcEdge = e2;
	e2->arcEdge = e1;
	reverseAdj[u].push_back(e1);
	reverseAdj[v].push_back(e2);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin>>N;
    for(int i = 1;i<=N;++i)
    {
        cin>>in[i];
        addEdge(S,i,1,0);
        reverseAddEdge(S,i,1,0);
        addEdge(i,i+v,1,0);
        reverseAddEdge(i,i+v,1,0);
    }
    for(int i = 1;i<=N;++i)
    {
        cin>>out[i];
        addEdge(i+p+v,E,1,0);
        reverseAddEdge(i+p+v,E,1,0);
        addEdge(i+p,i+p+v,1,0);
        reverseAddEdge(i+p,i+p+v,1,0);
    }

    cin>>T>>F;
    for(int i = 1;i<=N;++i)
    {
        for(int j = 1;j<=N;++j)
        {
            if(out[j] - in[i] > 0)
            {
                int cost;
                if(out[j] - in[i] < T)
                {
                    cost = (T-(out[j]-in[i]))*(T-(out[j]-in[i]));
                    if(cost > F)
                    {
                        cost = F;
                    }
                }
                else
                {
                    cost = 0;
                }
                addEdge(i+v,j+p,1,cost);
                reverseAddEdge(i+v,j+p,1,-cost);
            }
        }
    }

    int minimumPunish = 0;
    int minimumCnt = 0;
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
            minimumPunish += path[i]->cost;
            path[i]->flow += 1;
            path[i]->arcEdge->flow -= 1;
        }
        minimumCnt++;
    }

    int maximumPunish = 0;
    int maximumCnt = 0;
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
            for(auto &e : reverseAdj[cur])
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
            maximumPunish += path[i]->cost;
            path[i]->flow += 1;
            path[i]->arcEdge->flow -= 1;
        }
        maximumCnt++;
    }

    if(maximumCnt != N || minimumCnt != N)
    {
        cout<<"-1";
    }
    else
    {
        cout<<minimumPunish<<" "<<-maximumPunish;
    }

	return 0;
}

