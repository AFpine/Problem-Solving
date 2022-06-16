#include <bits/stdc++.h>

// 3044 자전거 경주 준비하기

// update 220616

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 10005;
const int MOD = 1e9;

int N,M,cnt,scccnt;
vector<int> adj[MAX];
vector<int> dag[MAX];
int dfsn[MAX], sccidx[MAX], sccsize[MAX], indegree[MAX];
bool finished[MAX], cycle[MAX];
stack<int> st;
long long dp[MAX];

int dfs(int cur)
{
    int result = dfsn[cur] = ++cnt;
    st.push(cur);

    for(auto &e : adj[cur])
    {
        if(dfsn[e] == 0)
        {
            result = min(result, dfs(e));
        }
        else if(finished[e] == false)
        {
            result = min(result, dfsn[e]);
        }
    }
    if(dfsn[cur] == result)
    {
        while(true)
        {
            int a = st.top();
            st.pop();
            sccidx[a] = scccnt;
            finished[a] = true;
            sccsize[scccnt]++;
            if(a == cur)
            {
                break;
            }
        }
        scccnt++;
    }

    return result;
}


int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin>>N>>M;

    for(int i = 1;i<=M;++i)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }

    for(int i = 1;i<=N;++i)
    {
        if(dfsn[i] == 0)
        {
            dfs(i);
        }
    }
    
    if(sccidx[1] == sccidx[2])
    {
        cout<<"inf";
        return 0;
    }

    for(int i = 1;i<=N;++i)
    {
        for(auto &e : adj[i])
        {
            if(sccidx[i] != sccidx[e])
            {//scc 간의 DAG 생성
                dag[sccidx[i]].push_back(sccidx[e]);
                indegree[sccidx[e]]++;
            }
        }
    }

    queue<int> Q;
    bool overflow[MAX] = {false};
    //난 이 overflow 배열이 왜 있어야 하는지 잘 모르겠네
    
    dp[sccidx[1]] = 1;
    for(int i = 0;i<scccnt;++i)
    {
        if(indegree[i] == 0)
        {
            Q.push(i);
        }
    }

    while(!Q.empty())
    {
        int cur = Q.front();
        Q.pop();

        if(sccsize[cur] > 1 && dp[cur] > 0)
        {//1번 정점에서 도달할 수 있는 사이클
            cycle[cur] = true;
        }

        for(auto &e : dag[cur])
        {
            if(cycle[cur])
            {
                cycle[e] = true;
            }
            if(overflow[cur])
            {
                overflow[e] = true;
            }
            dp[e] += dp[cur];
            if(dp[e] >= MOD)
            {
                dp[e] %= MOD;
                overflow[e] = true;
            }
            if(--indegree[e] == 0)
            {
                Q.push(e);
            }
        }
    }

    if(cycle[sccidx[2]])
    {//1번 정점에서 도달할 수 있는 사이클이 2번 정점에까지 도달할 수 있으면
        cout<<"inf\n";
    }
    else
    {
        if(overflow[sccidx[2]])
        {
            printf("%09d",dp[sccidx[2]]);
        }
        else
        {
            cout<<dp[sccidx[2]];
        }
    }




    return 0;
}