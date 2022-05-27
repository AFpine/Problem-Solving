#include <bits/stdc++.h>

// 10319 좀비 아포칼립스

// update 220527

using namespace std;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 150005;
const int P = 1000;

struct Edge
{
	int next;
	int capacity;
	int flow;
	Edge* arcEdge {nullptr};
};

int T;
int N,I,g,s,M;
int r,a,b,p,t;
int S = 0;
int E = 150000;
bool hospital[1005];
vector<Edge*> adj[MAX];

void init()
{
	memset(hospital,false,sizeof(hospital));
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

	cin>>T;
	while(T--)
	{
		init();
		cin>>N;
		cin>>I>>g>>s;
		for(int i = 1;i<=N;++i)
		{
			for(int j = 0;j<s;++j)
			{
				Edge* e1 = new Edge({i+((j+1)*P),INF,0});
				Edge* e2 = new Edge({i+(j*P),0,0});
				e1->arcEdge = e2;
				e2->arcEdge = e1;
				adj[i+(j*P)].push_back(e1);
				adj[i+((j+1)*P)].push_back(e2);
			}
		}
		cin>>M;
		for(int i = 1;i<=M;++i)
		{
			int x;
			cin>>x;
			hospital[x] = true;
		}
		cin>>r;
		for(int i = 1;i<=r;++i)
		{
			cin>>a>>b>>p>>t;
			for(int k = 0;k+t<=s;++k)
			{
				Edge* e1 = new Edge({b+((k+t)*P),p,0});
				Edge* e2 = new Edge({a+(k*P),0,0});
				e1->arcEdge = e2;
				e2->arcEdge = e1;
				adj[a+(k*P)].push_back(e1);
				adj[b+((k+t)*P)].push_back(e2);
			}
		}

		for(int i = 1;i<=1000;++i)
		{
			if(hospital[i])
			{
				for(int k = 0;k<=s;++k)
				{
					Edge* e1 = new Edge({E,INF,0});
					Edge* e2 = new Edge({i+(k*P),0,0});
					e1->arcEdge = e2;
					e2->arcEdge = e1;
					adj[i+(k*P)].push_back(e1);
					adj[E].push_back(e2);
				}
			}
		}

		Edge* e1 = new Edge({I,g,0});
		Edge* e2 = new Edge({S,0,0});
		e1->arcEdge = e2;
		e2->arcEdge = e1;
		adj[S].push_back(e1);
		adj[I].push_back(e2);

		int totalFlow = 0;
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
					if(e->capacity - e->flow > 0 && prev[e->next] == -1)
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
				flow = min(flow, path[i]->capacity - path[i]->flow);
			}
			for(int i = E; i != S; i = prev[i])
			{
				path[i]->flow += flow;
				path[i]->arcEdge->flow -= flow;
			}

			totalFlow += flow;
		}

		cout<<totalFlow<<'\n';

	}
    
	return 0;
}

