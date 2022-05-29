#include <bits/stdc++.h>

// 11493 동전 교환

// update 220529

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 505;

struct Edge
{
	int next, capacity, flow, cost;
	Edge* arcEdge {nullptr};
};

int T;
int N,M;
vector<int> vertexV;
vector<int> coinV;
//기준은 검은색 정점과 검은색 동전
bool vertexColor[MAX];
bool coinColor[MAX];
//1 is black, 0 is white
vector<Edge*> adj[MAX];
int cnt;
int totalCnt;

void init()
{
	cnt = 0;
	totalCnt = 0;
	vertexV.clear();
	coinV.clear();
	for(int i = 0;i<MAX;++i)
	{
		vertexColor[i] = false;
		coinColor[i] = false;
		adj[i].clear();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>T;
	while(T--)
	{
		init();
		cin>>N>>M;

		for(int i = 1;i<=M;++i)
		{
			int u,v;
			cin>>u>>v;

			Edge* e1 = new Edge({v,INF,0,1});
			Edge* e2 = new Edge({u,INF,0,1});
			e1->arcEdge = e2;
			e2->arcEdge = e1;
			adj[u].push_back(e1);
			adj[v].push_back(e2);
		}

		for(int i = 1;i<=N;++i)
		{
			cin>>vertexColor[i];
			if(vertexColor[i] == 0)
			{
				vertexV.push_back(i);
			}
		}
		for(int i = 1;i<=N;++i)
		{
			cin>>coinColor[i];
			if(coinColor[i] == 0)
			{
				coinV.push_back(i);
				cnt++;
			}
		}
		//vertexV에는 흰색 동전이 있는 검은색 정점, coinV에는 검은 동전이 있는 흰색 정점
		//둘 사이에 유량이 1 흐를 때, 비용의 합이 연산 횟수


		int S = 0;
		int E = 504;
		for(auto &i : coinV)
		{
			Edge* e1 = new Edge({i,1,0,0});
			Edge* e2 = new Edge({S,0,0,0});
			e1->arcEdge = e2;
			e2->arcEdge = e1;
			adj[S].push_back(e1);
			adj[i].push_back(e2);
		}
		for(auto &i : vertexV)
		{
			Edge* e1 = new Edge({E,1,0,0});
			Edge* e2 = new Edge({i,0,0,0});
			e1->arcEdge = e2;
			e2->arcEdge = e1;
			adj[i].push_back(e1);
			adj[E].push_back(e2);
		}

		for(int i = 1;i<=cnt;++i)
		{
			int prev[MAX], dist[MAX];
			bool inQ[MAX];
			Edge* path[MAX];
			queue<int> Q;

			fill(prev,prev+MAX,-1);
			fill(dist,dist+MAX,INF);
			fill(inQ,inQ+MAX,false);

			dist[S] = 0;
			inQ[S] = true;
			Q.push(S);

			while(!Q.empty())
			{
				int cur = Q.front();
				Q.pop();
				inQ[cur] = false;
				for(auto &e : adj[cur])
				{
					int temp = (e->flow < 0 ? -1 : 1) * e->cost;
					//위의 부분 내 코드 아님. 왜 이렇게 해야하는지?
					if(e->capacity-e->flow > 0 && dist[e->next] > dist[cur] + temp)
					{
						dist[e->next] = dist[cur] + temp;
						prev[e->next] = cur;
						path[e->next] = e;
						if(inQ[e->next] == false)
						{
							inQ[e->next] = true;
							Q.push(e->next);
						}
					}
				}
			}

			for(int i = E; i != S; i = prev[i])
			{
				totalCnt += (path[i]->flow < 0 ? -1 : 1)*path[i]->cost;
				//여기도 내 코드 아님 
				path[i]->flow += 1;
				path[i]->arcEdge->flow -= 1;
			}
		}

		cout<<totalCnt<<'\n';

	}

	return 0;
}

