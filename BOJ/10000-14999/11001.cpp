#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

// 11001

// 221115

using namespace std;
#define sz(a) (int)(a.size()) 
#define all(a) (a).begin(), (a).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef pair<long double, long double> pdd;
typedef complex<double> base;

const double PI = acos(-1);
const int INF = 1e9+7;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const ll MOD = 1e9+7;
const int MAX = 101010;

int N, D;
ll T[MAX], V[MAX];
ll ans;

void f(int s, int e, int is, int ie) {
	int mid = (s+e)/2;
	ll tmp = 0;
	int idx = 0;

	int lo = max(is, mid), hi = min(mid+D, ie);
	// int lo = mid, hi = ie;

	for(int i = lo; i <= hi; ++i) {
		if((i-mid) <= D && 1LL*(i-mid)*T[i]+V[mid] > tmp) {
			tmp = 1LL*(i-mid)*T[i]+V[mid];
			idx = i;
		}
	}
	ans = max(ans, tmp);
	if(s != mid) f(s, mid-1, is, idx);
	if(e != mid) f(mid+1, e, idx, ie);
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>D;
	for(int i = 1; i <= N; ++i) cin>>T[i];
	for(int i = 1; i <= N; ++i) cin>>V[i];

	f(1, N, 1, N);

	cout<<ans;

	return 0;
}