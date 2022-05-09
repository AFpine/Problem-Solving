#include <bits/stdc++.h>

// 10217 KCM Travel

// update 220509

using namespace std;

const int INF = 2e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;

struct Edge
{
	int dest, cost,	time;
};

struct PQ
{
	long long dist;
	int cost, vert;
};

struct compare
{
	bool operator()(const PQ& a, const PQ& b)
	{
		return a.dist > b.dist;
	}
};

int T;
int N,M,K;
int u,v,c,d;
vector<Edge> adj[101];
//{dest, cost, time}
long long dist[101][10001];
bool visited[101][10001];
priority_queue<PQ,vector<PQ>,compare> pq;
//{dist, cost, vertex}

void init()
{
	for(int i = 1;i<=100;++i)
	{	
		adj[i].clear();
		for(int j = 0;j<=10000;++j)
		{
			visited[i][j] = false;
			dist[i][j] = llINF;
		}
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
		long long result = llINF;
		init();

		cin>>N>>M>>K;
		
		for(int i = 1;i<=K;++i)
		{
			cin>>u>>v>>c>>d;
			adj[u].push_back({v,c,d});
		}

		dist[1][0] = 0;
		pq.push({0,0,1});

		while(!pq.empty())
		{
			int curdist = pq.top().dist;
			int curcost = pq.top().cost;
			int curvert = pq.top().vert;
			pq.pop();

			if(visited[curvert][curcost] == true)
			{
				continue;
			}
			visited[curvert][curcost] = true;

			for(auto &e : adj[curvert])
			{
				if((curcost + e.cost <= M) && (dist[e.dest][curcost+e.cost] > dist[curvert][curcost] + e.time))
				{
					dist[e.dest][curcost+e.cost] = dist[curvert][curcost] + e.time;
					pq.push({dist[e.dest][curcost+e.cost],curcost+e.cost,e.dest});
				}
			}
		}

		for(int i = 0;i<=M;++i)
		{
			result = min(result,dist[N][i]);
		}

		if(result == llINF)
		{
			cout<<"Poor KCM\n";
		}
		else
		{
			cout<<result<<'\n';
		}
	}
	return 0;
}

