#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

// 2452

// 221101

using namespace std;
#define sz(a) (int)(a.size()) 
#define all(a) (a).begin(), (a).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef pair<long double, long double> pdd;
typedef complex<double> cplx;

const double PI = acos(-1);
const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const long long MOD = 1e9+7;
const int MAX = 111;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int M, N, grid[MAX][MAX], uf[2*MAX*MAX], cnt, comp[MAX][MAX];
vector<int> adj[2*MAX*MAX];
map<int, int> maping;
int dist[2*MAX*MAX];

int num(pii a) { return a.first*MAX + a.second; }

int find(int a) {
	if(uf[a] < 0) return a;
	return uf[a] = find(uf[a]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if(a == b) return;
	uf[a] += uf[b];
	uf[b] = a;
}

int bfs(int st) {
	fill(dist, dist+2*MAX*MAX, INF);
	deque<int> dq;
	int ret = 0;
	dist[st] = 0;
	dq.push_back(st);

	while(!dq.empty()) {
		auto cur = dq.front();
		dq.pop_front();

		for(auto &e : adj[cur]) {
			if(dist[e] != INF) continue;
			dist[e] = dist[cur] + 1;
			ret = max(ret, dist[e]);
			dq.push_back(e);
		}
	}
	return ret;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill(uf, uf+2*MAX*MAX, -1);

	cin>>M>>N;
	for(int i = 1; i <= M; ++i) {
		for(int j = 1; j <= N; ++j) cin>>grid[i][j];
	}
	
	for(int i = 1; i <= M; ++i) {
		for(int j = 1; j <= N; ++j) {
			if(i+1 <= M && grid[i][j] == grid[i+1][j]) merge(num({i, j}), num({i+1, j}));
			if(j+1 <= N && grid[i][j] == grid[i][j+1]) merge(num({i, j}), num({i, j+1}));
		}
	}

	for(int i = 1; i <= M; ++i) {
		for(int j = 1; j <= N; ++j) {
			int curuf = find(num({i, j}));
			if(maping[curuf] == 0) { 
				maping[curuf] = ++cnt;
			}
			int curcomp = maping[curuf];
			comp[i][j] = curcomp;
		}
	}

	for(int i = 1; i <= M; ++i) {
		for(int j = 1; j <= N; ++j) {
			for(int dir = 0; dir < 4; ++dir) {
				int x = i + dx[dir];
				int y = j + dy[dir];
				if(x < 1 || x > M || y < 1 || y > N || grid[i][j] == grid[x][y]) continue;
				adj[comp[i][j]].push_back(comp[x][y]);
			}
		}
	}

	int ans = INF;
	for(int i = 1; i <= cnt; ++i) {
		ans = min(ans, bfs(i));
	}

	cout<<ans;

	return 0;
}