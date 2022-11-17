#include <bits/stdc++.h>

// 1175

// 221117

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
const int MAX = 55;

struct S {
	pii pos;
	int predir, c1, c2;
};

pii st, dest1, dest2;
int N, M;
ll dist[MAX][MAX][5][2][2];
char grid[MAX][MAX];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for(int i = 0; i < MAX; ++i) {
		for(int j = 0; j < MAX; ++j) {
			for(int d = 0; d < 4; ++d) {
				dist[i][j][d][0][0] = dist[i][j][d][0][1] = dist[i][j][d][1][0] = dist[i][j][d][1][1] = -1;
			}
		}
	}

	cin>>N>>M;
	for(int i = 1; i <= N; ++i) {
		for(int j = 1; j <= M; ++j) {
			cin>>grid[i][j];
			if(grid[i][j] == 'S') st = {i, j};
			if(grid[i][j] == 'C') {
				if(dest1 == pii(0, 0)) dest1 = {i, j};
				else dest2 = {i, j};
			}
		}
	}

	queue<S> Q;
	Q.push({st, 4, 0, 0});
	dist[st.first][st.second][4][0][0] = 0;
	
	ll ans = INF;
	while(!Q.empty()) {
		auto cur = Q.front();
		Q.pop();

		for(int dir = 0; dir < 4; ++dir) {
			if(dir == cur.predir) continue;
			int x = cur.pos.first + dx[dir];
			int y = cur.pos.second + dy[dir];
			if(x < 1 || x > N || y < 1 || y > M) continue;
			if(grid[x][y] == '#') continue;
			int c1 = cur.c1, c2 = cur.c2;
			if(pii(x, y) == dest1) c1 |= 1;
			if(pii(x, y) == dest2) c2 |= 1;

			if(dist[x][y][dir][c1][c2] >= 0) continue;
			dist[x][y][dir][c1][c2] = dist[cur.pos.first][cur.pos.second][cur.predir][cur.c1][cur.c2] + 1;
			Q.push({{x, y}, dir, c1, c2});
		}
	}
	
	for(int i = 1; i <= N; ++i) {
		for(int j = 1; j <= M; ++j) {
			for(int dir = 0; dir < 4; ++dir) {
				if(dist[i][j][dir][1][1] > 0) ans = min(ans, dist[i][j][dir][1][1]);
			}
		}
	}

	if(ans == INF) cout<<"-1";
	else cout<<ans;

	return 0;
}