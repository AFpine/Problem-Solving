#include <bits/stdc++.h>

// 2316 도시 왕복하기 2

// update 220521

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 805;

struct Edge
{
    int next = -1;
    int capacity = 0;
    int flow = 0;
    Edge* arcEdge = {nullptr};
    void addFlow(int flowval)
    {
        flow += flowval;
        arcEdge->flow -= flowval;
    }
    Edge(int nextval, int capval, int flowval)
    {
        next = nextval;
        capacity = capval;
        flow = flowval;
    }
};

int inV(int n)
{
    return n*2;
}
int outV(int n)
{
    return n*2-1;
}

int N,P;
vector<int> adj[MAX];
int c[MAX][MAX];
int f[MAX][MAX];
int total = 0;

int main()
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
   
    cin>>N>>P;

    for(int i = 1;i<=P;++i)
    {
        int u,v;
        cin>>u>>v;

        adj[outV(u)].push_back(inV(v));
        adj[inV(v)].push_back(outV(u));
        adj[outV(v)].push_back(inV(u));
        adj[inV(u)].push_back(outV(v));

        c[outV(u)][inV(v)] = 1;
        c[outV(v)][inV(u)] = 1;

    }
    for(int i = 1;i<=N;++i)
    {
        adj[inV(i)].push_back(outV(i));
        adj[outV(i)].push_back(inV(i));
        
        c[inV(i)][outV(i)] = 1;
    }

    int S = outV(1);
    int E = inV(2);
    
    while(true)
    {
        int prev[MAX];
        fill(prev,prev+MAX,-1);
        
        queue<int> Q;
        Q.push(S);

        while(!Q.empty() && prev[E] == -1)
        {
            int cur = Q.front();
            Q.pop();

            for(auto &next : adj[cur])
            {
                if(c[cur][next] - f[cur][next] > 0 && prev[next] == -1)
                {
                    Q.push(next);
                    prev[next] = cur;
                    if(next == E)
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
            flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
        }
        for(int i = E; i != S; i = prev[i])
        {
            f[prev[i]][i] += flow;
            f[i][prev[i]] -= flow;
        }
        total += flow;
    }

    cout<<total;

	return 0;
}

