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

const int MAX = 131313;

struct D {
	int t;
	ll a, h;
};

int N;
ll A;
ll ans = 1000000000000000000;
D dungeon[MAX];

bool calc(ll x) {
	ll m, c, a;
	m = c = x;
	a = A;

	for(int i = 1; i <= N; ++i) {
		if(dungeon[i].t == 1) {
			ll turn = (dungeon[i].h / a) + ((dungeon[i].h % a) ? 1 : 0);
			c -= (dungeon[i].a) * (turn-1);
			if(c <= 0) return false;
		}
		else {
			a += dungeon[i].a;
			c = min(m, c + dungeon[i].h);
		}
	}
	return true;
}

void solve() {
	ll l = 0, r = ans;
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

	cin>>N>>A;

	for(int i = 1; i <= N; ++i) {
		cin>>dungeon[i].t>>dungeon[i].a>>dungeon[i].h;
	}

	solve();

	return 0;
}