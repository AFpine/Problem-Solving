#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

// 1209

// 221104

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
const int INF = 1e9+7;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const long long MOD = 1e9+7;
const int MAX = 2020;

int N;
ll A[MAX], t[MAX], dp[2][MAX][MAX];

ll f(int flag, int i, int j) {
	auto &ret = dp[flag][i][j];
	if(ret != -1) return ret;
	if(i == N+1) return ret = 0;

	ret = f(flag, i+1, j) + abs(A[i] - t[j]);
	if(flag && j < N) ret = min(ret, f(flag, i, j+1));
	if(!flag && j > 1) ret = min(ret, f(flag, i, j-1));

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
	
	cin>>N;
	for(int i = 1; i <= N; ++i) { cin>>A[i]; t[i] = A[i]; }
	sort(t+1, t+1+N);

	memset(dp, -1, sizeof(dp));

	ll ans = min(f(1, 1, 1), f(0, 1, N));

	cout<<ans;

	return 0;
}
