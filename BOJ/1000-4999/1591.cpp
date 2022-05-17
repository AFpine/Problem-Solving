#include <bits/stdc++.h>

// 1591 수열 복원

// update 220517

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 5001;

int N,M;
int cntVertex = 0;
int cntEdge = 0;
map<vector<int>,int> veridx;
vector<pair<int,int>> adj[MAX];
vector<int> vertex[MAX];
int indegree[MAX];
int outdegree[MAX];
bool selectedEdge[MAX];
vector<int> result;

void dfs(int cur)
{
	for(auto &e : adj[cur])
	{
		if(selectedEdge[e.second] == false)
		{
			selectedEdge[e.second] = true;
			dfs(e.first);
		}
	}
	result.push_back(cur);
}

void eulerDFS()
{
	for(int i = 1;i<=cntVertex;++i)
	{
		if(indegree[i] < outdegree[i])
		{
			dfs(i);
			return;
		}
	}
	for(int i = 1;i<=cntVertex;++i)
	{
		if(outdegree[i] > 0)
		{
			dfs(i);
			return;
		}
	}
}

int main()
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>M;

	for(int i = 1;i<=N-M+1;++i)
	{
		int tempele;
		vector<int> temp1, temp2;
		for(int j = 1;j<=M;++j)
		{
			cin>>tempele;
			if(j == 1)
			{
				temp1.push_back(tempele);
			}
			else if(j == M)
			{
				temp2.push_back(tempele);
			}
			else
			{
				temp1.push_back(tempele);
				temp2.push_back(tempele);
			}
		}
		if(!veridx.count(temp1))
		{
			veridx[temp1] = ++cntVertex;
			vertex[veridx[temp1]] = temp1;
		}
		if(!veridx.count(temp2))
		{
			veridx[temp2] = ++cntVertex;
			vertex[veridx[temp2]] = temp2;
		}
		adj[veridx[temp1]].push_back({veridx[temp2],++cntEdge});
		outdegree[veridx[temp1]]++;
		indegree[veridx[temp2]]++;
	}

	eulerDFS();
	reverse(result.begin(),result.end());

	for(auto &i : vertex[result[0]])
	{
		cout<<i<<" ";
	}
	result.erase(result.begin());
	for(auto &i : result)
	{
		cout<<vertex[i].back()<<" ";
	}
	
	return 0;
}
