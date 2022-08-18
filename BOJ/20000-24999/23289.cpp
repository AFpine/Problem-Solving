#include <bits/stdc++.h>
 
// 23289 온풍기 안녕!

// update 220818

using namespace std;
#define sz(a) (int)(a.size()) 
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
const long long MOD = 1000000007;
const int MAX = 22;

int R, C, K, W;
int board[MAX][MAX], temp[MAX][MAX], visited[MAX][MAX];
vector<pii> test;
bool wall[MAX][MAX][MAX][MAX];
vector<pair<pii, int>> rob;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void input() {
	cin>>R>>C>>K;
	for(int i = 1; i <= R; ++i) {
		for(int j = 1; j <= C; ++j) {
			cin>>board[i][j];
			if(board[i][j] == 5) test.push_back({i, j});
			else if(board[i][j] != 0) rob.push_back({{i, j}, board[i][j]});
		}
	}
	cin>>W;
	for(int i = 1; i <= W; ++i) {
		int x, y, t;
		cin>>x>>y>>t;
		if(t == 0) {
			wall[x][y][x-1][y] = true;
			wall[x-1][y][x][y] = true;
		}
		else {
			wall[x][y][x][y+1] = true;
			wall[x][y+1][x][y] = true;
		}
	}
}

void wind() {
	for(int i = 1; i <= R; ++i) {
		for(int j = 1; j <= C; ++j) visited[i][j] = -1;
	}
	int idx = 0;
	for(auto &r : rob) {
		idx++;
		queue<pii> Q;
		queue<int> tQ;
		int tdx[5], tdy[5];
		if(r.second == 1) {
			tdx[0] = -1;
			tdx[1] = -1;
			tdx[2] = 0;
			tdx[3] = 1;
			tdx[4] = 1;

			tdy[0] = 0;
			tdy[1] = 1;
			tdy[2] = 1;
			tdy[3] = 0;
			tdy[4] = 1;
		}
		else if(r.second == 2) {
			tdx[0] = -1;
			tdx[1] = -1;
			tdx[2] = 0;
			tdx[3] = 1;
			tdx[4] = 1;

			tdy[0] = 0;
			tdy[1] = -1;
			tdy[2] = -1;
			tdy[3] = 0;
			tdy[4] = -1;
		}
		else if(r.second == 3) {
			tdx[0] = 0;
			tdx[1] = -1;
			tdx[2] = -1;
			tdx[3] = 0;
			tdx[4] = -1;

			tdy[0] = -1;
			tdy[1] = -1;
			tdy[2] = 0;
			tdy[3] = 1;
			tdy[4] = 1;
		}
		else {
			tdx[0] = 0;
			tdx[1] = 1;
			tdx[2] = 1;
			tdx[3] = 0;
			tdx[4] = 1;

			tdy[0] = -1;
			tdy[1] = -1;
			tdy[2] = 0;
			tdy[3] = 1;
			tdy[4] = 1;
		}
		Q.push(r.first);
		tQ.push(5);

		while(!Q.empty()) {
			auto cur = Q.front();
			Q.pop();
			auto curT = tQ.front();
			tQ.pop();
			if(curT <= 0) continue;

			for(int dir = 0; dir < 5; ++dir) {
				if(dir == 0 || dir == 3) continue;
				if(curT == 5 && dir != 2) continue;

				int x = cur.first + tdx[dir];
				int y = cur.second + tdy[dir];
				if(x < 1 || x > R || y < 1 || y > C) continue;
				if(visited[x][y] == idx) continue;

				if(dir == 2 && wall[cur.first][cur.second][x][y]) continue;
				if((dir == 1 || dir == 4) && (wall[cur.first][cur.second][cur.first+tdx[dir-1]][cur.second+tdy[dir-1]] || wall[cur.first+tdx[dir-1]][cur.second+tdy[dir-1]][x][y])) continue;

				visited[x][y] = idx;
				temp[x][y] += curT;
				Q.push({x, y});
				tQ.push(curT-1);
			}
		}
	}
}

void setTemp() {
	int tmp[MAX][MAX];
	for(int i = 1; i <= R; ++i) {
		for(int j = 1; j <= C; ++j) tmp[i][j] = 0;
	}

	for(int i = 1; i <= R; ++i) {
		for(int j = 1; j <= C; ++j) {
			for(int dir = 0; dir < 4; ++dir) {
				if(dir == 1 || dir == 3) continue;
				int x = i + dx[dir];
				int y = j + dy[dir];
				
				if(x < 1 || x > R || y < 1 || y > C) continue;
				if(wall[i][j][x][y] || wall[x][y][i][j]) continue;

				if(temp[i][j] > temp[x][y]) {
					int diff = (temp[i][j] - temp[x][y]) / 4;
					tmp[i][j] -= diff;
					tmp[x][y] += diff;
				}
				else {
					int diff = (temp[x][y] - temp[i][j]) / 4;
					tmp[i][j] += diff;
					tmp[x][y] -= diff;
				}
			}
		}
	}

	for(int i = 1; i <= R; ++i) {
		for(int j = 1; j <= C; ++j) {
			temp[i][j] += tmp[i][j];
			if(temp[i][j] > 0 && (i == 1 || i == R || j == 1 || j == C)) temp[i][j]--;
		}
	}

}

bool checkTest() {
	bool check = true;
	for(auto &p : test) {
		if(temp[p.first][p.second] < K) {
			check = false;
			break;
		}
	}
	return check;
}

void solve() {
	ll chocolate = 0;
	while(true) {
		wind();
		setTemp();
		chocolate++;
		if(chocolate > 100) break;;
		if(checkTest()) break;
	}	
	cout<<chocolate;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}