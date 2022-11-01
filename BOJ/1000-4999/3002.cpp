#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

// 3002

// 221031

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
const int MAX = 252525;

int N, M;
string S;
ll lazy[4*MAX];
vector<ll> tree[4*MAX];

ll calculate(vector<ll> &v) {
	ll ans = 0;
	for(int i = 0; i < 10; ++i) ans += i * v[i];
	return ans;
}

void propagate(int s, int e, int node) {
	if(lazy[node] != 0) {
		ll v = lazy[node];
		vector<ll> tmp(10);
		for(int i = 0; i < 10; ++i) tmp[(i+v)%10] = tree[node][i];
		for(int i = 0; i < 10; ++i) tree[node][i] = tmp[i];
		if(s != e) {
			lazy[node*2] += lazy[node];
			lazy[node*2+1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int s, int e, int node, int l, int r, ll k) {
	if(lazy[node] != 0) propagate(s, e, node);
	if(l > e || r < s) return;
	if(l <= s && r >= e) {
		lazy[node] += k;
		propagate(s, e, node);
		return;
	}
	int mid = (s+e)/2;
	update(s, mid, node*2, l, r, k);
	update(mid+1, e, node*2+1, l, r, k);
	for(int i = 0; i < 10; ++i) {
		tree[node][i] = tree[node*2][i] + tree[node*2+1][i];
	}
}

ll query(int s, int e, int node, int l, int r) {
	if(lazy[node] != 0) propagate(s, e, node);
	if(l > e || r < s) {
		return 0;
	}
	if(l <= s && r >= e) return calculate(tree[node]);
	int mid = (s+e)/2;
	return query(s, mid, node*2, l, r) + query(mid+1, e, node*2+1, l, r);
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for(int i = 0; i < 4*MAX; ++i) { tree[i].resize(10); tree[i][0] = 1; }
	cin>>N>>M;
	cin>>S;
	for(int i = 0; i < N; ++i) {
		update(1, N, 1, i+1, i+1, S[i]-'0');
	}

	while(M--) {
		int a, b;
		cin>>a>>b;

		ll ans = query(1, N, 1, a, b);
		cout<<ans<<'\n';
		update(1, N, 1, a, b, 1);
	}

	return 0;
}
