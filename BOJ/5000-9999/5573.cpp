#include <bits/stdc++.h>
 
// 5573 산책

// update 220804

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

int H, W, N;
int board[MAX][MAX];
int cost[MAX][MAX];

void input() {
	cin>>H>>W>>N;
	for(int i = 1; i <= H; ++i) {
		for(int j = 1; j <= W; ++j) {
			cin>>board[i][j];		
		}
	}
}

void dfs(int i, int j) {
	if(i == H+1 || j == W+1) {
		cout<<i<<" "<<j;
		return;
	}

	if(board[i][j]) {
		if(cost[i][j] % 2) dfs(i, j+1);
		else dfs(i+1, j);
	}
	else {
		if(cost[i][j] % 2) dfs(i+1, j);
		else dfs(i, j+1);
	}
}

void solve() {
	cost[1][1] = N;
	for(int i = 1; i <= H; ++i) {
		for(int j = 1; j <= W; ++j) {
			int cur = cost[i][j];
			if(cur % 2) {
				if(board[i][j]) {
					cost[i][j+1] += cur/2 + 1;
					cost[i+1][j] += cur/2;
				}
				else {
					cost[i][j+1] += cur/2;
					cost[i+1][j] += cur/2 + 1;
				}
			}
			else {
				cost[i][j+1] += cur/2;
				cost[i+1][j] += cur/2;
			}
		}
	}
	dfs(1, 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}