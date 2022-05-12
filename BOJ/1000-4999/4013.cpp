#include <bits/stdc++.h>

// 4013 ATM

// update 220512

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 500001;

int N,M;
int S,P;
int cnt = 0,sccnum = 0;
int ATM[MAX];
int dfsn[MAX];
vector<int> adj[MAX];
bool rest[MAX];
bool finished[MAX];
int sccidx[MAX];
int indegree[MAX];
bool sccrest[MAX];
int sccmoney[MAX];
vector<int> sccoutdegree[MAX];
stack<int> st;
queue<int> Q;
int sccStart;
bool sccReach[MAX];

int result[MAX];

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
		int money = 0;
		while(true)
		{
			int a = st.top();
			st.pop();
			money += ATM[a];
			finished[a] = true;
			sccidx[a] = sccnum;
			if(rest[a] == true)
			{
				sccrest[sccnum] = true;
			}
			if(a == S)
			{
				sccStart = sccnum;
			}
			if(cur == a)
			{
				break;
			}
		}
		sccmoney[sccnum] = money;
		sccnum++;
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
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
	}
	for(int i = 1;i<=N;++i)
	{
		cin>>ATM[i];
	}
	cin>>S>>P;
	for(int i = 1;i<=P;++i)
	{
		int temp;
		cin>>temp;
		rest[temp] = true;
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
			if(sccidx[i] != sccidx[e])
			{
				sccoutdegree[sccidx[i]].push_back(sccidx[e]);
				indegree[sccidx[e]]++;
			}
		}
	}

	for(int i = 0;i<sccnum;++i)
	{
		result[i] = sccmoney[i];
		if(i == sccStart)
		{
			sccReach[i] = true;
		}
		if(indegree[i] == 0)
		{
			Q.push(i);
		}
	}

	for(int i = 0;i<sccnum;++i)
	{
		int cur = Q.front();
		Q.pop();

		for(auto &e : sccoutdegree[cur])
		{
			if(sccReach[cur] == true)
			{
				result[e] = max(result[e],result[cur]+sccmoney[e]);
				sccReach[e] = true;
			}
			if(--indegree[e] == 0)
			{
				Q.push(e);
			}
		}
	}

	int maxresult = 0;
	for(int i = 0;i<sccnum;++i)
	{
		if(sccrest[i] == true && sccReach[i] == true)
		{
			maxresult = max(maxresult,result[i]);
		}
	}

	cout<<maxresult;

	return 0;
}
