#include <bits/stdc++.h>
 
// 3037 혼란

// update 220721
 
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef pair<double, double> pdd;
 
const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const long long MOD = 1e9+7;
const int MAXN = 1005;
const int MAXC = 10005;

int N, C;
ll dp[MAXN][MAXC];

void input() {
	cin>>N>>C;
}

void solve() {
	dp[1][0] = 1;
	dp[2][0] = dp[2][1] = 1;
	for(int i = 3; i <= N; ++i) {
		dp[i][0] = 1;
		int prvlen = (((i-1)*(i-2))/2 + 1);
		int curlen = (i*(i-1))/2 + 1;
		for(int j = 1; j <= 10001; ++j) {
			dp[i-1][j] = (dp[i-1][j] + dp[i-1][j-1]) % MOD;
			dp[i][j] = dp[i-1][j];
			if(curlen - j < prvlen) dp[i][j] = (dp[i][j] - dp[i-1][prvlen - (curlen - j) - 1]) % MOD;
			dp[i][j] = (dp[i][j] + MOD) % MOD;
		}
	}

	cout<<dp[N][C];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	input();
	solve();

	return 0;
}