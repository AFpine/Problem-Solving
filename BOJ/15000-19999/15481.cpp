#include <bits/stdc++.h>

// 15481 그래프와 MST

// update 220622

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 200005;
const int BMAX = 18;
const long long MOD = 1e9+7;

struct Edge
{
	int u,v,w;
};

int N,M;
long long MST;
int cnt = 0;
vector<Edge> edge, sorted;
long long result[MAX];
vector<pair<int,int>> adj[MAX];
bool visited[MAX];
int depth[MAX];
int parent[MAX][BMAX];
int maxW[MAX][BMAX];
int uf[MAX];

bool cmp(Edge a, Edge b)
{
	return a.w < b.w;
}

int find(int a)
{
	if(uf[a] < 0)
	{
		return a;
	}
	return uf[a] = find(uf[a]);
}

void merge(int a, int b, int w)
{
	int x = find(a);
	int y = find(b);
	if(x == y)
	{
		return;
	}
	uf[y] = x;
	adj[a].push_back({b,w});
	adj[b].push_back({a,w});
	MST += w;
}

void dfs(int cur, int d)
{
	depth[cur] = d;
	visited[cur] = true;
	for(auto &e : adj[cur])
	{
		if(visited[e.first])
		{
			continue;
		}
		parent[e.first][0] = cur;
		maxW[e.first][0] = e.second;
		dfs(e.first,d+1);
	}
}

int LCA(int u, int v)
{
	int ret = 0;
	//depth[u] >= depth[v] 가 된다
	if(depth[u] < depth[v])
	{
		swap(u,v);
	}
	
	int diff = depth[u] - depth[v];

	//u와 v의 깊이 차이를 없애준다(diff = 0) : u의 조상으로 올라가면서
	for(int j = 0;diff!=0;++j)
	{
		if(diff % 2 == 1)
		{
			ret = max(ret,maxW[u][j]);
			u = parent[u][j];
		}
		diff /= 2;
	}

	if(u != v)
	{
		for(int i = BMAX-1;i>=0;--i)
		{
			if(parent[u][i] != -1 && parent[u][i] != parent[v][i])
			{
				ret = max(ret,maxW[u][i]);
				ret = max(ret,maxW[v][i]);
				u = parent[u][i];
				v = parent[v][i];
			}
		}
		//이 시점에서 u와 v의 부모는 같다, 그러므로 그들의 공통 조상은 그들의 부모다
		ret = max(ret,maxW[u][0]);
		ret = max(ret,maxW[v][0]);
		u = parent[u][0];
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill(uf,uf+MAX,-1);
	memset(parent,-1,sizeof(parent));

	cin>>N>>M;

	for(int i = 1;i<=M;++i)
	{
		int uval,vval,wval;
		cin>>uval>>vval>>wval;
		sorted.push_back({uval,vval,wval});
	}
	
	edge = sorted;

	sort(sorted.begin(), sorted.end(), cmp);

	for(int i = 0;i<M;++i)
	{
		merge(sorted[i].u, sorted[i].v, sorted[i].w);
		if(cnt == N-1)
		{
			break;
		}
	}
	//1 is root node
	dfs(1,1);

	for(int k = 1;k<BMAX;++k)
	{
		for(int i = 1;i<=N;++i)
		{
			if(parent[i][k-1] != -1)
			{
				parent[i][k] = parent[parent[i][k-1]][k-1];
				maxW[i][k] = max(maxW[i][k-1], maxW[parent[i][k-1]][k-1]);
			}
		}
	}

	for(int i = 0;i<M;++i)
	{
		cout<<MST - LCA(edge[i].u, edge[i].v) + edge[i].w<<"\n";
	}

	return 0;
}