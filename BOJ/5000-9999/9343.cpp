#include <bits/stdc++.h>
 
// 9343 랜덤 걷기

// update 220722

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef pair<long double, long double> pdd;
 
const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const long long MOD = 1e9+7;
const int MAX = 2000000;

int T;
ll fact[MAX+5];

void getFact() {
	fact[1] = 1;
	for(int i = 2; i <= MAX; ++i) {
		fact[i] = (i * fact[i-1]) % MOD;
	}
}

void input() {
	getFact();
	cin>>T;
}

ll exp(ll val, ll k) {
	if(k == 0) return 1;
	if(k == 1) return val;
	
	ll temp = exp(val, k/2);
	if(k % 2) {
		temp *= temp;
		temp %= MOD;
		temp *= val;
		temp %= MOD;
		return temp;
	}
	else {
		temp = exp(val, k/2);
		temp *= temp;
		temp %= MOD;
		return temp;
	}
}

void solve() {
	int n;
	ll result;
	while(T--) {
		cin>>n;
		ll up = fact[2*n];
		ll down = fact[n+1];
		down *= fact[n];
		down %= MOD;
		
		result = up * exp(down, MOD-2);

		cout<<result%MOD<<'\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	input();
	solve();
 
	return 0;
}