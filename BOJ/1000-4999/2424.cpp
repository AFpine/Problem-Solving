#include <bits/stdc++.h>

// 2424 부산의 해적

// update 220811

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
const int MAX = 705;

int N, M;
pii S, P, T;
char board[MAX][MAX];
int rc[MAX][MAX], dist[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void input() {
	cin>>N>>M;
	for(int i = 1; i <= N; ++i) {
		for(int j = 1; j <= M; ++j) {
			cin>>board[i][j];
			if(board[i][j] == 'Y') S = {i, j};
			if(board[i][j] == 'V') P = {i, j};
			if(board[i][j] == 'T') T = {i, j};
		}
	}
	
	for(int i = 1; i <= N; ++i) {
		for(int j = 1; j <= M; ++j) {
			rc[i][j] = 1000000;
		}
	}
	
}

void laser(int r, int c, int k) {
	int x = r, y = c;
	while(true) {
		if(x < 1) break;
		if(board[x][y] == 'I') break;
		rc[x][y] = min(rc[x][y] , k);
		x--;
	}
	x = r;
	while(true) {
		if(x > N) break;
		if(board[x][y] == 'I') break;
		rc[x][y] = min(rc[x][y] , k);
		x++;
	}
	x = r;
	while(true) {
		if(y < 1) break;
		if(board[x][y] == 'I') break;
		rc[x][y] = min(rc[x][y] , k);
		y--;
	}
	y = c;
	while(true) {
		if(y > M) break;
		if(board[x][y] == 'I') break;
		rc[x][y] = min(rc[x][y] , k);
		y++;
	}
}

void solve() {
	queue<pii> Q;
	visited[P.first][P.second] = true;
	dist[P.first][P.second] = 0;
	
	Q.push(P);

	while(!Q.empty()) {
		auto cur = Q.front();
		Q.pop();
		auto curdist = dist[cur.first][cur.second];

		laser(cur.first, cur.second, curdist);

		for(int dir = 0; dir < 4; ++dir) {
			int x = cur.first + dx[dir];
			int y = cur.second + dy[dir];

			if(x < 1 || x > N || y < 1 || y > M) continue;
			if(board[x][y] == 'I') continue;
			if(visited[x][y]) continue;

			visited[x][y] = true;
			dist[x][y] = curdist + 1;
			Q.push({x, y});
		}
	}

	for(int i = 1; i <= N; ++i) {
		for(int j = 1; j <= M; ++j) {
			dist[i][j] = 1000000;
			visited[i][j] = false;
		}
	}

	visited[S.first][S.second] = true;
	dist[S.first][S.second] = 0;
	Q.push(S);

	while(!Q.empty()) {
		auto cur = Q.front();
		Q.pop();
		auto curdist = dist[cur.first][cur.second];

		for(int dir = 0; dir < 4; ++dir) {
			int x = cur.first + dx[dir];
			int y = cur.second + dy[dir];

			if(x < 1 || x > N || y < 1 || y > M) continue;
			if(board[x][y] == 'I') continue;
			if(visited[x][y]) continue;
			if(rc[x][y] <= curdist + 1) continue;

			visited[x][y] = true;
			dist[x][y] = curdist + 1;
			Q.push({x, y});
		}
	}

	if(visited[T.first][T.second]) cout<<"YES";
	else cout<<"NO";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}