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

const int MAX = 1010101;

struct ABC {
	ll A, B, C;
};

ll N, K, D;
ABC abc[10101];
ll ans = -1;

bool dotory(ll x) {
	ll xcnt = 0;
	ll cnt = 0;
	for(int i = 1; i <= K; ++i) {
		if(abc[i].A > x) continue;
		cnt += (min(abc[i].B, x) - abc[i].A) / abc[i].C + 1;
		if((x <= abc[i].B) && ((x - abc[i].A) % abc[i].C == 0)) xcnt++;
	}
	if((cnt >= D) && ((cnt - xcnt) < D)) ans = x;
	if(cnt >= D) return true;
	else return false;
}

void solve() {
	ll l = 1, r = N;
	while(l <= r) {
		int mid = (l+r)/2;
		if(dotory(mid)) r = mid - 1;
		else l = mid + 1;
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

	cin>>N>>K>>D;

	for(int i = 1; i <= K; ++i) cin>>abc[i].A>>abc[i].B>>abc[i].C;

	solve();

	return 0;
}