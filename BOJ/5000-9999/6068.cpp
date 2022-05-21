#include <bits/stdc++.h>

// 6068 최대 유량

// update 220521

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 53;

int N;
int Flow[MAX];
int c[MAX][MAX];
int f[MAX][MAX];
vector<int> adj[MAX];
int total = 0;

int ctoi(char c)
{
    if(c >= 'a' && c <= 'z')
    {
        return c - 'a';
    }
    else
    {
        return c - 'A' + 26;
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
        char u,v;
        int w;
        cin>>u>>v>>w;
        u = ctoi(u);
        v = ctoi(v);
        c[u][v] += w;
        c[v][u] += w;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int S = ctoi('A');
    int E = ctoi('Z');

    while(true)
    {
        int prev[MAX];
        fill(prev,prev+MAX,-1);
        queue<int> Q;

        Q.push(S);
        while(!Q.empty() && prev[E] == -1)
        {//증가 경로 찾는 BFS (소스에서 싱크까지 하나의 가능한 경로를 찾을 때까지)
            int cur = Q.front();
            Q.pop();
            for(auto &next : adj[cur])
            {
                if(c[cur][next] - f[cur][next] > 0 && prev[next] == -1)
                {//cur에서 next까지 유량을 흘릴 여유 용량이 있는가?
                    Q.push(next);
                    prev[next] = cur;
                    //이번 BFS에서 경로를 기억 (adj배열을 사용하지 않음. 매 BFS에서 남는 용량에 따라 경로가 바뀔 수 있음(심지어 역방향 으로도))
                    if(next == E)
                    {//싱크에 도달하면 이번 BFS는 끝
                        break;
                    }
                }
            }
        }

        if(prev[E] == -1)
        {//싱크로 가는 더 이상의 증가 경로가 없으면 끝
            break;
        }

        int flow = INF;
        for(int i = E; i != S; i = prev[i])
        {//경로상에서 보낼 수 있는 최대의 유량을 찾음(여유 용량이 가장 작은 값)
            flow = min(flow,c[prev[i]][i] - f[prev[i]][i]);
        }
        for(int i = E; i != S; i = prev[i])
        {//찾은 유량만큼 경로에 유량을 보냄
            f[prev[i]][i] += flow;
            f[i][prev[i]] -= flow;
        }

        total += flow;
    }

    cout<<total;



	return 0;
}

