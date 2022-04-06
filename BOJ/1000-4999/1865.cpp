#include <bits/stdc++.h>

// 1865 Wormhole (Bellman-Ford)

// update 220325

using namespace std;

static const int INF = 100000000;

struct Edge
{
	int start;
	int end;
	int time;
};

int world[501];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int TC;
	cin>>TC;

	for(int t = 0;t<TC;++t)
	{
		bool flag = false;
		int N,M,W;
		int S,E,T;
		vector<Edge> edgev;
		cin>>N>>M>>W;

		for(int i = 0;i<M;++i)
		{
			cin>>S>>E>>T;
			edgev.push_back({S,E,T});
			edgev.push_back({E,S,T});
		}
		for(int i = 0;i<W;++i)
		{
			cin>>S>>E>>T;
			edgev.push_back({S,E,-T});
		}

		for(int j = 1;j<=N;++j)
		{
			world[j] = INF;
		}

		for(int v = 1;v<=N-1;++v)
		{
			for(auto x : edgev)
			{
				if(world[x.end] > world[x.start] + x.time)
				{
					world[x.end] = world[x.start] + x.time;
				}
			}
		}
		for(auto x : edgev)
		{
			if(world[x.end] > world[x.start] + x.time)
			{
				flag = true;
				world[x.end] = world[x.start] + x.time;
			}
		}
		if(flag)
		{
			cout<<"YES\n";
		}
		else
		{
			cout<<"NO\n";
		}
	}

	return 0;
	
}