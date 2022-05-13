#include <bits/stdc++.h>

// 6543 그래프의 싱크

// update 220513

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 5005;

int n,m;
int v,w;
int cnt, sccnum;
int dfsn[MAX];
int sccidx[MAX];
bool outdegree[MAX];
bool finished[MAX];
vector<int> adj[MAX];
vector<vector<int>> scc;
stack<int> st;
vector<int> result;

int dfs(int cur)
{
	dfsn[cur] = ++cnt;
	st.push(cur);

	int res = dfsn[cur];
	for(auto &e : adj[cur])
	{
		if(dfsn[e] == 0)
		{
			res = min(res,dfs(e));
		}
		else if(finished[e] == false)
		{
			res = min(res,dfsn[e]);
		}
	}

	if(res == dfsn[cur])
	{
		vector<int> tempscc;
		while(true)
		{
			int a = st.top();
			st.pop();
			sccidx[a] = sccnum;
			finished[a] = true;
			tempscc.push_back(a);
			if(a == cur)
			{
				break;
			}
		}
		sort(tempscc.begin(),tempscc.end());
		scc.push_back(tempscc);
		sccnum++;
	}

	return res;
}

void init()
{
	sccnum = 0;
	cnt = 0;
	scc.clear();
	result.clear();
	while(!st.empty())
	{
		st.pop();
	}
	for(int i = 0;i<MAX;++i)
	{
		dfsn[i] = 0;
		sccidx[i] = 0;
		finished[i] = false;
		outdegree[i] = false;
		adj[i].clear();
	}
}

int main()
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while(true)
	{	
		init();
		cin>>n;
		if(n == 0)
		{
			break;
		}
		cin>>m;

		for(int i = 1;i<=m;++i)
		{
			cin>>v>>w;
			adj[v].push_back(w);	
		}

		for(int i = 1;i<=n;++i)
		{
			if(dfsn[i] == 0)
			{
				dfs(i);
			}
		}

		for(int i = 1;i<=n;++i)
		{
			for(auto &e : adj[i])
			{
				if(sccidx[i] != sccidx[e])
				{
					outdegree[sccidx[i]] = true;
				}
			}
		}

		for(int i = 0;i<sccnum;++i)
		{
			if(outdegree[i] == false)
			{
				for(auto x : scc[i])
				{
					result.push_back(x);
				}
			}
		}

		sort(result.begin(),result.end());

		for(auto x : result)
		{
			cout<<x<<" ";
		}

		cout<<"\n";
	}

	return 0;
}
