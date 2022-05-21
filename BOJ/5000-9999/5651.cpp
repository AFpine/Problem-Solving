#include <bits/stdc++.h>

// 5651 완전 중요한 간선

// update 220521

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 305;

int K,N,M;
vector<int> adj[MAX];
int c[MAX][MAX];
int f[MAX][MAX];
int cntCrucialLink;
vector<pair<int,int>> cl;
int maximumFlow;

void crucialLink(int a, int b)
{
    int S = a;
    int E = b;
    queue<int> Q;
    int prev[MAX];

    fill(prev,prev+MAX,-1);
    Q.push(S);

    while(!Q.empty() && prev[E] == -1)
    {
        int cur = Q.front();
        Q.pop();

        for(auto &next : adj[cur])
        {
            if(c[cur][next] - f[cur][next] > 0 && prev[next] == -1)
            {
                prev[next] = cur;
                Q.push(next);
                if(next == E)
                {
                    break;
                }
            }
        }
    }

    if(prev[E] == -1)
    {
        cntCrucialLink++;
    }

}

void init()
{
    cntCrucialLink = 0;
    maximumFlow = 0;
    cl.clear();
    for(int i = 0;i<MAX;++i)
    {
        adj[i].clear();
        for(int j = 0;j<MAX;++j)
        {
            c[i][j] = 0;
            f[i][j] = 0;
        }
    }
}

int main()
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    cin>>K;
    while(K--)
    {
        init();

        cin>>N>>M;

        for(int i = 1;i<=M;++i)
        {
            int u,v,w;
            cin>>u>>v>>w;
            
            adj[u].push_back(v);
            adj[v].push_back(u);
            
            cl.push_back(pair<int,int>(u,v));

            c[u][v] += w;
        }

        int S = 1;
        int E = N;

        while(true)
        {
            int prev[MAX];
            queue<int> Q;
            fill(prev,prev+MAX,-1);

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
            maximumFlow += flow;
        }
        //최대 유량을 흘려보낸 후 이므로, 소스에서 싱크로 가는 여유 경로는 존재하지 않는다

        for(auto &p : cl)
        {
            if(c[p.first][p.second] - f[p.first][p.second] != 0)
            {
                continue;
            }
            if(c[p.first][p.second] == 0)
            {
                continue;
            }
            crucialLink(p.first, p.second);
        }

        cout<<cntCrucialLink<<'\n';
    }

	return 0;
}

