#include <bits/stdc++.h>

// 3736 System Engineer

// update 220602

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 20005;

int N;
int A[MAX], B[MAX];
int level[MAX];
bool visited[MAX];
vector<int> adj[MAX];

void bfs()
{
	queue<int> Q;

	for(int i = 0; i<N;++i)
	{
		if(visited[i] == false)
		{
			level[i] = 0;
			Q.push(i);
		}
		else
		{
			level[i] = INF;
		}
	}

	while(!Q.empty())
	{
		int a = Q.front();
		Q.pop();
		for(auto &b : adj[a])
		{
			if(B[b] != -1 && level[B[b]] == INF)
			{
				level[B[b]] = level[a] + 1;
				Q.push(B[b]);
			}
		}
	}
}

bool dfs(int a)
{
	for(auto &b : adj[a])
	{
		if(B[b] == -1 || level[B[b]] == level[a]+1 && dfs(B[b]) == true)
		{
			visited[a] = true;
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}

void init()
{
	fill(visited,visited+MAX,false);
	for(int i = 0;i<MAX;++i)
	{	
		adj[i].clear();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while(scanf("%d",&N) > 0)
	{
		init();

		for(int i = 0;i<N;++i)
		{
			int tmp1, tmp2;
			scanf("%d: (%d) ",&tmp1,&tmp2);
			for(int j = 1;j<=tmp2;++j)
			{
				int b;
				scanf("%d",&b);
				adj[i].push_back(b);
				adj[b].push_back(i);
			}
		}

		int totalMatch = 0;
		fill(A,A+MAX,-1);
		fill(B,B+MAX,-1);
		while(true)
		{
			bfs();

			int flow = 0;
			for(int i = 0;i<N;++i)
			{
				if(visited[i] == false && dfs(i) == true)
				{
					flow++;
				}
			}
			if(flow == 0)
			{
				break;
			}
			totalMatch += flow;
		}

		printf("%d\n",totalMatch);

	}

	return 0;
}

