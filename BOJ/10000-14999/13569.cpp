#include <bits/stdc++.h>

// 13569 Rounding

// update 220816

using namespace std;
#define sz(a) (int)(a.size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<long long, long long> pll;
typedef pair<double, double> pdd;
typedef pair<int,int> pii;

const int INF = 1e9+5;
const long long llINF = 1e18;
const long long minllINF = -1e18;
const int minINF = -2e9-1;
const long long MOD = 1000000007;
const int MAXN = 205;
// more than MAXN*MAXN*2
const int MAXV = 100005;
const int d = 205;

struct Edge {
	int next, capacity, dm, flow {0}, f0 {0};
	Edge *arc {nullptr};
};

int M, N, D;
int S = MAXV-1, S0 = MAXV-2, E = MAXV-3, E0 = MAXV-4;
int level[MAXV], work[MAXV];
double arr[MAXN][MAXN], rsum[MAXN], csum[MAXN];
vector<Edge*> edge, adj[MAXV];
Edge* ijedge[MAXN][MAXN];

int vertexN(int i, int j) {
	return 2*(MAXN*i + j);
}

Edge* addEdge(int u, int v, int cap, int lb) {
	Edge *e1 = new Edge({v, cap, lb});
	Edge *e2 = new Edge({u, 0, 0});
	e1->arc = e2;
	e2->arc = e1;
	adj[u].push_back(e1);
	adj[v].push_back(e2);
	edge.push_back(e1);
	edge.push_back(e2);

	return e1;
}

void bfs() {
	fill(level, level+MAXV, -1);
	level[S] = 0;
	
	queue<int> Q;
	Q.push(S);
	while(!Q.empty()) {
		auto cur = Q.front();
		Q.pop();

		for(auto &e : adj[cur]) {
			if(level[e->next] == -1 && e->capacity - e->flow > 0) {
				level[e->next] = level[cur] + 1;
				Q.push(e->next);
			}
		}
	}
}

int dfs(int cur, int dest, int fl) {
	if(cur == dest) return fl;

	for(int &i = work[cur]; i < sz(adj[cur]); ++i) {
		auto e = adj[cur][i];
		if(level[e->next] == level[cur] + 1 && e->capacity - e->flow > 0) {
			int df = dfs(e->next, dest, min(e->capacity - e->flow, fl));
			if(df > 0) {
				e->flow += df;
				e->arc->flow -= df;
				return df;
			}
		}
	}

	return 0;
}

int dinic() {
	int ret = 0;
	while(true) {
		bfs();
		if(level[E] == -1) break;

		fill(work, work+MAXV, 0);
		
		while(true) {
			int flow = dfs(S, E, INF);
			if(flow == 0) break;
			ret += flow;
		}
	}

	return ret;
}

void input() {
	cin>>M>>N;
	for(int i = 1; i <= M; ++i) {
		for(int j = 1; j <= N; ++j) {
			cin>>arr[i][j];
		}
		cin>>rsum[i];
	}
	for(int i = 1; i <= N; ++i) cin>>csum[i];

	for(int i = 1; i <= M; ++i) {
		ijedge[i][N+1] = addEdge(S0, vertexN(i, N+1), ceil(rsum[i]), floor(rsum[i]));
		for(int j = 1; j <= N; ++j) {
			addEdge(vertexN(i, N+1), vertexN(i, j), INF, 0);
		}
	}

	for(int i = 1; i <= N; ++i) {
		ijedge[M+1][i] = addEdge(vertexN(M+1, i), E0, ceil(csum[i]), floor(csum[i]));
		for(int j = 1; j <= M; ++j) {
			addEdge(vertexN(j, i)+1, vertexN(M+1, i), INF, 0);
		}
	}

	for(int i = 1; i <= M; ++i) {
		for(int j = 1; j <= N; ++j) {
			ijedge[i][j] = addEdge(vertexN(i, j), vertexN(i, j)+1, ceil(arr[i][j]), floor(arr[i][j]));
		}
	}
	addEdge(E0, S0, INF, 0);
}

void solve() {
	int demand[MAXV] = {0};
	for(auto &e : edge) {
		auto &lb = e->dm;
		if(lb > 0) {
			demand[e->next] -= lb;
			demand[e->arc->next] += lb;
			e->capacity -= lb;
			e->f0 += lb;
			lb = 0;
		}
	}

	for(int i = 0; i < MAXV; ++i) {
		if(i == S || i == E) continue;
		if(demand[i] < 0) {
			addEdge(S, i, -demand[i], 0);
		}
		else if(demand[i] > 0) {
			addEdge(i, E, demand[i], 0);
		}
	}

	dinic();

	for(int i = 1; i <= M; ++i) {
		for(int j = 1; j <= N; ++j) {
			cout<<ijedge[i][j]->flow + ijedge[i][j]->f0<<' ';
		}
		cout<<ijedge[i][N+1]->flow + ijedge[i][N+1]->f0<<'\n';
	}
	for(int i = 1; i <= N; ++i) {
		cout<<ijedge[M+1][i]->flow + ijedge[M+1][i]->f0<<' ';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}