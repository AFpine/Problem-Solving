#pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
#define sz(a) (ll)(a.size()) 
#define all(a) (a).begin(), (a).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef pair<long double, long double> pdd;
typedef complex<double> cplx;

const int MAX = 101010;

ll N, K;
ll ans = -1;

bool bs(ll x) {
	ll cnt = 0;
	ll xcnt = 0;
	for(ll i = 1; i <= N; ++i) {
		ll d = min(i*N, x) / i;

		if(d < i) continue;
		cnt += (d - i + 1) * 2 - 1;

		if(((x / i) <= N) && ((x % i) == 0)) {
			if(i * i == x) xcnt += 1;
			else xcnt += 2;
		}
	}

	// cout<<x<<" "<<cnt<<" "<<xcnt<<"\n";

	if(cnt < K) return false;
	else {
		if((cnt >= K) && (cnt - xcnt < K)) ans = x;
		return true;
	}
}

void solve() {
	ll l = 1, r = N*N;
	while(l <= r) {
		ll mid = (l+r) / 2;
		if(bs(mid)) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}

	cout<<ans;
}

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>K;

	solve();
	
	return 0;
}