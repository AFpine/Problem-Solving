#include <bits/stdc++.h>
 
// 5465 곰돌이

// update 220809

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
const long long MOD = 9999991;
const int MAX = 805;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int N, S;
pii start, dest;
vector<pii> bee;
char board[MAX][MAX];
int bearD[MAX][MAX], realD[MAX][MAX], beeD[MAX][MAX];

void input() {
	cin>>N>>S;
	for(int i = 1; i <= N; ++i) {
		for(int j = 1; j <= N; ++j) {
			cin>>board[i][j];
			if(board[i][j] == 'H') bee.push_back({i, j});
			if(board[i][j] == 'M') start = {i, j};
			if(board[i][j] == 'D') dest = {i, j};
		}
	}
	memset(beeD, -1, sizeof(beeD));
}

void solve() {
	queue<pii> beeQ;
	for(auto &p : bee) {
		beeD[p.first][p.second] = 0;
		beeQ.push(p);
	}
	beeD[dest.first][dest.second] = INF;

	while(!beeQ.empty()) {
		auto cur = beeQ.front();
		beeQ.pop();
		auto curD = beeD[cur.first][cur.second];

		for(int dir = 0; dir < 4; ++dir) {
			int x = cur.first + dx[dir];
			int y = cur.second + dy[dir];
			
			if(x < 1 || x > N || y < 1 || y > N) continue;
			if(board[x][y] == 'T' || board[x][y] == 'D') continue;
			if(beeD[x][y] != -1) continue;

			beeD[x][y] = curD + 1;
			beeQ.push({x, y});
		}
	}

	int result = -1;
	int l = 0, r = N*N;
	while(l <= r) {
		queue<pii> Q;
		memset(bearD, -1, sizeof(bearD));

		int mid = (l+r)/2;
		bearD[start.first][start.second] = 0;

		if(mid >= beeD[start.first][start.second]) {
			r = mid - 1;
			continue;
		}

		Q.push(start);

		while(!Q.empty()) {
			auto cur = Q.front();
			Q.pop();
			auto curD = bearD[cur.first][cur.second];

			for(int dir = 0; dir < 4; ++dir) {
				int x = cur.first + dx[dir];
				int y = cur.second + dy[dir];
				
				if(x < 1 || x > N || y < 1 || y > N) continue;
				if(board[x][y] == 'T') continue;
				if(bearD[x][y] != -1) continue;

				int nextD = mid + (curD+1) / S;

				if(beeD[x][y] <= nextD) continue;
				bearD[x][y] = curD + 1;
				Q.push({x, y});
			}
		}
		if(bearD[dest.first][dest.second] != -1) {
			result = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}

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