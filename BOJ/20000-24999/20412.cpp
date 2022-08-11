#include <bits/stdc++.h>

// 20412 추첨상 사수 대작전! (Hard)

// update 220811

using namespace std;
#define sz(a) (int)(a.size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<long long, long long> pll;
typedef pair<double, double> pdd;
typedef pair<int,int> pii;

const int INF = 1e9+5;
const long long llINF = 1e18;
const long long minllINF = -1e18;
const int minINF = -2e9-1;
const long long MOD = 1000000007;
const int MAX = 20005;

ll X1, X2, S, M;

ll _MOD(ll x, ll m) {
	return (x % m) >= 0 ? (x % m) : ((x+m) % m);
}

ll POW(ll x, ll n) {
	if(n == 0) return 1;
	if(n == 1) return x;
	ll t = POW(x, n/2);
	if(n % 2) {
		t = _MOD((t*t), M);
		return _MOD((t*x), M);
	}
	else return _MOD((t*t), M);
}

void input() {
	cin>>M>>S>>X1>>X2;
}

void solve() {
	ll a = _MOD(_MOD((X1 - X2), M) * POW(_MOD((S-X1), M), M-2), M);
	ll c = _MOD((X1 - _MOD(a*S, M)), M);
	cout<<a<<" "<<c;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}