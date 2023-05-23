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
const long long MOD = 1e9+7;
const int MAX = 15;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int N, M;
char board[MAX][MAX];
pii R, B, O;
map<int, int> mp;
int result = INF;
bool success;

int pos(pii r, pii b) {
	return r.first * pow(17, 3) + r.second * pow(17, 2) + b.first * 17 + b.second;
}

bool Move(int dir, pii &R, pii &B, int cnt) {
	pii r = R, b = B;
	bool rflag = false, bflag = false;
	if(dir == 0) {
		if(r.first > b.first) {
			for(int i = 1; i <= N; ++i) {
				int x = r.first + dx[dir];
				if(x > N) break;
				if(board[x][r.second] == '#') break;
				if(pii(x, r.second) == O) {
					rflag = true;
					r = {-1, -1};
					break;
				}
				r.first = x;
			}
			for(int i = 1; i <= N; ++i) {
				int x = b.first + dx[dir];
				if(x > N) break;
				if(board[x][b.second] == '#') break;
				if(pii(x, b.second) == r) break;
				if(pii(x, b.second) == O) {
					bflag = true;
					b = {-1, -1};
					break;
				}
				b.first = x;
			}
			if(rflag && bflag) return false;
			else if(bflag) return false;
			else if(rflag) { success = true; return true; }
			else if(mp[pos(r, b)] > 0 && mp[pos(r, b)] <= cnt) return false;
			else {
				mp[pos(r, b)] = cnt;
				R = r;
				B = b;
				return true;
			}
		}
		else {
			for(int i = 1; i <= N; ++i) {
				int x = b.first + dx[dir];
				if(x > N) break;
				if(board[x][b.second] == '#') break;
				if(pii(x, b.second) == O) {
					bflag = true;
					b = {-1, -1};
					break;
				}
				b.first = x;
			}
			for(int i = 1; i <= N; ++i) {
				int x = r.first + dx[dir];
				if(x > N) break;
				if(board[x][r.second] == '#') break;
				if(pii(x, r.second) == b) break;
				if(pii(x, r.second) == O) {
					rflag = true;
					r = {-1, -1};
					break;
				}
				r.first = x;
			}
			if(rflag && bflag) return false;
			else if(bflag) return false;
			else if(rflag) { success = true; return true; }
			else if(mp[pos(r, b)] > 0 && mp[pos(r, b)] <= cnt) return false;
			else {
				mp[pos(r, b)] = cnt;
				R = r;
				B = b;
				return true;
			}
		}
	}
	else if(dir == 1) {
		if(r.first < b.first) {
			for(int i = 1; i <= N; ++i) {
				int x = r.first + dx[dir];
				if(x < 1) break;
				if(board[x][r.second] == '#') break;
				if(pii(x, r.second) == O) {
					rflag = true;
					r = {-1, -1};
					break;
				}
				r.first = x;
			}
			for(int i = 1; i <= N; ++i) {
				int x = b.first + dx[dir];
				if(x < 1) break;
				if(board[x][b.second] == '#') break;
				if(pii(x, b.second) == r) break;
				if(pii(x, b.second) == O) {
					bflag = true;
					b = {-1, -1};
					break;
				}
				b.first = x;
			}
			if(rflag && bflag) return false;
			else if(bflag) return false;
			else if(rflag) { success = true; return true; }
			else if(mp[pos(r, b)] > 0 && mp[pos(r, b)] <= cnt) return false;
			else {
				mp[pos(r, b)] = cnt;
				R = r;
				B = b;
				return true;
			}
		}
		else {
			for(int i = 1; i <= N; ++i) {
				int x = b.first + dx[dir];
				if(x < 1) break;
				if(board[x][b.second] == '#') break;
				if(pii(x, b.second) == O) {
					bflag = true;
					b = {-1, -1};
					break;
				}
				b.first = x;
			}
			for(int i = 1; i <= N; ++i) {
				int x = r.first + dx[dir];
				if(x < 1) break;
				if(board[x][r.second] == '#') break;
				if(pii(x, r.second) == b) break;
				if(pii(x, r.second) == O) {
					rflag = true;
					r = {-1, -1};
					break;
				}
				r.first = x;
			}
			if(rflag && bflag) return false;
			else if(bflag) return false;
			else if(rflag) { success = true; return true; }
			else if(mp[pos(r, b)] > 0 && mp[pos(r, b)] <= cnt) return false;
			else {
				mp[pos(r, b)] = cnt;
				R = r;
				B = b;
				return true;
			}
		}
	}
	else if(dir == 2) {
		if(r.second > b.second) {
			for(int i = 1; i <= M; ++i) {
				int y = r.second + dy[dir];
				if(y > M) break;
				if(board[r.first][y] == '#') break;
				if(pii(r.first, y) == O) {
					rflag = true;
					r = {-1, -1};
					break;
				}
				r.second = y;
			}
			for(int i = 1; i <= M; ++i) {
				int y = b.second + dy[dir];
				if(y > M) break;
				if(board[b.first][y] == '#') break;
				if(pii(b.first, y) == r) break;
				if(pii(b.first, y) == O) {
					bflag = true;
					b = {-1, -1};
					break;
				}
				b.second = y;
			}
			if(rflag && bflag) return false;
			else if(bflag) return false;
			else if(rflag) { success = true; return true; }
			else if(mp[pos(r, b)] > 0 && mp[pos(r, b)] <= cnt) return false;
			else {
				mp[pos(r, b)] = cnt;
				R = r;
				B = b;
				return true;
			}
		}
		else {
			for(int i = 1; i <= M; ++i) {
				int y = b.second + dy[dir];
				if(y > M) break;
				if(board[b.first][y] == '#') break;
				if(pii(b.first, y) == O) {
					bflag = true;
					b = {-1, -1};
					break;
				}
				b.second = y;
			}
			for(int i = 1; i <= M; ++i) {
				int y = r.second + dy[dir];
				if(y > M) break;
				if(board[r.first][y] == '#') break;
				if(pii(r.first, y) == b) break;
				if(pii(r.first, y) == O) {
					rflag = true;
					r = {-1, -1};
					break;
				}
				r.second = y;
			}
			if(rflag && bflag) return false;
			else if(bflag) return false;
			else if(rflag) { success = true; return true; }
			else if(mp[pos(r, b)] > 0 && mp[pos(r, b)] <= cnt) return false;
			else {
				mp[pos(r, b)] = cnt;
				R = r;
				B = b;
				return true;
			}
		}
	}
	else {
		if(r.second < b.second) {
			for(int i = 1; i <= M; ++i) {
				int y = r.second + dy[dir];
				if(y < 1) break;
				if(board[r.first][y] == '#') break;
				if(pii(r.first, y) == O) {
					rflag = true;
					r = {-1, -1};
					break;
				}
				r.second = y;
			}
			for(int i = 1; i <= M; ++i) {
				int y = b.second + dy[dir];
				if(y < 1) break;
				if(board[b.first][y] == '#') break;
				if(pii(b.first, y) == r) break;
				if(pii(b.first, y) == O) {
					bflag = true;
					b = {-1, -1};
					break;
				}
				b.second = y;
			}
			if(rflag && bflag) return false;
			else if(bflag) return false;
			else if(rflag) { success = true; return true; }
			else if(mp[pos(r, b)] > 0 && mp[pos(r, b)] <= cnt) return false;
			else {
				mp[pos(r, b)] = cnt;
				R = r;
				B = b;
				return true;
			}
		}
		else {
			for(int i = 1; i <= M; ++i) {
				int y = b.second + dy[dir];
				if(y < 1) break;
				if(board[b.first][y] == '#') break;
				if(pii(b.first, y) == O) {
					bflag = true;
					b = {-1, -1};
					break;
				}
				b.second = y;
			}
			for(int i = 1; i <= M; ++i) {
				int y = r.second + dy[dir];
				if(y < 1) break;
				if(board[r.first][y] == '#') break;
				if(pii(r.first, y) == b) break;
				if(pii(r.first, y) == O) {
					rflag = true;
					r = {-1, -1};
					break;
				}
				r.second = y;
			}
			if(rflag && bflag) return false;
			else if(bflag) return false;
			else if(rflag) { success = true; return true; }
			else if(mp[pos(r, b)] > 0 && mp[pos(r, b)] <= cnt) return false;
			else {
				mp[pos(r, b)] = cnt;
				R = r;
				B = b;
				return true;
			}
		}
	}
}

void backtracking(pii R, pii B, int cnt) {
	for(int k = 0; k < 4; ++k) {
		pii r = R, b = B;
		if(!Move(k, r, b, cnt)) continue;
		if(success) {
			result = min(result, cnt);
			success = false;
			return;
		}
		backtracking(r, b, cnt+1);
	}
	return;
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
			if(board[i][j] == '#') continue;
			if(board[i][j] == 'R') R = {i, j};
			else if(board[i][j] == 'B') B = {i, j};
			else if(board[i][j] == 'O') O = {i, j};
			board[i][j] = '.';
		}
	}

	// for(int i = 1; i <= N; ++i) {
	// 	for(int j = 1; j <= M; ++j) {
	// 		cout<<board[i][j];
	// 	}
	// 	cout<<'\n';
	// }

	mp[pos(R, B)]++;
	backtracking(R, B, 1);

	if(result == INF) cout<<"-1";
	else cout<<result;

	return 0;
}