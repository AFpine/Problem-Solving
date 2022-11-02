#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

// 2008

// 221102

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
const int MAXN = 105;
const int MAXM = 505;

int N, M, A, B, X, Y, arr[3*MAXM];
ll dp[3*MAXM][MAXN];

ll f(int i, int j, ll k) {
	if(j < 1 || j > N) return INF;
	auto &ret = dp[i][j];
	if(ret != -1) return ret;
	if(i == 3*MAXM-1) {
		if(j == B) return 0;
		else return INF;
	}

	ret = INF;
	if(arr[i] == j-1) { 
		ret = min(ret, f(i+1, j-1, k));
		ret = min(ret, f(i+1, j, k)+X);
		ret = min(ret, f(i+1, j+1, k)+Y);
	}
	else if(arr[i] == j) {
		ret = min(ret, f(i+1, j+1, k));
		ret = min(ret, f(i+1, j-1, k)+Y);
		ret = min(ret, f(i+1, j, k)+X);
	}
	else {
		ret = min(ret, f(i+1, j, k));
		ret = min(ret, f(i+1, j-1, k)+Y);
		ret = min(ret, f(i+1, j+1, k)+Y);
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

	fill(arr, arr+3*MAXM, -1);
	memset(dp, -1, sizeof(dp));

	cin>>N>>M;
	cin>>A>>B>>X>>Y;
	for(int i = 1; i <= M; ++i) cin>>arr[i+MAXM];

	cout<<f(1, A, 0);

	return 0;
}
