#include <bits/stdc++.h>

// 14942 Ant

// update 220427

using namespace std;

const int INF = 1e9+7;
const int minINF = -2e9-1;
const int BINARY_MAX = 17;

int N;
int a,b,c;

int room[100001][BINARY_MAX+1];
int cost[100001][BINARY_MAX+1];
int ant[100001];
int depth[100001];
vector<pair<int,int>> adj[100001];

void dfs(int cur)
{
	for(auto x : adj[cur])
	{
		if(depth[x.first] == -1)
		{
			depth[x.first] = depth[cur] + 1;
			room[x.first][0] = cur;
			cost[x.first][0] = x.second;
			dfs(x.first);
		}
	}
}

int antmove(int n)
{
	int d = depth[n];
	int x = n;
	int e = ant[n];

	for(int i = BINARY_MAX;i>=0;--i)
	{
		if(d == 0)
		{
			return x;
		}
		if(d >= 1<<i && e >= cost[x][i])
		{
			e -= cost[x][i];
			x = room[x][i];
			d -= 1<<i;
		}
	}
	return x;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N;

	for(int i = 1;i<=N;++i)
	{
		cin>>ant[i];
		depth[i] = -1;
	}

	for(int i = 1;i<N;++i)
	{
		cin>>a>>b>>c;
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
	}

	depth[1] = 0;
	dfs(1);

	for(int j = 1;j<=BINARY_MAX;++j)
	{
		for(int i = 1;i<=N;++i)
		{
			room[i][j] = room[room[i][j-1]][j-1];
			cost[i][j] = cost[i][j-1] + cost[room[i][j-1]][j-1];
		}
	}
	

	for(int i = 1;i<=N;++i)
	{
		cout<<antmove(i)<<'\n';
	}
	

	return 0;
}

