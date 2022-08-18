#include <bits/stdc++.h>
 
// 16932 모양 만들기

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
const long long MOD = 9999991;
const int MAX = 1005;

int N, M;
int board[MAX][MAX];
int uf[MAX*MAX*2];
int check[MAX*MAX*2];
int result;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int find(int a) {
	if(uf[a] < 0) return a;
	return uf[a] = find(uf[a]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if(a == b) return;
	uf[a] += uf[b];
	uf[b] = a;
}

void shape() {
	for(int i = 1; i <= N; ++i) {
		for(int j = 1; j <= M; ++j) {
			if(board[i][j] == 0) continue;
			for(int dir = 0; dir < 4; ++dir) {
				int x = i + dx[dir]; 
				int y = j + dy[dir];
				if(x < 1 || x > N || y < 1 || y > M) continue;
				if(board[x][y] == 0) continue;
				
				if(find(i*MAX + j) == find(x*MAX + y)) continue;
				merge((i*MAX + j), (x*MAX + y));
				result = max(result, -uf[find(i*MAX + j)]);
			}
		}
	}
}

void maxShape() {
	for(int i = 1; i <= N; ++i) {
		for(int j = 1; j <= M; ++j) {
			if(board[i][j] == 1) continue;
			int temp = 0;
			for(int dir = 0; dir < 4; ++dir) {
				int x = i + dx[dir];
				int y = j + dy[dir];
				if(x < 1 || x > N || y < 1 || y > M) continue;
				if(board[x][y] == 0) continue;

				if(check[find(x*MAX + y)] == (i*MAX + j)) continue;

				check[find(x*MAX + y)] = (i*MAX + j);
				temp += -uf[find(x*MAX + y)];
			}
			result = max(result, temp + 1);
		}
	}
}

void input() {
	cin>>N>>M;
	for(int i = 1; i <= N; ++i) {
		for(int j = 1; j <= M; ++j) {
			cin>>board[i][j];
		}
	}
}

void solve() {
	memset(uf, -1, sizeof(uf));
	shape();
	maxShape();

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