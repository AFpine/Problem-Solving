#include <bits/stdc++.h>

// 5719 거의 최단 경로

// update 220505

using namespace std;

const int INF = 1e9+7;
const int minINF = -2e9-1;

int N,M;
int S,D;
int U,V,P;
int dist[501];
vector<int> adj[501],radj[501];
int cost[501][501];
bool visited[501];

void init()
{
	for(int i = 0;i<=500;++i)
	{
		dist[i] = INF;
		visited[i] = false;
		adj[i].clear();
		radj[i].clear();
		for(int j = 0;j<=500;++j)
		{
			cost[i][j] = INF;
		}
	}
}

void dijk(int S, int D)
{
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	pq.push({0,S});

	while(!pq.empty())
	{
		int cur = pq.top().second;
		pq.pop();

		if(visited[cur] == true)
		{
			continue;
		}
		visited[cur] = true;

		for(auto x : adj[cur])
		{
			if(dist[x] > dist[cur] + cost[cur][x])
			{
				dist[x] = dist[cur] + cost[cur][x];
				pq.push({dist[x],x});
			}
		}
	}
}

void erasepath(int S, int D)
{
	queue<int> Q;
	Q.push(D);

	while(!Q.empty())
	{
		int cur = Q.front();
		Q.pop();

		for(auto x : radj[cur])
		{
			if(dist[cur] == dist[x] + cost[x][cur])
			{
				cost[x][cur] = INF;
				Q.push(x);
			}
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while(true)
	{
		cin>>N>>M;
		if(N == 0 && M == 0)
		{
			break;
		}
		cin>>S>>D;

		init();

		for(int i = 1;i<=M;++i)
		{
			cin>>U>>V>>P;
			adj[U].push_back(V);
			radj[V].push_back(U);
			cost[U][V] = P;
		}

		dist[S] = 0;
		dijk(S,D);
		
		erasepath(S,D);
		for(int i = 0;i<=500;++i)
		{
			visited[i] = false;
			dist[i] = INF;
		}

		dist[S] = 0;
		dijk(S,D);

		if(dist[D] == INF)
		{
			cout<<"-1"<<'\n';
		}
		else
		{
			cout<<dist[D]<<'\n';
		}
	}


	return 0;
}

