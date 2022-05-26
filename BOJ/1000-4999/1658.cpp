#include <bits/stdc++.h>

// 1658 돼지 잡기

// update 220526

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 103005;
const int p = 1000;

struct Edge
{
    int next;
    int capacity;
    int flow;
    Edge* arcEdge {nullptr};
};

int M,N;
int S = 0;
int E = 103000;
int pig[1005];
vector<Edge*> adj[MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin>>M>>N;

    for(int i = 1;i<=M;++i)
    {
        cin>>pig[i];
        Edge* e1 = new Edge({i,pig[i],0});
        Edge* e2 = new Edge({S,0,0});
        e1->arcEdge = e2;
        e2->arcEdge = e1;
        adj[S].push_back(e1);
        adj[i].push_back(e2);
    }

    for(int i = 1;i<=N;++i)
    {
        for(int j = 1;j<=M;++j)
        {
            Edge* e1 = new Edge({j+(i*p),INF,0});
            Edge* e2 = new Edge({j+((i-1)*p),0,0});
            e1->arcEdge = e2;
            e2->arcEdge = e1;
            adj[j+((i-1)*p)].push_back(e1);
            adj[j+(i*p)].push_back(e2);
        }
    }

    for(int i = 1;i<=N;++i)
    {
        int k;
        vector<int> tempV;
        cin>>k;
        for(int j = 1;j<=k;++j)
        {
            int tempK;
            cin>>tempK;
            tempV.push_back(tempK);
            Edge* e1 = new Edge({i+102000,INF,0});
            Edge* e2 = new Edge({tempK+(i*p),0,0});
            e1->arcEdge = e2;
            e2->arcEdge = e1;
            adj[tempK+(i*p)].push_back(e1);
            adj[i+102000].push_back(e2);
        }
        if(i != N)
        {
            for(int j = 0;j<tempV.size();++j)
            {
                for(int k = 0;k<tempV.size();++k)
                {
                    if(j == k)
                    {
                        continue;
                    }
                    Edge* e1 = new Edge({tempV[k]+((i+1)*p),INF,0});
                    Edge* e2 = new Edge({tempV[j]+(i*p),0,0});
                    e1->arcEdge = e2;
                    e2->arcEdge = e1;
                    adj[tempV[j]+(i*p)].push_back(e1);
                    adj[tempV[k]+((i+1)*p)].push_back(e2);
                }
            }
        }
        int B;
        cin>>B;
        Edge* e1 = new Edge({E,B,0});
        Edge* e2 = new Edge({i+102000,0,0});
        e1->arcEdge = e2;
        e2->arcEdge = e1;
        adj[i+102000].push_back(e1);
        adj[E].push_back(e2);
    }

    int totalFlow = 0;
    
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
                if(e->capacity - e->flow > 0 && prev[e->next] == -1)
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
            flow = min(flow, path[i]->capacity - path[i]->flow);
        }
        for(int i = E; i != S; i = prev[i])
        {
            path[i]->flow += flow;
            path[i]->arcEdge->flow -= flow;
        }

        totalFlow += flow;
    }   

    cout<<totalFlow;



	return 0;
}

