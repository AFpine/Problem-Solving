#include <bits/stdc++.h>

// 1162 도로포장

// update 220508

using namespace std;

const int INF = 2e9+5;
const int minINF = -2e9-1;

int N,M,K;
int u,v;
int cost;
long long dist[10001][21];
bool visited[10001][21];
vector<pair<int,int>> adj[10001];
priority_queue<tuple<long long,int,int>,vector<tuple<long long,int,int>>,greater<tuple<long long,int,int>>> pq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long result = 1e18;

	cin>>N>>M>>K;

	for(int i = 2;i<=N;++i)
	{
		for(int j = 0;j<=20;++j)
		{
			dist[i][j] = 1e18;
			visited[i][j] = false;
		}
	}

	for(int i = 1;i<=M;++i)
	{
		cin>>u>>v>>cost;
		adj[u].push_back({v,cost});
		adj[v].push_back({u,cost});
	}

	pq.push({0,1,0});
	while(!pq.empty())
	{
		long long curdist = get<0>(pq.top());
		int cur = get<1>(pq.top());
		int curk = get<2>(pq.top());
		pq.pop();
		
		if(visited[cur][curk] == true)
		{
			continue;
		}
		visited[cur][curk] = true;

		for(auto &e : adj[cur])
		{
			if((curk < K) && (dist[e.first][curk+1] > curdist))
			{
				dist[e.first][curk+1] = curdist;
				pq.push(make_tuple(dist[e.first][curk+1],e.first,curk+1));
			}
			if(dist[e.first][curk] > curdist + e.second)
			{
				dist[e.first][curk] = curdist + e.second;
				pq.push(make_tuple(dist[e.first][curk],e.first,curk));
			}
		}
	}

	for(int i = 0;i<=K;++i)
	{
		result = min(result,dist[N][i]);
	}

	cout<<result;

	return 0;
}

