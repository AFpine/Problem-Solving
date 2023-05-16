#include <bits/stdc++.h>

using namespace std;
#define sz(a) (int)(a.size()) 
#define all(a) (a).begin(), (a).end()
typedef long long ll;
// typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef pair<long double, long double> pdd;
typedef complex<double> cplx;

const double PI = acos(-1);
const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const long long MOD = 1e9+7;
const int MAX = 1010101;

struct Material {
	int x[6][6];
	char c[6][6];
};

Material material[45], grid;
int N;
int result;
bool selected[45];

int dx[] = {0, 0, 1, 1};
int dy[] = {0, 1, 0, 1};

void f(int cnt) {
	if(cnt == 4) {
		int cur = 0;
		for(int r = 1; r <= 5; ++r) {
			for(int c = 1; c <= 5; ++c) {
				if(grid.c[r][c] == 'W') continue;
				else if(grid.c[r][c] == 'R') {
					cur += grid.x[r][c] * 7;
				}
				else if(grid.c[r][c] == 'B') {
					cur += grid.x[r][c] * 5;
				}
				else if(grid.c[r][c] == 'G') {
					cur += grid.x[r][c] * 3;
				}
				else if(grid.c[r][c] == 'Y') {
					cur += grid.x[r][c] * 2;
				}
			}
		}
		result = max(result, cur);
		return;
	}
	
	auto pre = grid;
	for(int k = 0; k < 4*N; ++k) {
		if(selected[k/4]) continue;

		selected[k/4] = true;
		for(int dir = 0; dir < 4; ++dir) {
			for(int i = 1; i <= 4; ++i) {
				for(int j = 1; j <= 4; ++j) {
					grid.x[i+dx[dir]][j+dy[dir]] += material[k].x[i][j];
					if(grid.x[i+dx[dir]][j+dy[dir]] > 9) grid.x[i+dx[dir]][j+dy[dir]] = 9;
					if(grid.x[i+dx[dir]][j+dy[dir]] < 0) grid.x[i+dx[dir]][j+dy[dir]] = 0;
					if(material[k].c[i][j] != 'W') grid.c[i+dx[dir]][j+dy[dir]] = material[k].c[i][j];
				}
			}
			f(cnt+1);
			grid = pre;
		}
		selected[k/4] = false;
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

	for(int i = 1; i <= 5; ++i) {
		for(int j = 1; j <= 5; ++j) {
			grid.x[i][j] = 0;
			grid.c[i][j] = 'W';
		}
	}

	cin>>N;
	for(int t = 0; t < N; ++t) {
		for(int i = 1; i <= 4; ++i) {
			for(int j = 1; j <= 4; ++j) {
				cin>>material[4*t].x[i][j];
			}
		}
		for(int i = 1; i <= 4; ++i) {
			for(int j = 1; j <= 4; ++j) {
				cin>>material[4*t].c[i][j];
			}
		}
		for(int i = 1; i <= 4; ++i) {
			for(int j = 1; j <= 4; ++j) {
				material[4*t+1].x[j][5-i] = material[4*t].x[i][j];
				material[4*t+1].c[j][5-i] = material[4*t].c[i][j];
			}
		}
		for(int i = 1; i <= 4; ++i) {
			for(int j = 1; j <= 4; ++j) {
				material[4*t+2].x[5-i][5-j] = material[4*t].x[i][j];
				material[4*t+2].c[5-i][5-j] = material[4*t].c[i][j];
			}
		}
		for(int i = 1; i <= 4; ++i) {
			for(int j = 1; j <= 4; ++j) {
				material[4*t+3].x[5-j][i] = material[4*t].x[i][j];
				material[4*t+3].c[5-j][i] = material[4*t].c[i][j];
			}
		}
	}

	f(1);

	cout<<result;

	return 0;
}