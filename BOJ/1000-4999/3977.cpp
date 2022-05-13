#include <bits/stdc++.h>

// 3977 축구 전술

// update 220513

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 100005;

int T;
int N,M,A,B;
int cnt,sccnum;
int sccidx[MAX];
int dfsn[MAX];
int indegree[MAX];
bool finished[MAX];
vector<int> adj[MAX];
stack<int> st;
vector<vector<int>> scc;

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
			finished[a] = true;
			sccidx[a] = sccnum;
			tempscc.push_back(a);
			if(cur == a)
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
	cnt = 0;
	sccnum = 0;
	scc.clear();
	while(!st.empty())
	{
		st.pop();
	}
	for(int i = 0;i<MAX;++i)
	{
		adj[i].clear();
		indegree[i] = 0;
		dfsn[i] = 0;
		finished[i] = 0;
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

		bool flag = false;
		int resultindex;

		cin>>N>>M;

		for(int i = 1;i<=M;++i)
		{
			cin>>A>>B;
			adj[A].push_back(B);
		}

		for(int i = 0;i<N;++i)
		{
			if(dfsn[i] == 0)
			{
				dfs(i);
			}
		}

		for(int i = 0;i<N;++i)
		{
			for(auto &e : adj[i])
			{
				if(sccidx[i] != sccidx[e])
				{
					indegree[sccidx[e]]++;
				}
			}
		}

		for(int i = 0;i<sccnum;++i)
		{
			if(indegree[i] == 0 && flag == false)
			{
				resultindex = i;
				flag = true;
			}
			else if(indegree[i] == 0 && flag == true)
			{
				flag = false;
				break;
			}
		}

		if(flag)
		{
			sort(scc[resultindex].begin(),scc[resultindex].end());
			for(auto x : scc[resultindex])
			{
				cout<<x<<'\n';
			}
		}
		else
		{
			cout<<"Confused\n";
		}
		cout<<'\n';

	}
	return 0;
}
