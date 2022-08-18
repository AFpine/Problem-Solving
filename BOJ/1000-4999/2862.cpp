#include <bits/stdc++.h>
 
// 2862 수학 게임

// update 220818

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
const int MAX = 60005;

ll N;
vector<ll> fibo;

void fib() {
	fibo.push_back(1);
	fibo.push_back(1);
	while(true) {
		ll f1 = fibo.back();
		ll f2 = fibo[sz(fibo)-2];
		if(f1 + f2 > N) break;
		fibo.push_back(f1+f2);
	}
}

void input() {
	cin>>N;

	fib();
}

void solve() {
	ll res = N;
	while(true) {
		auto it = lower_bound(fibo.begin(), fibo.end(), res);
		if((*it) == res) break;
		res -= (*(prev(it)));
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