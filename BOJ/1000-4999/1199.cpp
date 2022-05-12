#include <bits/stdc++.h>

// 1199 오일러 회로

// update 220512

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;

struct Edge
{
	int to;
	int num;
	Edge* arcEdge {nullptr};
};

int N;
vector<Edge*> adj[1001];
int degree[1001];
bool visited[1001];

int check(int cur)
{
	int result = 1;
	visited[cur] = true;
	for(auto &e : adj[cur])
	{
		if(visited[e->to] == false)
		{
			result += check(e->to);
		}
	}
	return result;
}

void dfs(int cur)
{
	while(adj[cur].size())
	{
		auto &e = adj[cur].back();
		if(e->num > 0)
		{
			e->num--;
			e->arcEdge->num--;
			dfs(e->to);
		}
		else
		{
			adj[cur].pop_back();
		}
	}
	cout<<cur<<" ";
}

int main()
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>N;

	for(int i = 1;i<=N;++i)
	{
		for(int j = 1;j<=N;++j)
		{
			int temp;
			cin>>temp;
			if(i < j && temp > 0)
			{
				Edge *e1 = new Edge{j,temp};
				Edge *e2 = new Edge{i,temp};
				e1->arcEdge = e2;
				e2->arcEdge = e1;
				adj[i].push_back(e1);
				adj[j].push_back(e2);
				degree[i] += temp;
				degree[j] += temp;
			}
		}
	}

	for(int i = 1;i<=N;++i)
	{
		if(degree[i] % 2 == 1)
		{
			cout<<"-1";
			return 0;
		}
	}

	bool flag = false;
	int start = -1;
	for(int i = 1;i<=N;++i)
	{
		if(visited[i] == false)
		{
			int component = check(i);
			if(component > 1 && flag == true)
			{
				cout<<"-1";
				return 0;
			}
			else
			{
				start = i;
				flag = true;
			}
		}
	}

	if(start == -1)
	{
		start = 1;
	}

	dfs(start);

	return 0;
}
