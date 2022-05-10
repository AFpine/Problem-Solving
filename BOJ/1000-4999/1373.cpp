#include <bits/stdc++.h>

// 1373 복도 뚫기

// update 220510

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;

struct Sensor
{
	int x,y,r;
};

struct Edge
{
	int u,v;
	double cost;
	bool operator<(const Edge &e)
	{
		return cost < e.cost;
	}
};

int T;
Sensor sensor[1005];
int p[1005];
vector<Edge> edge;
int w,n,x,y,r;

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

double distance(Sensor &a, Sensor &b)
{
	double ret = (sqrt(pow(a.x-b.x,2) + pow(a.y-b.y,2)))-(a.r+b.r);
	if(ret < 0)
	{
		return 0;
	}
	else
	{
		return ret;
	}
}

void init()
{
	edge.clear();
	for(int i = 0;i<=1004;++i)
	{
		p[i] = -1;
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
		init();

		cin>>w>>n;
		double result = 0;
		for(int i = 1;i<=n;++i)
		{
			cin>>sensor[i].x>>sensor[i].y>>sensor[i].r;
		}

		for(int i = 1;i<=n;++i)
		{
			for(int j = i+1;j<=n;++j)
			{
				edge.push_back({i,j,distance(sensor[i],sensor[j])});
			}
			edge.push_back({i,n+1,(double)sensor[i].x-sensor[i].r});
			edge.push_back({i,n+2,(double)w-sensor[i].x-sensor[i].r});
		}
		edge.push_back({n+1,n+2,(double)w});

		sort(edge.begin(),edge.end());

		for(auto &e : edge)
		{
			if(find(e.u) != find(e.v))
			{
				merge(e.u,e.v);
				if(find(n+1) == find(n+2))
				{
					result = e.cost;
					break;
				}
			}
		}
		
		cout<<fixed;
		cout.precision(6);
		if(result == 0)
		{
			cout<<"0\n";
		}
		else
		{
			cout<<result/2<<'\n';
		}
	}
	return 0;
}

