#include <bits/stdc++.h>

// 1504 Especial Shortest Path (Dijkstra)

// update 220313

using namespace std;

static const int MAXVALUE = 1000000000;

int dist[801];

struct Vertex
{
	vector<pair<int,int>> edge;
};

struct compare
{
	bool operator()(int n1, int n2)
	{
		return dist[n1]>dist[n2];
	}
};

void Dijkstra(int n, vector<Vertex>& v)
{
	priority_queue<int, vector<int>, compare> pq;
	pq.push(n);
	while(!pq.empty())
	{
		int now = pq.top();
		pq.pop();
		for(auto x : v[now].edge)
		{
			if(dist[now] + x.second < dist[x.first])
			{
				dist[x.first] = dist[now] + x.second;
				pq.push(x.first);
			}
		}
	}
}

void reset(int s, int e)
{
	for(int i = s;i<=e;++i)
	{
		dist[i] = MAXVALUE;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N,E;
	int a,b,c;
	int v1,v2;
	int n1, n2, n3;
	priority_queue<int> pq;
	vector<Vertex> v(801);
	int res12N = MAXVALUE, res21N = MAXVALUE, result = MAXVALUE;

	cin>>N>>E;

	for(int i = 1;i<=N;++i)
	{
		dist[i] = MAXVALUE;
	}
	for(int i = 0;i<E;++i)
	{
		cin>>a>>b>>c;
		v[a].edge.push_back({b,c});
		v[b].edge.push_back({a,c});
	}
	cin>>v1>>v2;


	dist[1] = 0;
	Dijkstra(1,v);
	if(dist[v1] != MAXVALUE)
	{
		n1 = dist[v1];
		reset(1,N);
		dist[v1] = 0;
		Dijkstra(v1,v);
		if(dist[v2] != MAXVALUE)
		{
			n2 = dist[v2];
			reset(1,N);
			dist[v2] = 0;
			Dijkstra(v2,v);
			if(dist[N] != MAXVALUE)
			{
				n3 = dist[N];
				res12N = n1+n2+n3;
			}
			else
			{
				res12N = MAXVALUE;
			}
		}
		else
		{
			res12N = MAXVALUE;
		}
	}
	
	reset(1,N);
	dist[1] = 0;
	Dijkstra(1,v);
	if(dist[v2] != MAXVALUE)
	{
		n1 = dist[v2];
		reset(1,N);
		dist[v2] = 0;
		Dijkstra(v2,v);
		if(dist[v1] != MAXVALUE)
		{
			n2 = dist[v1];
			reset(1,N);
			dist[v1] = 0;
			Dijkstra(v1,v);
			if(dist[N] != MAXVALUE)
			{
				n3 = dist[N];
				res21N = n1 + n2 + n3;
			}
			else
			{
				res21N = MAXVALUE;
			}
		}
		else
		{
			res21N = MAXVALUE;
		}
	}

	result = min(res12N, res21N);

	if(result >= MAXVALUE)
	{
		result = -1;
	}

	cout<<result<<"\n";
}