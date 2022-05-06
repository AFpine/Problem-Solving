#include <bits/stdc++.h>

// 4343 Arctic Network

// update 220506

using namespace std;

const int INF = 1e9+5;
const int minINF = -2e9-1;

struct Edge
{
	int u,v;
	double cost;
	bool operator<(const Edge& a)
	{
		return cost < a.cost;
	}
};

struct Outpost
{
	double x,y;
};

int S,P;
vector<Edge> edge;
Outpost op[501];
int p[501];

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

double distance(Outpost& a, Outpost& b)
{
	return sqrt(pow((a.x-b.x),2) + pow((a.y-b.y),2));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin>>T;
	while(T--)
	{
		cin>>S>>P;

		double result = 0;
		
		for(int i = 0;i<=500;++i)
		{
			p[i] = -1;
		}
		edge.clear();

		for(int i = 1;i<=P;++i)
		{
			cin>>op[i].x>>op[i].y;
		}

		for(int i = 1;i<=P;++i)
		{
			for(int j = 1;j<=P;++j)
			{
				if(i == j)
				{
					continue;
				}
				edge.push_back({i,j,distance(op[i],op[j])});
			}
		}

		sort(edge.begin(), edge.end());

		for(auto &e : edge)
		{
			if(find(e.u) != find(e.v))
			{
				merge(e.u,e.v);
				P--;
				result = e.cost;
				if(P-(S-1) == 1)
				{
					break;
				}
			}
		}
		cout<<fixed;
		cout.precision(2);
		cout<<result<<'\n';
	}


	return 0;
}

