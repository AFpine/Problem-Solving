// #pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
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
const long long MOD = 1e9 + 7;
const int MAX = 101010;

ll N, K;
ll arr[MAX];
ll cnt[MAX];
ll dp[MAX];

ll power2(ll n) {
	ll ret = 1;
	while(n--) {
		ret = (ret * 2) % MOD;
	}
	return ret;
}

ll f(int n) {
	if(n == 0) return (cnt[0] + 1);

	auto ret = dp[n];
	if(ret != -1) return ret;

	ret = 0;
	if(K-n == n) {
		ret = (ret + (cnt[n] + 1) * f(n-1)) % MOD;
	}
	else {
		ret = (ret + (power2(cnt[n]) + power2(cnt[K-n]) - 1) * f(n-1)) % MOD;
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

	cin>>N>>K;
	for(int i = 1; i <= N; ++i) {
		cin>>arr[i];
		cnt[arr[i] % K]++;
	}

	ll result = f(K/2);

	result = (result + MOD - (N+1)) % MOD;

	cout<<result;

	return 0;
}
