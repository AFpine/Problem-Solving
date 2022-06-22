#include <bits/stdc++.h>

// 18231 파괴된 도시

// update 220622

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 2005;
const long long MOD = 1e9+7;

int N,M,K;
bool visited[MAX];
bool burn[MAX];
bool bomb[MAX];
vector<int> burnV;
vector<int> adj[MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>M;

	for(int i = 1;i<=M;++i)
	{
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);	
		adj[v].push_back(u);
	}

	cin>>K;
	for(int i = 1;i<=K;++i)
	{
		int k;
		cin>>k;
		burn[k] = true;
		burnV.push_back(k);
	}

	for(auto &b : burnV)
	{
		bool flag = false;
		for(auto &e : adj[b])
		{
			if(!burn[e])
			{
				flag = true;
			}
		}
		if(!flag)
		{
			bomb[b] = true;
			visited[b] = true;
			for(auto &e : adj[b])
			{
				if(burn[e])
				{
					visited[e] = true;
				}
			}
		}
	}

	bool incorrect = false;
	for(int i = 1;i<=N;++i)
	{
		if(burn[i] == true && visited[i] == false)
		{
			incorrect = true;
		}
	}

	if(incorrect)
	{
		cout<<"-1";
	}
	else
	{
		int cnt = 0;
		for(int i = 1;i<=N;++i)
		{
			if(bomb[i])
			{
				cnt++;
			}
		}
		cout<<cnt<<"\n";
		for(int i = 1;i<=N;++i)
		{
			if(bomb[i])
			{
				cout<<i<<" ";
			}
		}
	}




	return 0;
}