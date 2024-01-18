#pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
#define sz(a) (ll)(a.size()) 
#define all(a) (a).begin(), (a).end()
typedef unsigned long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef pair<long double, long double> pdd;
typedef complex<double> cplx;

const int MOD = 10007;
int N;
int ans = 0;
int dp[1010][15];

int f(int i, int j) {
	if(i == 1) return 1;

	auto &ret = dp[i][j];
	if(ret != -1) return ret;

	ret = 0;
	for(int k = j; k <= 9; ++k) {
		ret = (ret + f(i-1, k)) % MOD;
	}
	return ret;
}

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(dp, -1, sizeof(dp));

	cin>>N;
	for(int i = 0; i <= 9; ++i) {
		ans = (ans + f(N, i)) % MOD;
	}
	cout<<ans;

	return 0;
}