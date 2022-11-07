#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

// 20175

// 221107

using namespace std;
#define sz(a) (int)(a.size()) 
#define all(a) (a).begin(), (a).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef pair<long double, long double> pdd;
typedef complex<double> cplx;

const double PI = acos(-1);
const int INF = 1e9+7;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const long long MOD = 1e9+7;
const int MAX = 1010101;

int N;
ll d, a[MAX];

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>d;
	d *= 2LL;
	for(int i = 1; i <= N; ++i) { cin>>a[i]; a[i] *= 2LL; }
	
	ll mx = -llINF, mn = llINF;
	ll ans = llINF;
	for(int i = 1; i <= N; ++i) {
		mx = max(mx, a[i] - (1LL*(i-1))*d);
		mn = min(mn, a[i] - (1LL*(i-1))*d);
	}
	ans = min(ans, (abs(mx - mn))/2);

	mx = -llINF, mn = llINF;
	for(int i = 1; i <= N; ++i) {
		mx = max(mx, a[i] + (1LL*(i-1))*d);
		mn = min(mn, a[i] + (1LL*(i-1))*d);
	}
	ans = min(ans, (abs(mx - mn))/2);

	if(ans % 2) cout<<ans/2<<".5";
	else cout<<ans/2<<".0";

	return 0;
}
