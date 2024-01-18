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

const int MAX = 202020;

int N, C;
ll arr[MAX];
ll ans = -1;

bool calc(ll x) {
	ll cnt = 1;
	ll prv = arr[1];
	for(int i = 2; i <= N; ++i) {
		if((arr[i] - prv) >= x) {
			cnt++;
			prv = arr[i];
		}
	}
	if(cnt >= C) return true;
	else return false;
}

void solve() {
	ll l = 0, r = 2000000000;
	while(l <= r) {
		ll mid = (l+r) / 2;
		if(calc(mid)) {
			ans = max(ans, mid);
			l = mid+1;
		}
		else r = mid-1;
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

	cin>>N>>C;
	for(int i = 1; i <= N; ++i) cin>>arr[i];

	sort(arr+1, arr+1+N);

	solve();

	return 0;
}