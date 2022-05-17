#include <bits/stdc++.h>

// 1108 검색 엔진

// update 220517

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 1300;

map<string,int> site;
int N;
int cnt = 0, cntscc = 0;
int cntsite = 0;
int dfsn[MAX];
bool finished[MAX];
int sccidx[MAX];
int indegree[MAX];
vector<int> adj[MAX];
vector<vector<int>> scc;
stack<int> st;
long long score[MAX];
queue<int> Q;

int dfs(int cur)
{
	int res = dfsn[cur] = ++cnt;
	st.push(cur);

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
			sccidx[a] = cntscc;
			tempscc.push_back(a);
			if(cur == a)
			{
				break;
			}
		}
		scc.push_back(tempscc);
		cntscc++;
	}

	return res;
}

void linkdfs(int cur)
{
	for(auto &e : adj[cur])
	{
		if(sccidx[e] != sccidx[cur])
		{
			score[e] += score[cur];
			dfs(e);
		}
	}
}

int main()
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	string temps;
	int cntlink;

	cin>>N;

	for(int i = 1;i<=N;++i)
	{
		cin>>s;
		if(site.find(s) == site.end())
		{
			site.insert({s,++cntsite});
		}
		cin>>cntlink;
		for(int j = 1;j<=cntlink;++j)
		{
			cin>>temps;
			if(site.find(temps) == site.end())
			{
				site.insert({temps,++cntsite});
			}
			adj[site[temps]].push_back(site[s]);
			indegree[site[s]]++;
		}
	}
	cin>>s;

	for(int i = 1;i<=cntsite;++i)
	{
		score[i] = 1;
		if(dfsn[i] == 0)
		{
			dfs(i);
		}
	}

	for(int i = 1;i<=cntsite;++i)
	{
		for(auto &e : adj[i])
		{
			if(sccidx[e] == sccidx[i])
			{
				indegree[e]--;
			}
		}
	}

	for(int i = 1;i<=cntsite;++i)
	{
		if(indegree[i] == 0)
		{
			Q.push(i);
		}
	}

	for(int i = 1;i<=cntsite;++i)
	{
		int cur = Q.front();
		Q.pop();

		for(auto &e : adj[cur])
		{
			if(sccidx[e] != sccidx[cur])
			{
				score[e] += score[cur];
			}
			if(--indegree[e] == 0)
			{
				Q.push(e);
			}
		}
	}

	cout<<score[site[s]];

	
	return 0;
}
