#include <bits/stdc++.h>

// 1948 임계 경로

// update 220517

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 10005;

int n,m;
vector<pair<int,int>> adj[MAX];
vector<pair<pair<int,int>,int>> reverseAdj[MAX];
int indegree[MAX];
int outdegree[MAX];
int longtime[MAX];
bool selectedEdge[100005];
queue<int> Q;
int resulttime;
int result = 0;


int main()
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for(int i = 0;i<MAX;++i)
	{
		longtime[i] = -1;
	}

	int start, end;
	cin>>n>>m;

	for(int i = 1;i<=m;++i)
	{
		int u,v,cost;
		cin>>u>>v>>cost;
		adj[u].push_back({v,cost});
		reverseAdj[v].push_back({{u,cost},i});
		outdegree[u]++;
		indegree[v]++;
	}

	cin>>start>>end;

	Q.push(start);
	longtime[start] = 0;
	while(!Q.empty())
	{
		int cur = Q.front();
		Q.pop();
		
		for(auto &e : adj[cur])
		{
			longtime[e.first] = max(longtime[e.first],longtime[cur]+e.second);
			if(--indegree[e.first] == 0)
			{
				Q.push(e.first);
			}
		}
	}

	Q.push(end);
	while(!Q.empty())
	{
		int cur = Q.front();
		Q.pop();
		
		for(auto &e : reverseAdj[cur])
		{
			if(longtime[e.first.first] == longtime[cur] - e.first.second && selectedEdge[e.second] == false)
			{
				result++;
				selectedEdge[e.second] = true;
				Q.push(e.first.first);
			}
		}
	}

	cout<<longtime[end]<<'\n'<<result;

	
	return 0;
}
