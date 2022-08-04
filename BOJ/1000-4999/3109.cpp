#include <bits/stdc++.h>
 
// 3109 빵집

// update 220803

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
const long long MOD = 998244353;
const int MAX = 10005;
const int MAXC = 505;

int R, C;
bool board[MAX][MAXC];
bool visited[MAX][MAXC];
int result;

void input() {
	cin>>R>>C;
	char c;
	for(int i = 1; i <= R; ++i) {
		for(int j = 1; j <= C; ++j) {
			cin>>c;
			if(c == '.') board[i][j] = true;
			else board[i][j] = false;	
		}
	}
}

bool f(int r, int c) {
	if(c == C) {
		result++;
		return true;
	}
	
	if(r-1 >= 1 && !visited[r-1][c+1] && board[r-1][c+1]) {
		visited[r-1][c+1] = true;
		bool flag = f(r-1, c+1);
		if(flag) return true;
	}
	if(!visited[r][c+1] && board[r][c+1]) {
		visited[r][c+1] = true;
		bool flag = f(r, c+1);
		if(flag) return true;
	}
	if(r+1 <= R && !visited[r+1][c+1] && board[r+1][c+1]) {
		visited[r+1][c+1] = true;
		bool flag = f(r+1, c+1);
		if(flag) return true;
	}
	return false;
}

void solve() {
	for(int i = 1; i <= R; ++i) {
		visited[i][1] = true;
		f(i, 1);
	}
	// for(int i = 1; i <= R; ++i) {
	// 	for(int j = 1; j <= C; ++j) {
	// 		if(visited[i][j]) cout<<"1";
	// 		else cout<<"0";
	// 	}
	// 	cout<<'\n';
	// }
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