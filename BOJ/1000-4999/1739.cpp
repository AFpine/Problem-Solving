#include <bits/stdc++.h>

// 1739 도로 정비하기

// update 220525

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 4020;
const int p = 2010;

int T;
int N,M,K;
int cnt;
int dfsn[MAX];
int sccidx[MAX];
bool finished[MAX];
vector<int> adj[MAX];
stack<int> st;
int sccnum;
vector<vector<int>> scc;

int oppo(int a)
{
    if(a % 2 == 1)
    {//if not, return origin
        return a+1;
    }
    else
    {//if origin, return not
        return a-1;
    }
}

int dfs(int cur)
{
    int res = dfsn[cur] = ++cnt;
    st.push(cur);

    for(auto &e : adj[cur])
    {
        if(dfsn[e] == 0)
        {
            res = min(res, dfs(e));
        }
        else if(finished[e] == false)
        {
            res = min(res, dfsn[e]);
        }
    }

    if(res == dfsn[cur])
    {
        vector<int> tempV;
        while(true)
        {
            int a = st.top();
            st.pop();
            finished[a] = true;
            sccidx[a] = sccnum;
            tempV.push_back(a);
            if(cur == a)
            {
                break;
            }
        }
        scc.push_back(tempV);
        sccnum++;
    }

    return res;
}

void init()
{
    cnt = 0;
    sccnum = 0;
    while(!st.empty())
    {
        st.pop();
    }
    for(int i = 0;i<MAX;++i)
    {
        adj[i].clear();
        finished[i] = false;
        dfsn[i] = 0;
        sccidx[i] = 0;
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
        
        cin>>N>>M>>K;

        for(int i = 1;i<=K;++i)
        {
            int A,B,C,D;
            cin>>A>>B>>C>>D;
            A *= 2;
            B = B*2 + p;
            C *= 2;
            D = D*2 + p;
            if(A == C && B == D)
            {
                continue;
            }

            if(A > C)
            {
                B = oppo(B);
                D = oppo(D);
            }
            if(B > D)
            {
                A = oppo(A);
                C = oppo(C);
            }
            adj[oppo(A)].push_back(B);
            adj[oppo(B)].push_back(A);
            adj[oppo(A)].push_back(C);
            adj[oppo(C)].push_back(A);
            adj[oppo(D)].push_back(B);
            adj[oppo(B)].push_back(D);
            adj[oppo(D)].push_back(C);
            adj[oppo(C)].push_back(D);
        }

        for(int i = 1;i<=2*N;++i)
        {
            if(dfsn[i] == 0)
            {
                dfs(i);
            }
        }
        for(int i = 1+p;i<=2*M+p;++i)
        {
            if(dfsn[i] == 0)
            {
                dfs(i);
            }
        }


        bool result = true;
        for(int i = 2;i<=2*N;i+=2)
        {
            if(sccidx[i] == sccidx[i-1])
            {
                result = false;
                break;
            }
        }
        for(int i = 2+p;i<=2*M+p;i+=2)
        {
            if(sccidx[i] == sccidx[i-1])
            {
                result = false;
                break;
            }
        }

        if(result)
        {
            cout<<"Yes\n";
        }
        else
        {
            cout<<"No\n";
        }
    }
    

	
	return 0;
}

