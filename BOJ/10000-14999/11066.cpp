#include <bits/stdc++.h>
 
// 11066 파일 합치기

// update 220809

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
const int MAX = 505;

int K;
int arr[MAX];
ll dp[MAX][MAX];
ll psum[MAX];

void input() {
	cin>>K;
	for(int i = 1; i <= K; ++i) {
		cin>>arr[i];
		dp[i][i] = 0;
		psum[i] = arr[i] + psum[i-1];
	}
}

ll f(int i, int j) {
	if(i > j) return llINF;
	if(i == j) return 0;

	ll &ret = dp[i][j];
	if(ret != -1) return ret;

	ret = llINF;
	for(int k = i; k <= j; ++k) {
		ret = min(ret, f(i, k) + f(k+1, j) + psum[j] - psum[i-1]);
	}
	return ret;
}

void solve() {
	memset(dp, -1, sizeof(dp));
	cout<<f(1, K)<<'\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tt;
	cin>>tt;
	while(tt--) {
		input();
		solve();
	}

	return 0;
}