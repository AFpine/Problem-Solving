#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

// 16468

// 221111

using namespace std;
#define sz(a) (int)(a.size()) 
#define all(a) (a).begin(), (a).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef pair<long double, long double> pdd;
typedef complex<double> base;

const double PI = acos(-1);
const int INF = 1e9+7;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const long long MOD = 100030001;
const int MAX = 333;

int N, L;
ll dp[MAX][MAX][2];

ll f(int n, int l, int c) {
	if(n == 0) return (c ? l == 0 : l != 0);
	if(l == 0) return 0;
	auto &ret = dp[n][l][c];
	if(ret != -1) return ret;

	ret = 0;
	if(c) {
		for(int i = 0; i < n; ++i) {
			ret = (ret + f(i, l-1, 1) * f(n-1-i, l-1, 1)) % MOD;
			ret = (ret + f(i, l-1, 1) * f(n-1-i, l-1, 0)) % MOD;
			ret = (ret + f(i, l-1, 0) * f(n-1-i, l-1, 1)) % MOD;
		}
	}
	else {
		for(int i = 0; i < n; ++i) ret = (ret + f(i, l-1, 0) * f(n-1-i, l-1, 0)) % MOD;
	}
	return ret;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(dp, -1, sizeof(dp));

	cin>>N>>L;

	cout<<f(N, L, 1);

	return 0;
}