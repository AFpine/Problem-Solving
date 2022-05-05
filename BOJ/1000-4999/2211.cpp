#include <bits/stdc++.h>

// 2211 네트워크 복구

// update 220505

using namespace std;

const int INF = 1e9+7;
const int minINF = -2e9-1;

int N,M;
int A,B,C;
int weight[1001][1001];
int cost[1001];
vector<int> adj[1001];
vector<pair<int,int>> result;
bool visited[1001];


void dijk()
{
	priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
	pq.push({0,{1,0}});

	while(!pq.empty())
	{
		int cur = pq.top().second.first;
		int prev = pq.top().second.second;
		pq.pop();

		if(visited[cur] == true)
		{
			continue;
		}
		visited[cur] = true;
		// cout<<prev<<cur<<cost[cur]<<'\n';
		result.push_back({cur,prev});
		for(auto x : adj[cur])
		{
			if(cost[x] > cost[cur] + weight[cur][x])
			{
				cost[x] = cost[cur] + weight[cur][x];
				pq.push({cost[x],{x,cur}});
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>M;

	for(int i = 1;i<=N;++i)
	{
		cost[i] = INF;
	}

	for(int i = 1;i<=M;++i)
	{
		cin>>A>>B>>C;
		
		adj[A].push_back(B);
		adj[B].push_back(A);
		weight[A][B] = C;
		weight[B][A] = C;
	}

	cost[1] = 0;

	dijk();

	cout<<result.size()-1<<'\n';

	for(int i = 1;i<result.size();++i)
	{
		cout<<result[i].first<<" "<<result[i].second<<'\n';
	}

	return 0;
}

