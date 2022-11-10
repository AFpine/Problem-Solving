#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

// 15782

// 221110

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
const long long MOD = 1e9+7;
const int MAX = 101010;

int N, M, cnt, in[MAX], out[MAX];
vector<int> adj[MAX];
int tree[4*MAX], lazy[4*MAX];

void propagate(int s, int e, int node) {
	if(lazy[node]) {
		if((e-s+1) % 2) tree[node] ^= lazy[node];
 		if(s != e) {
			lazy[node*2] ^= lazy[node];
			lazy[node*2+1] ^= lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int s, int e, int node, int l, int r, int k) {
	propagate(s, e, node);
	if(l > e || r < s) return;
	if(l <= s && r >= e) {
		lazy[node] ^= k;
		propagate(s, e, node);
		return;
	}
	int mid = (s+e)/2;
	update(s, mid, node*2, l, r, k);
	update(mid+1, e, node*2+1, l, r, k);
	tree[node] = tree[node*2] ^ tree[node*2+1];
}

int query(int s, int e, int node, int l, int r) {
	propagate(s, e, node);
	if(l > e || r < s) return 0;
	if(l <= s && r >= e) return tree[node];
	int mid = (s+e)/2;
	return (query(s, mid, node*2, l, r) ^ query(mid+1, e, node*2+1, l, r));
}

void dfs(int v) {
	in[v] = ++cnt;
	for(auto &e : adj[v]) {
		if(!in[e]) dfs(e);
	}
	out[v] = cnt;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>M;
	for(int i = 1; i < N; ++i) {
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);

	for(int i = 1; i <= N; ++i) {
		int d;
		cin>>d;
		update(1, N, 1, in[i], in[i], d);
	}
	while(M--) {
		int op, x, y;
		cin>>op;
		if(op == 1) {
			cin>>x;
			cout<<query(1, N, 1, in[x], out[x])<<'\n';
		}
		else {
			cin>>x>>y;
			update(1, N, 1, in[x], out[x], y);
		}
	}

	return 0;
}