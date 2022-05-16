#include <bits/stdc++.h>

// 11400 단절선

// update 220516

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 100001;

int V,E,cnt;
int dfsn[MAX];
vector<int> adj[MAX];
vector<vector<pair<int,int>>> bcc;
stack<pair<int,int>> st;
vector<pair<int,int>> result;
int resultcnt = 0;

int dfs(int cur, int prev = -1)
{//BCC Algorithm
	int res = dfsn[cur] = ++cnt;
    //res 는 dfs 상에서 트리, 역박향 간선으로 도달 가능한 최소의 dfsn
    //scc 에서도 비슷하게, 이 정점으로 부터 도달할 수 있는 제일 작은 dfsn
	for(auto &e : adj[cur])
	{
		if(e == prev)
		{//dfs 트리에서 자신의 부모면 스킵
			continue;
		}
		//아직 방문하지 않은 간선이면 스택에 간선 (cur,e)를 push
		if(dfsn[cur] > dfsn[e])
		{//역방향 간선
        	st.push({cur,e});
		}
		if(dfsn[e] > 0)
		{//트리 간선
			res = min(res,dfsn[e]);
		}
		else
		{//재귀적으로
			int temp = dfs(e,cur);
			res = min(res,temp);
            //e가 dfs트리상에서 cur의 조상 노드로 갈 수 없다면 : 새로운 BCC
			if(temp >= dfsn[cur])
			{//스택에 쌓여있던 간선을 뺀다 / 간선 (cur,e)까지만 뺀다
				vector<pair<int,int>> tempbcc;
				while(!st.empty() && st.top() != pair<int,int>(cur,e))
				{
					tempbcc.push_back(st.top());
					st.pop();
				}
				tempbcc.push_back(st.top());
				st.pop();
				bcc.push_back(tempbcc);
			}
		}
	}

    //res : 최소 도달 가능 dfsn
	return res;
}

int main()
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>V>>E;

	for(int i = 1;i<=E;++i)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for(int i = 1;i<=V;++i)
	{
		if(dfsn[i] == 0)
		{
			dfs(i);
		}	
	}

    for(auto &curbcc : bcc)
    {
        if(curbcc.size() == 1)
        {
            if(curbcc[0].first >= curbcc[0].second)
            {
                result.push_back({curbcc[0].second,curbcc[0].first});
            }
            else
            {
                result.push_back({curbcc[0].first,curbcc[0].second});
            }
        }
    }

    sort(result.begin(),result.end());
    cout<<result.size()<<'\n';
    for(auto &p : result)
    {
        cout<<p.first<<" "<<p.second<<'\n';
    }



	return 0;
}
