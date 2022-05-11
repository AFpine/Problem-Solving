#include <bits/stdc++.h>

// 24977 Visits

// update 220511

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 100001;

struct Edge
{
	int u,v;
	long long cost;
	bool operator<(const Edge &e)
	{
		return cost > e.cost;
	}
};

long long result = 0;
int N;
int p[MAX];
vector<Edge> edge;

int find(int a)
{
	if(p[a] < 0)
	{
		return a;
	}
	return p[a] = find(p[a]);
}

void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if(a == b)
	{
		return;
	}
	p[a] = b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for(int i = 1;i<=100000;++i)
	{
		p[i] = -1;
	}

	cin>>N;

	for(int i = 1;i<=N;++i)
	{
		int v;
		long long cost;
		cin>>v>>cost;
		edge.push_back({i,v,cost});
	}

	sort(edge.begin(),edge.end());

	for(auto &e : edge)
	{
		if(find(e.u) != find(e.v))
		{
			merge(e.u,e.v);
			result += e.cost;
		}
	}

	cout<<result;

	return 0;
}
