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
const int MAX = 111;

struct Shark {
	int speed;
	int dir;
	int size;
};

int R, C, M;
ll result;
vector<int> board[MAX][MAX];
Shark shark[MAX * MAX];
pii nxt[MAX * MAX];
bool invalid[MAX * MAX];

void fishing(int idx) {
	for(int i = 1; i <= R; ++i) {
		if(board[i][idx].empty()) continue;
		result += shark[board[i][idx][0]].size;
		invalid[board[i][idx][0]] = true;
		board[i][idx].clear();
		break;
	}
}

void shark_move() {
	for(int i = 1; i <= R; ++i) {
		for(int j = 1; j <= C; ++j) {
			if(board[i][j].empty()) continue;

			for(auto &s : board[i][j]) {
				if(shark[s].speed == 0) {
					nxt[s] = {i, j};
					continue;
				}

				if(shark[s].dir == 3) {
					if(shark[s].speed <= (C-j)) {
						nxt[s].second = j + shark[s].speed;
					}
					else {
						int t = (shark[s].speed - (C-j)) / (C - 1);
						int r = (shark[s].speed - (C-j)) % (C - 1);
						if(t % 2) {
							shark[s].dir = 3;
							nxt[s].second = r + 1;
						}
						else {
							shark[s].dir = 4;
							nxt[s].second = C - r;
						}
					}
					nxt[s].first = i;
				}
				else if(shark[s].dir == 4) {
					if(shark[s].speed <= (j-1)) {
						nxt[s].second = j - shark[s].speed;
					}
					else {
						int t = (shark[s].speed - (j-1)) / (C - 1);
						int r = (shark[s].speed - (j-1)) % (C - 1);
						if(t % 2) {
							shark[s].dir = 4;
							nxt[s].second = C - r;
						}
						else {
							shark[s].dir = 3;
							nxt[s].second = r + 1;
						}
					}
					nxt[s].first = i;
				}
				else if(shark[s].dir == 2) {
					if(shark[s].speed <= (R-i)) {
						nxt[s].first = i + shark[s].speed;
					}
					else {
						int t = (shark[s].speed - (R-i)) / (R - 1);
						int r = (shark[s].speed - (R-i)) % (R - 1);
						if(t % 2) {
							shark[s].dir = 2;
							nxt[s].first = r + 1;
						}
						else {
							shark[s].dir = 1;
							nxt[s].first = R - r;
						}
					}
					nxt[s].second = j;
				}
				else {
					if(shark[s].speed <= (i-1)) {
						nxt[s].first = i - shark[s].speed;
					}
					else {
						int t = (shark[s].speed - (i-1)) / (R - 1);
						int r = (shark[s].speed - (i-1)) % (R - 1);
						if(t % 2) {
							shark[s].dir = 1;
							nxt[s].first = R - r;
						}
						else {
							shark[s].dir = 2;
							nxt[s].first = r + 1;
						}
					}
					nxt[s].second = j;
				}
			}
			board[i][j].clear();
		}
	}

	for(int i = 1; i <= M; ++i) {
		if(invalid[i]) continue;
		board[nxt[i].first][nxt[i].second].push_back(i);
	}

	for(int i = 1; i <= R; ++i) {
		for(int j = 1; j <= C; ++j) {
			if(board[i][j].empty()) continue;

			int mx = -1;
			int idx = 0;
			for(auto &s : board[i][j]) {
				if(mx < shark[s].size) {
					idx = s;
					mx = shark[s].size;
				}
			}
			for(auto &s : board[i][j]) {
				if(s != idx) invalid[s] = true;
			}
			board[i][j].clear();
			board[i][j].push_back(idx);
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

	cin>>R>>C>>M;
	for(int i = 1; i <= M; ++i) {
		int r, c, s, d, z;
		cin>>r>>c>>s>>d>>z;
		shark[i].speed = s;
		shark[i].dir = d;
		shark[i].size = z;
		board[r][c].push_back(i);
	}

	for(int i = 1; i <= C; ++i) {
		fishing(i);
		shark_move();

		// for(int i = 1; i <= R; ++i) {
		// 	for(int j = 1; j <= C; ++j) {
		// 		if(board[i][j].empty()) cout<<"0 ";
		// 		else cout<<shark[board[i][j][0]].size<<" ";
		// 	}
		// 	cout<<'\n';
		// }
		// cout<<'\n';
	}

	cout<<result;

	return 0;
}