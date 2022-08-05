#include <bits/stdc++.h>
 
// 2873 롤러코스터

// update 220805

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
const int MAX = 1005;

int R, C;
int board[MAX][MAX];

void input() {
	cin>>R>>C;
	for(int i = 1; i <= R; ++i) {
		for(int j = 1; j <= C; ++j) {
			cin>>board[i][j];
		}
	}
}

void solve() {
	if(R % 2 == 0 && C % 2 == 0) {
		pii minpos = {-1, -1};
		int minval = INF;
		for(int i = 1; i <= R; ++i) {
			for(int j = 1; j <= C; ++j) {
				if(i == 1 && j == 1 || i == R && j == C || (i+j) % 2 == 0) continue;
				if(minval > board[i][j]) {
					minpos = {i, j};
					minval = board[i][j];
				}
			}
		}
		// 만약 가장 작은 위치가 (홀수, 짝수) 이거나 (짝수, 홀수) 이면, 그 위치를 제외하고는 모두 지나갈 수 있다
		if(minpos.first == R) {
			for(int i = 1; i <= minpos.first-2; ++i) {
				for(int j = 2; j <= C; ++j) {
					if(i % 2) cout<<"R";
					else cout<<"L";
				}
				cout<<"D";
			}
			for(int i = 1, k = 1; i <= C; ++i, ++k) {
				if(k % 2) {
					if(i == minpos.second) --k;
					else cout<<"D";
				}
				else {
					if(i == minpos.second) --k;
					else cout<<"U";
				}
				if(i != C) cout<<"R";
			}
		}
		else {
			for(int i = 1; i <= minpos.first-1; ++i) {
				for(int j = 2; j <= C; ++j) {
					if(i % 2) cout<<"R";
					else cout<<"L";
				}
				cout<<"D";
			}
			if(minpos.first % 2) {
				for(int i = 1, k = 1; i <= C; ++i, ++k) {
					if(k % 2) {
						if(i == minpos.second) --k;
						else cout<<"D";
					}
					else {
						if(i == minpos.second) --k;
						else cout<<"U";
					}
					if(i != C) cout<<"R";
				}
				for(int i = minpos.first + 2; i <= R; ++i) {
					cout<<"D";
					for(int j = 2; j <= C; ++j) {
						if(i % 2) cout<<"L";
						else cout<<"R";
					}
				}
			}
			else {
				for(int i = C, k = 1; i >= 1; --i, ++k) {
					if(k % 2) {
						if(i == minpos.second) --k;
						else cout<<"D";
					}
					else {
						if(i == minpos.second) --k;
						else cout<<"U";
					}
					if(i != 1) cout<<"L";
				}
				for(int i = minpos.first + 2; i <= R; ++i) {
					cout<<"D";
					for(int j = 2; j <= C; ++j) {
						if(i % 2) cout<<"L";
						else cout<<"R";
					}
				}
			}
		}
	}
	else if(R % 2 == 1) {
		for(int i = 1; i <= R; ++i) {
			for(int j = 2; j <= C; ++j) {
				if(i % 2) cout<<"R";
				else cout<<"L";
			}
			if(i != R) cout<<"D";
		}
	}
	else {
		for(int i = 1; i <= C; ++i) {
			for(int j = 2; j <= R; ++j) {
				if(i % 2) cout<<"D";
				else cout<<"U";
			}
			if(i != C) cout<<"R";
		}
	}
	cout<<"\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}