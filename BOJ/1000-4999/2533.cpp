#include <bits/stdc++.h>

// 2533 사회망 서비스

// update 220502

using namespace std;

const int INF = 1e9+7;
const int minINF = -2e9-1;

int N;
int u,v;
vector<int> adj[1000001], child[1000001];
bool visited[1000001];
int dp[1000001][2];
//1 is early adapter, 0 is not

void makeTree(int cur)
{
	// visited[cur] = true;
	for(auto x : adj[cur])
	{
		if(visited[x] == false)
		{
			visited[x] = true;
			child[cur].push_back(x);
			makeTree(x);
		}
	}
}

int sns(int cur, int prev)
{
	int &ret = dp[cur][prev];

	if(ret != -1)
	{
		return ret;
	}

	int ea = 0,nea = 0;

	ea = 1;
	for(auto x : child[cur])
	{//cur is early adapter
		ea += sns(x,1);
	}
	for(auto x : child[cur])
	{//cur is not early adapter
		nea += sns(x,0);
	}
	if(prev == 0)
	{//prev is not early adapter
		return ret = ea;
	}
	else
	{//prev is early adapter
		return ret = min(nea, ea);
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(dp,-1,sizeof(dp));

	cin>>N;

	for(int i = 1;i<N;++i)
	{
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	visited[1] = true;
	makeTree(1);

	cout<<sns(1,1);

	return 0;
}

