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
const long long MOD = 1e7;
const int MAX = 10101010;

ll N, M;
vector<ll> ex10;

int length(ll i) {
	int ret = 0;
	while(i) {
		i /= 10;
		ret++;
	}
	return ret;
}

void solve(ll m) {
	pll prv;
	prv.first = 1;
	prv.second = 1;
	for(ll i = 2; i <= m; ++i) {
		ll cur = prv.first * i;
		int t1 = length(i);
		int t2 = length(prv.first);
		int t3 = length(cur);

		ll up = *(upper_bound(ex10.begin(), ex10.end(), cur));
		up /= 10LL;

		if(cur < 1e10) {
			prv.first = cur;
			prv.second = prv.second + t3 - t2;
		}
		else {
			prv.second = prv.second - 10 + t3;
			ll n = 0;
			for(int i = 1; i <= 10; ++i) {
				n = (cur / up);
				n *= 10LL;
				up /= 10LL;
			}
			n /= 10;
			prv.first = n;
		}
	}
	cout<<prv.second<<'\n';
}

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll t = 1;
	for(int i = 1; i <= 18; ++i) {
		t *= 10;
		ex10.push_back(t);
	}

	cin>>N;
	while(N--) {
		cin>>M;
		solve(M);
	}
	
	return 0;
}
