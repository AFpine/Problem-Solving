#include <bits/stdc++.h>
 
// 18430 무기 공학

// update 220803

using namespace std;
#define sz(a) (int)(a.size()) 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef pair<long double, long double> pdd;
 
const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const long long MOD = 998244353;
const int MAX = 10005;

int N, M;
int board[10][10];
int result;
bool visited[10][10];

pii d[] = {{0, 1}, {1, 2}, {2, 3}, {3, 0}};
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void input() {
	cin>>N>>M;
	for(int i = 1; i <= N; ++i) {
		for(int j = 1; j <= M; ++j) {
			cin>>board[i][j];
		}
	}
}

void f(int i, int j, int cur) {
	if(j == M+1) {
		j = 1;
		i += 1;
	}
	if(i == N + 1) {
		result = max(result, cur);
		return;
	}
	if(!visited[i][j]) {
		for(int dir = 0; dir < 4; ++dir) {
			int x1 = i + dx[d[dir].first];
			int y1 = j + dy[d[dir].first];
			int x2 = i + dx[d[dir].second];
			int y2 = j + dy[d[dir].second];
			if(x1 < 1 || x1 > N || x2 < 1 || x2 > N || y1 < 1 || y1 > M || y2 < 1 || y2 > M) continue;
			if(visited[x1][y1] || visited[x2][y2]) continue;
			visited[i][j] = visited[x1][y1] = visited[x2][y2] = true;
			f(i, j+1, cur + board[i][j]*2 + board[x1][y1] + board[x2][y2]);
			visited[i][j] = visited[x1][y1] = visited[x2][y2] = false;
		}
	}
	f(i, j+1, cur);
}

void solve() {
	f(1, 1, 0);
	cout<<result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}