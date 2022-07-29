#include <bits/stdc++.h>

// 16134 조합 (Combination)

// update 220729

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<long long, long long> pll;
typedef pair<int,int> pii;

const int INF = 1e9+5;
const long long llINF = 1e18;
const long long minllINF = -1e18;
const int minINF = -2e9-1;
const int MAX = 1000005;
const long long MOD = 1e9+7;

ll N, R;
ll fact[MAX];

void factorial(int N) {
	fact[0] = 1;
	for(int i = 1; i <= N; ++i) {
		fact[i] = (fact[i-1] * i) % MOD;
	}
}

ll exp(ll a, ll n) {
	if(n == 0) return 1;
	if(n == 1) return a;

	ll temp = exp(a, n/2);
	if(n % 2) {
		temp = (temp*temp) % MOD;
		return (temp*a) % MOD;
	}
	else {
		return (temp*temp) % MOD;
	}
}

void input() {
	cin>>N>>R;
	factorial(N);
}

void solve() {
	ll res = (fact[R] * fact[N-R]) % MOD;
	res = exp(res, MOD-2);
	res = (res * fact[N]) % MOD;
	cout<<res<<"\n";
}

int main() {
	ios_base::sync_with_stdio(false);	
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}