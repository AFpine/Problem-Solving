#include <bits/stdc++.h>

// 2213 트리의 독립집합

// update 220503

using namespace std;

const int INF = 1e9+7;
const int minINF = -2e9-1;

int n;
int weight[10001];
int parent[10001];
bool visited[10001];
vector<int> adj[10001], child[10001];
int dp[10001][2];
vector<int> result;

void makeTree(int cur)
{
	for(auto x : adj[cur])
	{
		if(visited[x] == false)
		{
			visited[x] = true;
			parent[x] = cur;
			child[cur].push_back(x);
			makeTree(x);
		}
	}
}

int f(int cur, int parent)
{
	int &ret = dp[cur][parent];
	if(ret != -1)
	{
		return ret;
	}

	int pick, notpick;
	pick = 0;
	notpick = 0;

	pick = weight[cur];
	for(auto x : child[cur])
	{
		pick += f(x,1);
	}
	for(auto x : child[cur])
	{
		notpick += max(f(x,1), f(x,0));
	}
	if(parent == 0)
	{
		return ret = max(pick,notpick);
	}
	else
	{
		return ret = notpick;
	}
}

void tracking(int cur, int parent)
{
	int pick, notpick;
	pick = 0;
	notpick = 0;
	pick = weight[cur];
	for(auto x : child[cur])
	{
		pick += f(x,1);
	}
	for(auto x : child[cur])
	{
		notpick += max(f(x,1), f(x,0));
	}

	if(dp[cur][parent] == pick)
	{
		result.push_back(cur);
		for(auto x : child[cur])
		{
			tracking(x,1);
		}
		return;
	}
	else
	{
		for(auto x : child[cur])
		{
			tracking(x,0);
		}
		return;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(dp,-1,sizeof(dp));

	cin>>n;

	for(int i = 1;i<=n;++i)
	{
		cin>>weight[i];
	}

	for(int i = 1;i<n;++i)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	visited[1] = true;
	makeTree(1);


	cout<<f(1,0)<<'\n';

	tracking(1,0);

	sort(result.begin(),result.end());
	for(auto x : result)
	{
		cout<<x<<" ";
	}

	return 0;
}

