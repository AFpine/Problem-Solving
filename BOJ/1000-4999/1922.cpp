#include <bits/stdc++.h>

// 1922 네트워크 연결

// update 220506

using namespace std;

const int INF = 1e9+5;
const int minINF = -2e9-1;

struct Edge
{
	int u,v,cost;
	bool operator<(const Edge& a)
	{
		return cost < a.cost;
	}
};

int N,M;
int a,b,c;
vector<Edge> edge;
int p[1001];

int find(int a)
{
	if(p[a] < 0)
	{
		return a;
	}
	p[a] = find(p[a]);
	return p[a];
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

	for(int i = 1;i<=1000;++i)
	{
		p[i] = -1;
	}

	int result = 0;

	cin>>N>>M;

	for(int i = 1;i<=M;++i)
	{
		cin>>a>>b>>c;
		edge.push_back({a,b,c});
	}

	sort(edge.begin(), edge.end());

	for(auto &e : edge)
	{
		if(find(e.u) != find(e.v))
		{
			merge(e.u,e.v);
			result += e.cost;
			N--;
			if(N == 1)
			{
				break;
			}
		}
	}

	cout<<result;

	return 0;
}

