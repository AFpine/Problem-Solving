#include <bits/stdc++.h>

// 3955 캔디 분배

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
const int MAX = 100005;
const long long MOD = 1e9+7;

ll T, K, C;
ll x, y;

ll xGCD(int a, int b) {
	ll s = 0, old_s = 1, t = 1, old_t = 0, r = b, old_r = a;
	while(r) {
		ll temp;
		ll q = old_r / r;
		temp = old_r;
		old_r = r;
		r = temp - q * r;
		temp = old_s;
		old_s = s;
		s = temp - q * s;
		temp = old_t;
		old_t = t;
		t = temp - q * t;
	}
	x = old_s;
	y = old_t;
	return old_r;
}

void input() {
	cin>>K>>C;
}

void solve() {
	if(K == 1 && C == 1) {
		cout<<"2\n";
		return;
	}
	else if(C == 1) {
		if(K+1 > 1e9) cout<<"IMPOSSIBLE\n";
		else cout<<K+1<<'\n';
		return;
	}
	else if(K == 1) {
		cout<<"1\n";
		return;
	}

	if(xGCD(C, K) != 1) {
		cout<<"IMPOSSIBLE\n";
	}
	else {
		while(x <= 0) x = (x+K) % K;
		if(x > 1e9) cout<<"IMPOSSIBLE\n";
		else cout<<x<<'\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);	
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>T;
	while(T--) {
		input();
		solve();
	}

	return 0;
}