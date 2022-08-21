#include <bits/stdc++.h>
 
// 10978 기숙사 재배정

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
const long long MOD = 9999991;
const int MAX = 100005;

int N;
ll fact[25];
ll dp[25];

void factorial() {
	for(ll i = 2; i <= 21; ++i) {
		fact[i] = fact[i-1] * i;
	}
}

ll recur(int n) {
	if(n <= 1) return 0;
	if(n == 2) return 1;
	ll &ret = dp[n];
	if(ret != -1) return ret;

	return (n-1) * (recur(n-1) + recur(n-2));
}

void input() {
	memset(dp, -1, sizeof(dp));
	cin>>N;
}

void solve() {
	cout<<recur(N)<<'\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tt;
	cin>>tt;
	factorial();
	while(tt--) {
		input();
		solve();
	}

	return 0;
}