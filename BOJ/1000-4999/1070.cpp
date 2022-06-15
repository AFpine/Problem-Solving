#include <bits/stdc++.h>

// 1070 김지민의 침략

// update 220614

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 6010;
const int COSTMAX = 1e7;
const int MOD = 1e9+7;
const int d = 3000;

struct Edge
{
	int next, capacity, flow;
	Edge* arcEdge {nullptr};
};

int N,M,S,E;
int cntV;
int cost[26];
char castle[51][51];
vector<Edge*> adj[MAX];
map<pair<int,int>, int> maping;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void addEdge(int u, int v, int cap)
{
	Edge* e1 = new Edge({v,cap,0});
	Edge* e2 = new Edge({u,0,0});
	e1->arcEdge = e2;
	e2->arcEdge = e1;
	adj[u].push_back(e1);
	adj[v].push_back(e2);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>M;
	for(int i = 1;i<=N;++i)
	{
		string s;
		cin>>s;
		for(int j = 1;j<=M;++j)
		{
			castle[i][j] = s[j-1];
			if(castle[i][j] != '-')
			{
				maping[pair<int,int>(i,j)] = ++cntV;
			}
			if(castle[i][j] == '*')
			{
				S = cntV + d;
			}
		}
	}
	for(int i = 0;i<26;++i)
	{
		cin>>cost[i];
	}

	E = 6009;
	for(int i = 1;i<=N;++i)
	{
		for(int j = 1;j<=M;++j)
		{
			if(castle[i][j] == '-')
			{
				continue;
			}
			if(castle[i][j] != '*')
			{//시작점이 아니라면, 정점분할 (정점에서의 capacity는 주어진 cost)
				addEdge(maping[{i,j}], maping[{i,j}]+d, cost[castle[i][j]-'A'] + COSTMAX);
				//분할된 정점들 사이의 capacity(cost)에다가 COSTMAX(1e7)를 더하는 이유는
				//최소한의 간선 갯수를 이용한 최소 컷을 구하려 하는데, 많은 수의 장애물들이 더 낮은 cost를 사용해서 
				//설치될 수 있기 때문에 설치되는 장애물의 갯수를 최우선으로 생각하게 하기 위해서 장애물의 최대 크기인 1e7을 더했다 (그리하면 장애물을 최소한으로 설치하는 것이 비용의 최소값이 된다)
			}
			for(int dir = 0;dir<4;++dir)
			{
				int x = i+dx[dir];
				int y = j+dy[dir];
				if(x < 1 || x > N || y < 1 || y > M)
				{
					addEdge(maping[{i,j}]+d,E,INF);
				}
				else if(castle[x][y] != '-')
				{
					addEdge(maping[{i,j}]+d, maping[{x,y}],INF);
				}
			}
		}
	}

	long long mincut = 0;
	while(true)
	{
		int prev[MAX];
		Edge* path[MAX];
		queue<int> Q;

		fill(prev,prev+MAX,-1);
		
		Q.push(S);
		while(!Q.empty() && prev[E] == -1)
		{
			int cur = Q.front();
			Q.pop();

			for(auto &e : adj[cur])
			{
				if(e->capacity-e->flow > 0 && prev[e->next] == -1)
				{
					prev[e->next] = cur;
					path[e->next] = e;
					Q.push(e->next);
					if(e->next == E)
					{
						break;
					}
				}
			}
		}

		if(prev[E] == -1)
		{
			break;
		}

		int flow = INF;
		for(int i = E; i != S; i = prev[i])
		{
			flow = min(flow, path[i]->capacity-path[i]->flow);
		}
		for(int i = E; i != S; i = prev[i])
		{
			path[i]->flow += flow;
			path[i]->arcEdge->flow -= flow;
		}
		mincut += flow;
	}

	cout<<mincut%COSTMAX;

	return 0;
}