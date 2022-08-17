#include <bits/stdc++.h>
 
// 8986 전봇대

// update 220817

using namespace std;
#define sz(a) (int)(a.size()) 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef pair<long double, long double> pdd;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const long long MOD = 9999991;
const int MAX = 100005;

int N;
ll arr[MAX];

ll sum(ll k) {
	ll ret = 0;
	for(int i = 1; i < N; ++i) {
		ret += abs(arr[i] - k*i);
	}
	return ret;
}

void input() {
	cin>>N;
	for(int i = 0; i < N; ++i) cin>>arr[i];
}

void solve() {
	ll l = 0, r = arr[N-1];
	while((r-l) >= 3) {
		ll p = (2*l+r)/3, q = (l+2*r)/3;
		if(sum(p) > sum(q)) {
			l = p;
		}
		else {
			r = q;
		}
	}
	ll result = llINF;
	for(ll i = l; i <= r; ++i) {
		result = min(result, sum(i));
	}
	cout<<result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}