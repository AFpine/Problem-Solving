#include <bits/stdc++.h>

// 11280 2-SAT - 3

// update 220519

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 20010;

int N,M;
int cnt, scccnt;
int sccidx[MAX];
int dfsn[MAX];
bool finished[MAX];
vector<int> adj[MAX];
stack<int> st;
bool result = true;

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

    for(int i = 1;i<=M;++i)
    {
        int a,b;
        cin>>a>>b;
        if(a < 0)
        {
            a = -a;
            a *= 2;
            a = oppo(a);
        }
        else
        {
            a *= 2;
        }
        if(b < 0)
        {
            b = -b;
            b *= 2;
            b = oppo(b);
        }
        else
        {
            b *= 2;
        }
        adj[oppo(a)].push_back(b);
        adj[oppo(b)].push_back(a);
    }

    for(int i = 1;i<=2*N;++i)
    {
        if(dfsn[i] == 0)
        {
            sccDFS(i);
        }
    }

    for(int i = 1;i<=N;++i)
    {
        if(sccidx[2*i] == sccidx[2*i-1])
        {
            result = false;
            break;
        }
    }

    if(result)
    {
        cout<<"1";
    }
    else
    {
        cout<<"0";
    }
    
    
	return 0;
}

