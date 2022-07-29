#include <bits/stdc++.h>

// 14565 역원(Inverse) 구하기

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

ll N, A;
ll x, y;

ll xGCD(ll a, ll b) {
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
	cin>>N>>A;
}

void solve() {
	ll res1 = (N-A) % N;
	res1 = (res1+N) % N;
	
	ll res2;
	if(xGCD(A, N) != 1) res2 = -1;
	else {
		x = (x+N) % N;
		res2 = x;
	}

	cout<<res1<<" "<<res2<<'\n';
}

int main() {
	ios_base::sync_with_stdio(false);	
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}