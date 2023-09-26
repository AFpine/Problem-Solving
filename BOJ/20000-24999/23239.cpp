#pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

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
const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const long long MOD = 1e9+7;
const int MAX = 2020;

ll w, h, L;
ll result = 0;

ll f(ll R) {
	if(R < 0) return 0;
	ll ret = 0;
	for(ll i = 1; i < R; ++i) {
		ll t = 0;
		ll l = 0, r = R;
		while(l <= r) {
			ll m = (l+r)/2LL;
			if((i*i) + (m*m) <= R*R) {
				t = m;
				l = m + 1;
			}
			else r = m - 1;
		}
		ret += t;
	}
	return ret;
}

ll f2(ll w, ll h) {
	ll ret = 0;
	for(ll i = 1; i < L-w; ++i) {
		ll t = h;
		ll l = h, r = L-w;
		while(l <= r) {
			ll m = (l+r)/2LL;
			if(((i*i) + (m*m) <= ((L-w)*(L-w))) && (((i+w)*(i+w)) + ((m-h)*(m-h)) <= ((L-h)*(L-h)))) {
				t = m;
				l = m + 1;
			}
			else r = m - 1;
		}
		ret += (t - h);
	}
	return ret;
} 

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>w>>h>>L;
	
	result += f(L) * 3LL;
	result += L * 2LL;

	result += f(L-h);
	result += f(L-w);
	if(L-h > 0) result += L-h;
	if(L-w > 0) result += L-w;

	if(L-h > w && L-w > h) result -= f2(w, h);

	cout<<result;

	return 0;
}
