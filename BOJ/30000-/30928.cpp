#pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;

const int MAX = 15;

int N, M;
char board[MAX][MAX];
vector<pii> st;
int ans = 0;
string S = "YOKOHAMA";

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void f(int idx, pii cur) {
	if(idx == 7) {
		ans++;
		return;
	}

	for(int dir = 0; dir < 4; ++dir) {
		int x = cur.first + dx[dir];
		int y = cur.second + dy[dir];
		if(x < 1 || x > N || y < 1 || y > M) continue;
		if(board[x][y] == S[idx+1]) {
			f(idx+1, { x, y });
		}
	}
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin>>N>>M;

	for(int i = 1; i <= N; ++i) {
		for(int j = 1; j <= M; ++j) {
			cin>>board[i][j];
			if(board[i][j] == 'Y') st.push_back({ i, j });
		}
	}
	
	for(auto &p : st) {
		f(0, p);
	}

	cout<<ans;

}