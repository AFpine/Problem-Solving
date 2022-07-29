#include <bits/stdc++.h>

// 10327 피보나치 문제해결전략

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

int t;
ll N, D, S, T;
ll fibo[50];

ll xGCD(ll a, ll b, ll &x, ll &y) {
	if(b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	ll x1, y1;
	ll d = xGCD(b, a % b, x1, y1);
	x = y1;
	y = x1 - y1 * (a / b);
	return d;
}

void fib() {
	fibo[0] = fibo[1] = fibo[2] = 1;
	for(int i = 3; i <= 44; ++i) {
		fibo[i] = fibo[i-1] + fibo[i-2];
	}
}

void input() {
	cin>>N;
}

void solve() {
	pll res = {llINF, llINF};
	for(int i = 1; i <= 44; ++i) {
		S = 0;
		T = 0;
		D = xGCD(fibo[i], fibo[i-1], S, T);

		ll X = S * N / D, Y = T * N / D;

		//여기가 제일 어려움.. 범위 정하기
		ll l = ceil(-1.0*X/fibo[i-1]), r = floor(1.0*Y/fibo[i]);

		while(l <= r) {
			ll mid = (l+r)/2;
			if((X + mid*fibo[i-1]) < (Y - mid*fibo[i]) || (X + mid*fibo[i-1]) < 1 || (Y - mid*fibo[i]) < 1) l = mid + 1;
			else {
				if(res.first > (X + mid*fibo[i-1]) || ((res.first == (X + mid*fibo[i-1])) && (res.second > (Y - mid*fibo[i])))) {
					res.first = (X + mid*fibo[i-1]);
					res.second = (Y - mid*fibo[i]);
				}
				r = mid - 1;
			}
		}
	}
	cout<<res.second<<" "<<res.first<<'\n';
}

int main() {
	ios_base::sync_with_stdio(false);	
	cin.tie(NULL);
	cout.tie(NULL);

	fib();

	cin>>t;
	while(t--) {
		input();
		solve();
	}

	return 0;
}