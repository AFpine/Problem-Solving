#include <bits/stdc++.h>

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
const long long MOD = 1e9+9;
const int MAX = 1010101;

int N;
ll K;
ll dp[5][2][MAX];

ll f(int cnt, int c, int len) {
	if(len == N) return 1LL;

	auto &ret = dp[cnt][c][len];
	if(ret != -1) return ret;
	
	ret = 0;
	if(cnt == 0) {
		ret = (ret + f(1, 0, len+1)) % MOD;
		ret = (ret + f(0, 0, len+1) * (K-1LL)) % MOD;
	}
	else if(cnt == 1) {
		ret = (ret + f(2, 0, len+1)) % MOD;
		ret = (ret + f(1, 0, len+1)) % MOD;
		ret = (ret + f(0, 0, len+1) * (K-2LL)) % MOD;
	}
	else if(cnt == 2) {
		ret = (ret + f(3, 0, len+1)) % MOD;
		ret = (ret + f(3, 1, len+1)) % MOD;
		ret = (ret + f(0, 0, len+1) * (K-2LL)) % MOD;
	}
	else if(cnt == 3) {
		ret = (ret + f(4, c, len+1)) % MOD;
		ret = (ret + f(1, 0, len+1)) % MOD;
		ret = (ret + f(0, 0, len+1) * (K-2LL)) % MOD;
	}
	else {
		if(c == 1) {
			ret = (ret + f(1, 0, len+1)) % MOD;
			ret = (ret + f(0, 0, len+1) * (K-2LL)) % MOD;
		}
		else {
			ret = (ret + f(3, 0, len+1)) % MOD;
			ret = (ret + f(0, 0, len+1) * (K-2LL)) % MOD;
		}
	}

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

	memset(dp, -1, sizeof(dp));

	cin>>N>>K;

	cout<<f(0, 0, 0);

	return 0;
}