#include <bits/stdc++.h>
 
// 11062 카드 게임

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

int N;
int arr[MAX];
int dp[MAX][MAX];

int f(int l, int r) {
	if(l > r) return 0;

	int &ret = dp[l][r];
	if(ret != -1) return ret;

	ret = 0;
	auto t1 = arr[l] + min(f(l+1, r-1), f(l+2, r));
	auto t2 = arr[r] + min(f(l+1, r-1), f(l, r-2));
	return ret = max(t1, t2);
}

void input() {
	cin>>N;
	for(int i = 1; i <= N; ++i) cin>>arr[i];
	memset(dp, -1, sizeof(dp));
}

void solve() {
	cout<<f(1, N)<<'\n';
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