#include <bits/stdc++.h>

// 1516 게임 개발

// update 220511

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 100001;

int N;
vector<int> adj[501];
int indegree[501];
int cost[501];
int result[501];
queue<int> Q;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N;

	for(int i = 1;i<=N;++i)
	{
		int temp;
		cin>>cost[i];
		cin>>temp;
		while(temp != -1)
		{
			indegree[i]++;
			adj[temp].push_back(i);
			cin>>temp;
		}
	}
	
	for(int i = 1;i<=N;++i)
	{
		if(indegree[i] == 0)
		{
			Q.push(i);
			result[i] = cost[i];
		}
	}

	for(int i = 1;i<=N;++i)
	{
		int cur = Q.front();
		Q.pop();

		for(auto e : adj[cur])
		{
			result[e] = max(result[e],result[cur]+cost[e]);
			if(--indegree[e] == 0)
			{
				Q.push(e);
			}
		}
	}

	for(int i = 1;i<=N;++i)
	{
		cout<<result[i]<<'\n';
	}



	return 0;
}
