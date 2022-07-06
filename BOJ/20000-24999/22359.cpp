#include <bits/stdc++.h>

// 22359 흔한 타일 색칠 문제

// update 220705

using namespace std;
typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int,int> pii;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 35;
const long long MOD = 1e9+7;

int T, K, pK, a, b;
char plate[1025][1025];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


void coloring(int r, int c, int nx, int ny) {
	bool check[3] = {false};
	for(int i = 0; i < 2; ++i) {
		for(int j = 0; j < 2; ++j) {
			int tr = r + i;
			int tc = c + j;
			for(int dir = 0; dir < 4; ++dir) {
				int x = tr + dx[dir];
				int y = tc + dy[dir];
				if(x < 1 || x > pK || y < 1 || y > pK) continue;

				if(plate[x][y] != '-' && plate[x][y] != '@') {
					check[plate[x][y] - 'a'] = true;
				}
			}
		}
	}

	int color;
	for(int i = 0; i < 3; ++i) {
		if(!check[i]) {
			color = i;
			break;
		}
	}

	for(int i = 0; i < 2; ++i) {
		for(int j = 0; j < 2; ++j) {
			int tr = r + i;
			int tc = c + j;
			if(tr == nx && tc == ny) continue;
			plate[tr][tc] = 'a' + color;
		}
	}
}

void recur(int r, int c, int k, int x, int y) {
	if(k <= 1) {
		coloring(r,c,x,y);
		return;
	}

	int d = 1<<(k-1);

	if(x < r+d && y < c+d) {
		coloring(r+d-1, c+d-1, r+d-1, c+d-1);
		recur(r, c, k-1, x, y);
		recur(r+d, c, k-1, r+d, c+d-1);
		recur(r, c+d, k-1, r+d-1, c+d);
		recur(r+d, c+d, k-1, r+d, c+d);
	}
	else if(y < c+d) {
		coloring(r+d-1, c+d-1, r+d, c+d-1);
		recur(r, c, k-1, r+d-1, c+d-1);
		recur(r+d, c, k-1, x, y);
		recur(r, c+d, k-1, r+d-1, c+d);
		recur(r+d, c+d, k-1, r+d, c+d);
	}
	else if(x < r+d) {
		coloring(r+d-1, c+d-1, r+d-1, c+d);
		recur(r, c, k-1, r+d-1, c+d-1);
		recur(r+d, c, k-1, r+d, c+d-1);
		recur(r, c+d, k-1, x, y);
		recur(r+d, c+d, k-1, r+d, c+d);
	}
	else {
		coloring(r+d-1, c+d-1, r+d, c+d);
		recur(r, c, k-1, r+d-1, c+d-1);
		recur(r+d, c, k-1, r+d, c+d-1);
		recur(r, c+d, k-1, r+d-1, c+d);
		recur(r+d, c+d, k-1, x, y);
	}
}

void solve() {
	recur(1, 1, K, a, b);

	for(int i = 1; i <= pK; ++i) {
		for(int j = 1; j <= pK; ++j) {
			cout<<plate[i][j];
		}
		cout<<'\n';
	}
}

void input() {
	memset(plate,'-',sizeof(plate));
	cin>>a>>b;
	plate[a][b] = '@';	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>T>>K;
	pK = (1 << K);
	while(T--) {
		input();
		solve();
	}
	
	return 0;
}