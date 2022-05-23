#include <bits/stdc++.h>

// 23314 Minimum Spanning Cactus

// update 220521

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 300005;

int N,M,Q;
int cnt, bcccnt, edgecnt;
int dfsn[MAX];
int bccidx[MAX];
int edgeCost[MAX];
long long totalCost = 0;
vector<int> adj[MAX];
stack<pair<int,int>> st;
vector<vector<pair<int,int>>> bcc;
map<pair<int,int>,int> edge;
multiset<int> bccEdge[MAX];
long long maxEdge[MAX];
bool erasedBcc[MAX];
bool artiedge[MAX];

int dfs(int cur, int prev = -1)
{
    int res = dfsn[cur] = ++cnt;

    for(auto &next : adj[cur])
    {
        if(next == prev)
        {
            continue;
        }
        if(dfsn[cur] > dfsn[next])
        {
            st.push({cur,next});
        }
        if(dfsn[next] > 0)
        {
            res = min(res,dfsn[next]);
        }
        else
        {
            int temp = dfs(next,cur);
            res = min(res,temp);
            
            if(temp >= dfsn[cur])
            {
                vector<pair<int,int>> tempbcc;
                while(!st.empty() && st.top() != pair<int,int>(cur,next))
                {
                    tempbcc.push_back(st.top());
                    bccidx[edge[st.top()]] = bcccnt;
                    st.pop();
                }
                tempbcc.push_back(st.top());
                bccidx[edge[st.top()]] = bcccnt;
                st.pop();
                bcc.push_back(tempbcc);
                bcccnt++;
            }
        }
    }

    return res;
}

int main()
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin>>N>>M>>Q;

    for(int i = 1;i<=M;++i)
    {
        int u,v;
        int c;
        cin>>u>>v>>c;
        adj[u].push_back(v);
        adj[v].push_back(u);
        if(!edge.count(pair<int,int>(u,v)) && !edge.count(pair<int,int>(v,u)))
        {
            edgecnt++;
            edge[pair<int,int>(u,v)] = edgecnt;
            edge[pair<int,int>(v,u)] = edgecnt;
            edgeCost[edgecnt] = c;
        }
    }

    for(int i = 1;i<=N;++i)
    {
        if(dfsn[i] == 0)
        {
            dfs(i);
        }
    }

    for(int i = 0;i<bcccnt;++i)
    {
        if(bcc[i].size() > 1)
        {
            artiedge[i] = false;
            for(auto &p : bcc[i])
            {
                bccEdge[i].insert(edgeCost[edge[p]]);
                totalCost += edgeCost[edge[p]];
            }
            maxEdge[i] = *(bccEdge[i].rbegin());
            if(maxEdge[i] > 0)
            {
                erasedBcc[i] = true;
                totalCost -= maxEdge[i];
            }
            else
            {
                erasedBcc[i] = false;
            }
        }
        else if(bcc[i].size() == 1)
        {
            totalCost += edgeCost[edge[bcc[i][0]]];
            artiedge[i] = true;
        }
    }
    cout<<totalCost<<'\n';

    while(Q--)
    {
        int x,y;
        int d;
        cin>>x>>y>>d;
        
        pair<int,int> curedge = {x,y};
        int curbccidx = bccidx[edge[curedge]];

        if(artiedge[curbccidx] == true)
        {
            totalCost -= edgeCost[edge[curedge]];
            edgeCost[edge[curedge]] = d;
            totalCost += d;
        }
        else
        {
            if(erasedBcc[curbccidx] == true)
            {
                totalCost += maxEdge[curbccidx];
            }
            auto it = bccEdge[curbccidx].find(edgeCost[edge[curedge]]);
            bccEdge[curbccidx].erase(it);
            totalCost -= edgeCost[edge[curedge]];
            edgeCost[edge[curedge]] = d;
            bccEdge[curbccidx].insert(d);
            totalCost += d;
            maxEdge[curbccidx] = *(bccEdge[curbccidx].rbegin());
            if(maxEdge[curbccidx] > 0)
            {
                erasedBcc[curbccidx] = true;
                totalCost -= maxEdge[curbccidx];
            }
            else
            {
                erasedBcc[curbccidx] = false;
            }
        }
        cout<<totalCost<<'\n';
    }
	
	return 0;
}

