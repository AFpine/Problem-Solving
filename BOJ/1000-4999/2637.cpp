#include <bits/stdc++.h>

// 1637 장난감 조립

// update 220512

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 100001;

int N,M;
int X,Y,K;

int need[101];
vector<pair<int,int>> adj[101];
int indegree[101];
int outdegree[101];
vector<int> baseIngre;
queue<int> Q;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>M;
	for(int i = 1;i<=M;++i)
	{
		cin>>X>>Y>>K;
		adj[X].push_back({Y,K});
		indegree[Y]++;
		outdegree[X]++;
	}

	for(int i = 1;i<=N;++i)
	{
		if(indegree[i] == 0)
		{
			Q.push(i);
			need[i] = 0;
		}
		if(outdegree[i] == 0)
		{
			baseIngre.push_back(i);
		}
	}
	need[N] = 1;

	for(int i = 1;i<=N;++i)
	{
		int cur = Q.front();
		Q.pop();

		for(auto next : adj[cur])
		{
			need[next.first] += (next.second * need[cur]);
			if(--indegree[next.first] == 0)
			{
				Q.push(next.first);
			}
		}
	}

	for(auto i : baseIngre)
	{
		cout<<i<<" "<<need[i]<<'\n';
	}

	return 0;
}
