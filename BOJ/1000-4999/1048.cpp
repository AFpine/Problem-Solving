#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

// 1048 

// 221103

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
const int MAX = 305;

int N, M, L;
ll dp[55][MAX][MAX];
char board[MAX][MAX];
string S;

ll f(int l, int si, int sj, int ei, int ej) {
	if(si < 1) si = 1;
	if(sj < 1) sj = 1;
	if(ei > N) ei = N;
	if(ej > M) ej = M;
	ll ret = 0;
	ret += dp[l][ei][ej];
	ret -= dp[l][si-1][ej];
	ret -= dp[l][ei][sj-1];
	ret += dp[l][si-1][sj-1];
	ret += 2LL*MOD;
	return ret % MOD;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>M>>L;
	cin>>S;
	for(int i = 1; i <= N; ++i) {
		for(int j = 1; j <= M; ++j) {
			cin>>board[i][j];
			dp[0][i][j] = dp[0][i-1][j] + dp[0][i][j-1] - dp[0][i-1][j-1];
			if(board[i][j] == S[0]) dp[0][i][j]++;
		}
	}

	for(int l = 1; l < sz(S); ++l) {
		for(int i = 1; i <= N; ++i) {
			for(int j = 1; j <= M; ++j) {
				if(board[i][j] == S[l]) {
					dp[l][i][j] = f(l-1, 1, 1, N, M);
					// dp[l][i][j] -= f(l-1, i-2, j-2, i+2, j+2);
					// dp[l][i][j] -= f(l-1, i-1, 1, i+1, j-3);
					// dp[l][i][j] -= f(l-1, 1, j-1, i-3, j+1);
					// dp[l][i][j] -= f(l-1, i-1, j+3, i+1, M);
					// dp[l][i][j] -= f(l-1, i+3, j-1, N, j+1);
					dp[l][i][j] -= f(l-1, 1, j-1, N, j+1);
					dp[l][i][j] -= f(l-1, i-1, 1, i+1, M);
					dp[l][i][j] -= f(l-1, i-2, j-2, i+2, j+2);
					dp[l][i][j] += f(l-1, i-2, j-1, i+2, j+1);
					dp[l][i][j] += f(l-1, i-1, j-2, i+1, j+2);
				}
				dp[l][i][j] += dp[l][i-1][j];
				dp[l][i][j] += dp[l][i][j-1];
				dp[l][i][j] -= dp[l][i-1][j-1];
				dp[l][i][j] += 2LL*MOD;
				dp[l][i][j] %= MOD;
			}
		}
	}
	cout<<dp[sz(S)-1][N][M];
	
	return 0;
}
