#include <bits/stdc++.h>

// 13172 ∑

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
const int MAX = 10005;
const long long MOD = 1e9+7;

int M;
pll dice[MAX];

ll exp(ll a, ll n) {
	if(n == 0) return 1;
	if(n == 1) return a;
	ll temp = exp(a, n/2);
	ll ret;
	if(n % 2) {
		ret = (temp * temp) % MOD;
		ret = (ret * a) % MOD;
		return ret;
	}
	else {
		ret = (temp * temp) % MOD;
		return ret;
	}
}

void input() {
	cin>>M;
	for(int i = 1; i <= M; ++i) {
		cin>>dice[i].first>>dice[i].second;
	}
}

void solve() {
	ll res = 0;
	for(int i = 1; i <= M; ++i) {
		ll temp = dice[i].second * exp(dice[i].first, MOD-2);
		res = (res + temp) % MOD;
	}
	cout<<res;
}

int main() {
	ios_base::sync_with_stdio(false);	
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}