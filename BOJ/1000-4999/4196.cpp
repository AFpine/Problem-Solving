#include <bits/stdc++.h>

// 4196 도미노

// update 220512

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 100001;

int T;
int N,M;
int x,y;
int cnt;
int result;
int indegree[MAX];
int dfsn[MAX];
bool finished[MAX];
bool selected[MAX];
vector<int> adj[MAX];
stack<int> st;
int p[MAX];

int find(int a)
{
	if(p[a] < 0)
	{
		return a;
	}
	return p[a] = find(p[a]);
}

void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if(a == b)
	{
		return;
	}
	p[b] = a;
}

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
			if(find(a) != find(cur))
			{
				merge(a,cur);
			}
			if(a == cur)
			{
				break;
			}
		}
	}
	return res;
}

void init()
{
	cnt = 0;
	result = 0;
	while(!st.empty())
	{
		st.pop();
	}
	for(int i = 1;i<=100000;++i)
	{
		p[i] = -1;
		dfsn[i] = 0;
		indegree[i] = 0;
		finished[i] = false;
		selected[i] = false;
		adj[i].clear();
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

		cin>>N>>M;

		for(int i = 1;i<=M;++i)
		{
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

		for(int i = 1;i<=N;++i)
		{
			for(auto &e : adj[i])
			{
				if(find(i) != find(e))
				{
					indegree[find(e)]++;
				}
			}
		}

		for(int i = 1;i<=N;++i)
		{
			if(indegree[find(i)] == 0 && selected[find(i)] == false)
			{
				selected[find(i)] = true;
				result++;
			}
		}

		cout<<result<<'\n';
	}

	return 0;
}
