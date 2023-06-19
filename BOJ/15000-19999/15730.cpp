#include <bits/stdc++.h>

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
const long long MOD = 1e9+9;
const int MAX = 105;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int N, M, board[MAX][MAX];
bool filled[MAX][MAX], visited[MAX][MAX];
char tboard[MAX][MAX];
int result;

void bfs(int c) {
	memset(visited, false, sizeof(visited));
	queue<pii> Q;	

	for(int i = 1; i <= N; ++i) {
		if(board[i][1] < c) {
			visited[i][1] = true;
			Q.push({i, 1});
		}
		if(board[i][M] < c) {
			visited[i][M] = true;
			Q.push({i, M});
		}
	}
	for(int i = 1; i <= M; ++i) {
		if(board[1][i] < c) {
			visited[1][i] = true;
			Q.push({1, i});
		}
		if(board[N][i] < c) {
			visited[N][i] = true;
			Q.push({N, i});
		}
	}

	while(!Q.empty()) {
		auto cur = Q.front();
		Q.pop();

		for(int dir = 0; dir < 4; ++dir) {
			int x = cur.first + dx[dir];
			int y = cur.second + dy[dir];

			if(x < 1 || x > N || y < 1 || y > M) continue;
			if(board[x][y] >= c || visited[x][y]) continue;

			visited[x][y] = true;
			Q.push({x, y});
		}	
	}

	for(int i = 1; i <= N; ++i) {
		for(int j = 1; j <= M; ++j) {
			if(!visited[i][j] && !filled[i][j] && board[i][j] < c) {
				result += (c - board[i][j]);
				filled[i][j] = true;
			}
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

	cin>>N>>M;
	for(int i = 1; i <= N; ++i) {
		for(int j = 1; j <= M; ++j) {
			cin>>board[i][j];
		}
	}
	
	for(int i = 10000; i >= 0; --i) {
		bfs(i);
	}

	cout<<result;

	return 0;
}