#include <bits/stdc++.h>

// 2887 행성 터널

// update 220507

using namespace std;

const int INF = 1e9+5;
const int minINF = -2e9-1;

struct Edge
{
	int u,v;
	int cost;
	bool operator<(const Edge& a)
	{
		return cost < a.cost;
	}
};

struct Planet
{
	int x,y,z;
};

int N;
vector<Edge> edge;
vector<pair<int,int>> planet[3];	//0 is x, 1 is y, 2 is z / first is value, second is index
int p[100001];

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

	for(int i = 0;i<=100000;++i)
	{
		p[i] = -1;
	}

	cin>>N;
	int result = 0;
	int cnt = 0;

	for(int i = 0;i<N;++i)
	{
		int x,y,z;
		cin>>x>>y>>z;
		planet[0].push_back({x,i});
		planet[1].push_back({y,i});
		planet[2].push_back({z,i});
	}

	sort(planet[0].begin(),planet[0].end());
	sort(planet[1].begin(),planet[1].end());
	sort(planet[2].begin(),planet[2].end());

	for(int i = 0;i<N-1;++i)
	{
		edge.push_back({planet[0][i].second,planet[0][i+1].second,(abs(planet[0][i].first-planet[0][i+1].first))});
		edge.push_back({planet[1][i].second,planet[1][i+1].second,(abs(planet[1][i].first-planet[1][i+1].first))});
		edge.push_back({planet[2][i].second,planet[2][i+1].second,(abs(planet[2][i].first-planet[2][i+1].first))});
	}

	sort(edge.begin(),edge.end());

	for(auto& e : edge)
	{
		if(find(e.u) == find(e.v))
		{
			continue;
		}
		result += e.cost;
		merge(e.u,e.v);
		cnt++;
		if(cnt == N-1)
		{
			break;
		}
	}

	cout<<result;

	return 0;
}

