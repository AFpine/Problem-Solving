#include <bits/stdc++.h>

// 15504 프로그래밍 대결

// update 220621

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 610;
const int d = 302;

struct Edge
{
	int next, capacity, flow; 
	int cost;
	Edge* arcEdge {nullptr};
};

int N;
int S = 0, E = 608;
int A[MAX], H[MAX], L[MAX];
vector<Edge*> adj[MAX];

void addEdge(int u, int v, int capval, int costval)
{
	Edge* e1 = new Edge({v,capval,0,costval});
	Edge* e2 = new Edge({u,0,0,-costval});
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

	cin>>N;

	int maxidx = 0, maxval = -1;
	for(int i = 1;i<=N;++i)
	{//실력
		cin>>A[i];
		if(A[i] > maxval)
		{
			maxval = A[i];
			maxidx = i;
		}
	}
	for(int i = 1;i<=N;++i)
	{//피로도
		cin>>H[i];
	}
	for(int i = 1;i<=N;++i)
	{//승리 가능 횟수
		cin>>L[i];
	}
	
	for(int i = 1;i<=N;++i)
	{//source -> 승리하는 사람 / 피로도는 비용에서 음수로 작용하기 때문에, 역으로 양수를 넣는다
	//패배하는 사람 -> sink / 비용의 이유는 위와 동일
		if(i == maxidx)
		{//제일 강한 사람은 최대 L[i]번 승리할 수 있다
			addEdge(S,i,L[i],H[i]);
			addEdge(i+d,E,0,H[i]);
			//제일 강한 사람은 지지 않는다
		}
		else
		{//나머지는 최대 L[i]번 승리할 수 있다 (한 번은 져야하기 때문에)
			addEdge(S,i,L[i]-1,H[i]);
			addEdge(i+d,E,1,H[i]);
			//나머지는 무조건 1번 진다
		}
	}

	for(int i = 1;i<=N;++i)
	{
		for(int j = 1;j<=N;++j)
		{
			if(i == j)
			{
				continue;
			}
			if(A[i] > A[j])
			{
				addEdge(i,j+d,1,-(A[i]^A[j]));
			}
		}
	}

	long long total = 0;
	while(true)
	{
		int prev[MAX], dist[MAX];
		bool inq[MAX];
		Edge* path[MAX];
		queue<int> Q;

		fill(prev,prev+MAX,-1);
		fill(dist,dist+MAX,INF);
		fill(inq,inq+MAX,false);

		dist[S] = 0;
		inq[S] = 0;
		Q.push(S);

		while(!Q.empty())
		{
			int cur = Q.front();
			Q.pop();
			inq[cur] = false;

			for(auto &e : adj[cur])
			{
				if(e->capacity-e->flow > 0 && dist[e->next] > dist[cur] + e->cost)
				{
					dist[e->next] = dist[cur] + e->cost;
					prev[e->next] = cur;
					path[e->next] = e;
					if(!inq[e->next])
					{
						inq[e->next] = true;
						Q.push(e->next);	
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
			total += path[i]->cost * flow;
			path[i]->flow += flow;
			path[i]->arcEdge->flow -= flow;
		}
	}

	cout<<-total;


	return 0;
}