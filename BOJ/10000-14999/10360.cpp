#include <bits/stdc++.h>

// 10360 The Mountain of Gold?

// update 220506

using namespace std;

const long long INF = 1e18;
const int minINF = -2e9-1;

int T;
int N,M;
int A,B,C;

long long dist[1001];
vector<pair<int,int>> adj[1001];
bool cycle[1001];
bool visited[1001];

bool returncycle(int cur)
{
	if(cur == 0)
	{
		return true;
	}
	visited[cur] = true;

	for(auto x : adj[cur])
	{
		if(visited[x.first] == false)
		{
			visited[x.first] = true;
			return returncycle(x.first);
		}
	}
	return false;
}

void init()
{
	for(int i = 0;i<=1000;++i)
	{
		dist[i] = INF;
		adj[i].clear();
		cycle[i] = false;
		visited[i] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>T;
	int tc = 0;
	while(T--)
	{
		init();

		tc++;
		bool mcycle = false;
		bool mcyclereturn = false;

		cin>>N>>M;

		for(int i = 1;i<=M;++i)
		{
			cin>>A>>B>>C;
			adj[A].push_back({B,C});
		}

		dist[0] = 0;

		for(int i = 0;i<N;++i)
		{
			for(int j = 0;j<N;++j)
			{
				for(auto x : adj[j])
				{
					int next = x.first;
					int cost = x.second;
					if((dist[j] != INF) && (dist[next] > dist[j] + cost))
					{
						dist[next] = dist[j] + cost;
						if(i == N-1)
						{
							mcycle = true;
							cycle[next] = true;
						}
					}
				}
			}
		}

		for(int i = 0;i<N;++i)
		{
			if(cycle[i] == true)
			{
				if(returncycle(i))
				{
					mcyclereturn = true;
				}
			}
		}

		cout<<"Case #"<<tc<<": ";
		if(mcycle && mcyclereturn)
		{
			cout<<"possible"<<'\n';
		}
		else
		{
			cout<<"not possible"<<'\n';
		}
	}


	return 0;
}

