#include <bits/stdc++.h>

// 16915 호텔 관리

// update 220520

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 200010;

int N,M;
int cnt, scccnt;
int sccidx[MAX];
int dfsn[MAX];
bool finished[MAX];
vector<int> adj[MAX];
vector<int> connectedSwitch[MAX];
stack<int> st;
int doorStatus[MAX];

int oppo(int n)
{
    if(n % 2 == 0)
    {
        return n-1;
    }
    else
    {
        return n+1;
    }
}

int sccDFS(int cur)
{
    int res = dfsn[cur] = ++cnt;
    st.push(cur);

    for(auto &next : adj[cur])
    {
        if(dfsn[next] == 0)
        {
            res = min(res,sccDFS(next));
        }
        else if(finished[next] == false)
        {
            res = min(res,dfsn[next]);
        }
    }

    if(res == dfsn[cur])
    {
        while(true)
        {
            int a = st.top();
            st.pop();
            finished[a] = true;
            sccidx[a] = scccnt;
            if(a == cur)
            {
                break;
            }
        }
        scccnt++;
    }
    
    return res;
}

int main()
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin>>N>>M;

    for(int i = 1;i<=N;++i)
    {
        cin>>doorStatus[i];
    }

    for(int i = 1;i<=M;++i)
    {
        int k;
        int room;
        cin>>k;
        for(int j = 1;j<=k;++j)
        {
            cin>>room;
            connectedSwitch[room].push_back(i);
        }
    }

    for(int i = 1;i<=N;++i)
    {
        int s1 = connectedSwitch[i][0] * 2;
        int s2 = connectedSwitch[i][1] * 2;
        if(doorStatus[i] == 1)
        {
            adj[s1].push_back(s2);
            adj[s2].push_back(s1);
            adj[oppo(s1)].push_back(oppo(s2));
            adj[oppo(s2)].push_back(oppo(s1));
        }
        else
        {
            adj[s1].push_back(oppo(s2));
            adj[s2].push_back(oppo(s1));
            adj[oppo(s1)].push_back(s2);
            adj[oppo(s2)].push_back(s1);
        }
    }

    for(int i = 1;i<=2*M;++i)
    {
        if(dfsn[i] == 0)
        {
            sccDFS(i);
        }
    }

    for(int i = 1;i<=M;++i)
    {
        if(sccidx[i*2] == sccidx[i*2-1])
        {
            cout<<"0";
            return 0;
        }
    }

    cout<<"1";
   
	return 0;
}

