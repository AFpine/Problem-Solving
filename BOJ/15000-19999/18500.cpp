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
const int MAX = 105;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int R, C, N, cnt;
char board[MAX][MAX];
int comp[MAX][MAX];
int minh[MAX][MAX];
int maxh[MAX][MAX];
vector<pii> compv[MAX];

void init() {
	for(int i = 0; i < MAX; ++i) {
		for(int j = 0; j < MAX; ++j) {
			comp[i][j] = 0;
			minh[i][j] = -1;
		}
		compv[i].clear();
	}
	cnt = 1;
}

void getComp(pii st) {
	if(board[st.first][st.second] == '.' || comp[st.first][st.second]) return;
	if(st.first < R) ++cnt; 
	comp[st.first][st.second] = cnt;
	queue<pii> Q;
	Q.push(st);
	
	while(!Q.empty()) {
		auto cur = Q.front();
		Q.pop();

		compv[cnt].push_back(cur);
		minh[cnt][cur.second] = max(minh[cnt][cur.second], cur.first);

		for(int dir = 0; dir < 4; ++dir) {
			int x = cur.first + dx[dir];
			int y = cur.second + dy[dir];
			if(x <= 0 || x > R || y <= 0 || y > C) continue;
			if(board[x][y] == '.' || comp[x][y] > 0) continue;
			comp[x][y] = cnt;
			Q.push({x, y});
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
	
	cin>>R>>C;
	for(int i = 1; i <= R; ++i) {
		for(int j = 1; j <= C; ++j) cin>>board[i][j];
	}
	
	cin>>N;
	for(int t = 1; t <= N; ++t) {
		init();

		int h;
		cin>>h;
		if(t % 2) {
			for(int j = 1; j <= C; ++j) {
				if(board[R-h+1][j] == 'x') {
					board[R-h+1][j] = '.';
					break;
				}
			}
		}
		else {
			for(int j = C; j >= 1; --j) {
				if(board[R-h+1][j] == 'x') {
					board[R-h+1][j] = '.';
					break;
				}
			}
		}

		for(int i = R; i >= 1; --i) {
			for(int j = 1; j <= C; ++j) {
				getComp({i, j});
			}
		}
		
		for(int i = 1; i <= R; ++i) for(int j = 1; j <= C; ++j) board[i][j] = '.';

		if(cnt == 1) {
			int f = INF;
			for(int j = 1; j <= C; ++j) f = min(f, R - minh[1][j]);
			for(auto &p : compv[1]) board[p.first + f][p.second] = 'x';
		}
		else {
			for(auto &p : compv[1]) board[p.first][p.second] = 'x';
			
			int f = INF;
			for(auto &p : compv[2]) {
				for(int i = p.first; i <= R; ++i) {
					if(i == R) f = min(f, R - p.first);
					if(board[i+1][p.second] == 'x') {
						f = min(f, i - p.first);
					}
				}
			}
			for(auto &p : compv[2]) board[p.first + f][p.second] = 'x';
		}
	}

	for(int i = 1; i <= R; ++i) {
		for(int j = 1; j <= C; ++j) cout<<board[i][j];
		cout<<'\n';
	}


	return 0;
}
