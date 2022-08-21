#include <bits/stdc++.h>
 
// 14578 영훈이의 색칠공부

// update 220821

using namespace std;
#define sz(a) (int)(a.size()) 
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
const long long MOD = 1000000007;
const int MAX = 100005;

int N;
ll fact[MAX];
ll dp[MAX];

void factorial() {
	fact[1] = 1;
	for(ll i = 2; i <= N; ++i) {
		fact[i] = (fact[i-1] * i) % MOD;
	}
}

void recur(ll n) {
	dp[1] = 0;
	dp[2] = 1;
	for(ll i = 3; i <= N; ++i) {
		dp[i] = ((i-1) * (dp[i-1] + dp[i-2])) % MOD;
	}
}

void input() {
	fill(dp, dp+MAX, -1);
	cin>>N;
	factorial();
}

void solve() {
	recur(N);
	cout<<(fact[N] * dp[N]) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}