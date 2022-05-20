#include <bits/stdc++.h>

// 11281 2-SAT - 4

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
int result[MAX];
int boolscc[MAX];
pair<int,int> p[MAX];

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

void init()
{
    for(int i = 0;i<MAX;++i)
    {
        dfsn[i] = 0;
        boolscc[i] = -1;
        result[i] = -1;
    }
}

int main()
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    init();

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
            cout<<"0";
            return 0;
        }
    }

    for(int i = 1;i<=2*N;++i)
    {
        p[i].first = sccidx[i];
        p[i].second = i;
    }

    sort(p+1,p+(2*N)+1);
    //SCC들에 대해 위상정렬 (DFS방문 순서를 역순으로)

    for(int i = 2*N;i>=1;--i)
    {
        if(result[p[i].second] != -1)
        {//자신의 값이 정해져 있디면 : not의 값이 이전에 정해졌다면 
            continue;
        }
        if(boolscc[p[i].first] == -1)
        {//자신이 속한 SCC에서의 논리값이 정해져있지 않다면 = not의 값도 정해져 있지 않다
            boolscc[p[i].first] = 0;
            result[p[i].second] = 0;
            boolscc[sccidx[oppo(p[i].second)]] = 1;
            result[oppo(p[i].second)] = 1;
        }
        else
        {//자신이 속한 SCC에서의 논리값이 정해져 있으면, 그에 따라야 한다
            result[p[i].second] = boolscc[p[i].first];
        }
    }

    cout<<"1\n";
    for(int i = 2;i<=2*N;i+=2)
    {
        cout<<result[i]<<" ";
    }
    
	return 0;
}

