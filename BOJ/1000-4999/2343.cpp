#pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
#define sz(a) (ll)(a.size()) 
#define all(a) (a).begin(), (a).end()
typedef unsigned long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef pair<long double, long double> pdd;
typedef complex<double> cplx;

int N, M;
ll arr[101010];
ll ans = 2000000000;

bool calc(ll x) {
	ll cur = 0;
	ll cnt = 1;
	for(int i = 1; i <= N; ++i) {
		if(arr[i] > x) return false;
		if((cur + arr[i]) > x) {
			cnt++;
			cur = arr[i];
		}
		else cur += arr[i];
	}
	if(cnt <= M) return true;
	else return false;
}

void solve() {
	ll l = 1, r = ans;
	while(l <= r) {
		ll mid = (l+r) / 2;
		if(calc(mid)) {
			ans = min(ans, mid);
			r = mid-1;
		}
		else l = mid+1;
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

	cin>>N>>M;
	for(int i = 1; i <= N; ++i) cin>>arr[i];

	solve();

	return 0;
}