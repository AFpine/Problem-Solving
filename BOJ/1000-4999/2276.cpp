#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

// 2276

// 221031

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
const int MAX = 305;

struct wv {
	ll w; pii pos;
	bool operator<(const wv& rhs) const {
		return w > rhs.w;
	}
};

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int N, M;
ll ans = 0;
bool visited[MAX][MAX];
wv grid[MAX][MAX];
priority_queue<wv> pq;

void dfs(wv cur) {
	auto v = cur.pos;
	for(int dir = 0; dir < 4; ++dir) {
		int x = v.first + dx[dir];
		int y = v.second + dy[dir];
		if(x < 1 || x > N || y < 1 || y > M || visited[x][y]) continue;
		visited[x][y] = true;

		if(grid[x][y].w > cur.w) pq.push({grid[x][y]});
		else {
			ans += cur.w - grid[x][y].w;
			pq.push({cur.w, {x, y}});
		}
	}
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>M>>N;
	for(int i = 1; i <= N; ++i) {
		for(int j = 1; j <= M; ++j) {
			cin>>grid[i][j].w;
			grid[i][j].pos = {i, j};

			if(i == 1 || i == N || j == 1 || j == M) { 
				pq.push(grid[i][j]); visited[i][j] = true; 
			}
		}
	}
	
	while(!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		dfs(cur);
	}

	cout<<ans;
	return 0;
}
