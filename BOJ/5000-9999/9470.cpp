#include <bits/stdc++.h>

// 9470 Strahler 순서

// update 220512

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 100001;

int T;
int K,M,P;
int A,B;
vector<int> adj[1001];
int indegree[1001];
int dist[1001];
bool distplus[1001];

void init()
{
	for(int i = 1;i<=1000;++i)
	{
		dist[i] = 0;
		indegree[i] = 0;
		adj[i].clear();
		distplus[i] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>T;
	K = 0;
	while(T--)
	{
		init();

		queue<int> Q;
		cin>>K>>M>>P;

		for(int i = 1;i<=P;++i)
		{
			cin>>A>>B;
			adj[A].push_back(B);
			indegree[B]++;
		}

		for(int i = 1;i<=M;++i)
		{
			dist[i] = 0;
			if(indegree[i] == 0)
			{
				dist[i] = 1;
				Q.push(i);
			}
		}

		for(int i = 1;i<=M;++i)
		{
			int cur = Q.front();
			Q.pop();

			for(auto next : adj[cur])
			{
				if(dist[next] < dist[cur])
				{
					dist[next] = dist[cur];
					distplus[next] = false;
				}
				else if(dist[next] == dist[cur])
				{
					distplus[next] = true;
				}
				if(--indegree[next] == 0)
				{
					if(distplus[next])
					{
						dist[next] += 1;
					}
					Q.push(next);
				}
			}
		}

		cout<<K<<" "<<dist[M]<<'\n';
	}


	return 0;
}
