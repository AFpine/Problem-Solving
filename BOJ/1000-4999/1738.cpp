#include <bits/stdc++.h>

// 1738 골목길

// update 220506

using namespace std;

const long long INF = 1e18;
const int minINF = -2e9-1;

int n,m,u,v,w;
long long dist[101];
vector<pair<int,int>> adj[101];
bool cycle[101];
bool visited[101];
int pre[101];

bool checkcycle(int cur)
{	
	if(cur == n)
	{
		return true;
	}
	visited[cur] = true;
	for(auto x : adj[cur])
	{
		int next = x.first;
		if(visited[next] == false)
		{
			visited[next] = true;
			return checkcycle(next);
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	bool mcycle = false;
	stack<int> result;

	for(int i = 1;i<=100;++i)
	{
		dist[i] = -INF;
	}

	cin>>n>>m;

	for(int i = 1;i<=m;++i)
	{
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
	}

	dist[1] = 0;
	pre[1] = -1;

	for(int i = 1;i<=n;++i)
	{
		for(int j = 1;j<=n;++j)
		{
			if(dist[j] == -INF)
			{
				continue;
			}
			for(auto x : adj[j])
			{
				int next = x.first;
				int cost = x.second;
				if(dist[next] < dist[j] + cost)
				{
					dist[next] = dist[j] + cost;
					pre[next] = j;
					if(i == n)
					{
						cycle[j] = true;
						cycle[next] = true;
					}
				}
			}
		}
	}

	for(int i = 1;i<=n;++i)
	{
		if(cycle[i] == true)
		{
			if(checkcycle(i))
			{
				mcycle = true;
				break;
			}
		}
	}

	if((mcycle) || (dist[n] == -INF))
	{
		cout<<"-1";
	}
	else
	{
		while(n != -1)
		{
			result.push(n);
			n = pre[n];
		}
		while(!result.empty())
		{
			cout<<result.top()<<" ";
			result.pop();
		}
	}
	

	return 0;
}

