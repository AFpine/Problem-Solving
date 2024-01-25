#pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
#define sz(a) (ll)(a.size()) 
#define all(a) (a).begin(), (a).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef pair<long double, long double> pdd;
typedef complex<double> cplx;

const int MAX = 1010101;

int R, C, T;
string S;
char board[20][20];
set<pii> target;

bool validation() {
	bool invalid = false;
	for(int i = 1; i <= R; ++i) {
		for(int j = 1; j <= C; ++j) {
			if(board[i][j] == 'b') {
				if(target.find({ i, j }) == target.end()) invalid = true;
			}
		}
	}

	if(invalid) return false;
	else return true;
}

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while(true) {
		cin>>R>>C;
		if(R == 0 && C == 0) break;

		pii worker = { 0, 0 };
		target.clear();
		for(int i = 1; i <= R; ++i) {
			for(int j = 1; j <= C; ++j) {
				cin>>board[i][j];
				if(board[i][j] == 'w') {
					worker = { i, j };
					board[i][j] = '.';
				}
				else if(board[i][j] == '+') {
					target.insert({ i, j });
					board[i][j] = '.';
				}
				else if(board[i][j] == 'B') {
					target.insert({ i, j });
					board[i][j] = 'b';
				}
				else if(board[i][j] == 'W') {
					worker = { i, j };
					target.insert({ i, j });
					board[i][j] = '.';
				}
			}
		}
		cin>>S;

		bool complete = false;
		for(int s = 0; s < S.length(); ++s) {
			int dx = 0;
			int dy = 0;
			if(S[s] == 'U')	dx = -1;
			else if(S[s] == 'D') dx = 1;
			else if(S[s] == 'R') dy = 1;
			else dy = -1;

			int x = worker.first;
			int y = worker.second;
			int nx = x + dx;
			int ny = y + dy;
			int nnx = x + 2*dx;
			int nny = y + 2*dy;

			if(board[nx][ny] == '#') continue;
			
			if(board[nx][ny] == '.') {
				worker = { nx, ny };
			}

			if(board[nx][ny] == 'b') {
				if(board[nnx][nny] == '.') {
					board[nx][ny] = '.';
					board[nnx][nny] = 'b';
					worker = { nx, ny };
				}
			}

			if(validation()) {
				complete = true;
				break;
			}
		}

		if(target.find({ worker.first, worker.second }) != target.end()) {
			board[worker.first][worker.second] = 'W';
		}
		else {
			board[worker.first][worker.second] = 'w';
		}

		for(auto &p : target) {
			if(board[p.first][p.second] == '.') board[p.first][p.second] = '+';
			else if(board[p.first][p.second] == 'b') board[p.first][p.second] = 'B';
		}

		cout<<"Game "<<++T<<": "<< (complete ? "complete" : "incomplete") << '\n';
		for(int i = 1; i <= R; ++i) {
			for(int j = 1; j <= C; ++j) {
				cout<<board[i][j];
			}
			cout<<'\n';
		}
	}

	return 0;
}