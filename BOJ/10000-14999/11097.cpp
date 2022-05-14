#include <bits/stdc++.h>

// 11097 도시 계획

// update 220514

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 301;

int t;
int n;
int cnt,sccnum;
int sccidx[MAX];
int dfsn[MAX];
bool finished[MAX];
vector<int> adj[MAX];
vector<vector<int>> scc;
stack<int> st;
vector<pair<int,int>> resultv;
int result;
int dist[MAX][MAX];

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

	if(dfsn[cur] == res)
	{
		vector<int> tempscc;
		while(true)
		{
			int a = st.top();
			st.pop();
			tempscc.push_back(a);
			finished[a] = true;
			sccidx[a] = sccnum;
			if(a == cur)
			{
				break;
			}
		}
		scc.push_back(tempscc);
		sccnum++;
	}

	return res;
}

void init()
{
	scc.clear();
	resultv.clear();
	sccnum = 0;
	result = 0;
	cnt = 0;
	while(!st.empty())
	{
		st.pop();
	}
	for(int i = 0;i<MAX;++i)
	{
		dfsn[i] = 0;
		sccidx[i] = -1;
		finished[i] = false;
		adj[i].clear();
		for(int j = 0;j<MAX;++j)
		{
			dist[i][j] = 0;
		}
	}
}

int main()
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>t;
	while(t--)
	{
		string s;

		init();
		
		cin>>n;

		for(int i = 1;i<=n;++i)
		{
			cin>>s;
			for(int j = 1;j<=n;++j)
			{
				if(i == j)
				{
					continue;
				}
				if(s[j-1] == '1')
				{
					adj[i].push_back(j);
				}
			}
		}

		for(int i = 1;i<=n;++i)
		{
			if(dfsn[i] == 0)
			{
				dfs(i);
			}
		}

		for(int i = 0;i<sccnum;++i)
		{
			int sccsize = scc[i].size();
			if(sccsize != 1)
			{
				for(int j = 0;j<sccsize-1;++j)
				{
					resultv.push_back({scc[i][j],scc[i][j+1]});
					result++;
				}
				result++;
				resultv.push_back({scc[i][sccsize-1],scc[i][0]});
			}
		}

		for(int i = 1;i<=n;++i)
		{
			for(auto &e : adj[i])
			{
				if(sccidx[i] != sccidx[e])
				{
					dist[sccidx[i]][sccidx[e]] = 1;
				}
			}
		}

		for(int k = 0;k<sccnum;++k)
		{
			for(int i = 0;i<sccnum;++i)
			{
				for(int j = 0;j<sccnum;++j)
				{
					if(i == j || i == k || k == j)
					{
						continue;
					}
					else if(dist[i][j] &&(dist[i][k] && dist[k][j]))
					{
						dist[i][j] = 0;
					}
				}
			}
		}

		for(int i = 0;i<sccnum;++i)
		{
			for(int j = 0;j<sccnum;++j)
			{
				if(i == j)
				{
					continue;
				}
				if(dist[i][j] == 1)
				{
					resultv.push_back({scc[i][0],scc[j][0]});
					result++;
				}
			}
		}

		cout<<result<<'\n';
		for(auto &p : resultv)
		{
			cout<<p.first<<" "<<p.second<<'\n';
		}
		cout<<'\n';
	}
	
	return 0;
}
