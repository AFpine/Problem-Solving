#include <bits/stdc++.h>

// 11635 Wipe Your Whiteboards

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

int T;
ll A, B, R, S, Q, D;

ll xGCD(ll a, ll b, ll &x, ll &y) {
	if(b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	ll x1, y1;
	ll d = xGCD(b, a%b, x1, y1);
	x = y1;
	y = x1 - y1 * (a/b);
	return d;
}

void input() {
	A = B = 0;
	cin>>R>>S>>Q;
}

void solve() {
	ll tempA, tempB, prvA, prvB;
	D = xGCD(R, S, A, B);
	A = A * Q / D;
	B = B * Q / D;

	ll res = 0;
	if(D > 0) {
		// k가 증가할수록 x,y가 줄어든다
		ll l = -INF, r = INF;
		while(l <= r) {
			ll mid = (l+r)/2;
			if((A + mid*S/D) >= 1 && (B - mid*R/D) >= 1) res = mid, l = mid + 1;
			else r = mid - 1;
		}
	}
	else {
		// k가 증가할수록 x,y가 늘어난다
		ll l = -INF, r = INF;
		while(l <= r) {
			ll mid = (l+r)/2;
			if((A + mid*S/D) >= 1 && (B - mid*R/D) >= 1) res = mid, r = mid - 1;
			else l = mid + 1;
		}
	}

	cout<<(A + res*S/D)<<" "<<(B - res*R/D)<<'\n';
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