#include <bits/stdc++.h>

// 18437

// 221027

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
const int MAX = 101010;

int N, M, cnt, boss[MAX], in[MAX], out[MAX];
vector<int> adj[MAX];
int tree[4*MAX], lazy[4*MAX];

void propagate(int s, int e, int node) {
	if(lazy[node] != -1) {
		tree[node] = (lazy[node] * (e-s+1));
		if(s != e) {
			lazy[node*2] = lazy[node];
			lazy[node*2+1] = lazy[node];
		}
		lazy[node] = -1;
	}
}

void update(int s, int e, int node, int l, int r, int k) {
	propagate(s, e, node);
	if(l > e || r < s) return;
	if(l <= s && r >= e) {
		lazy[node] = k;
		propagate(s, e, node);
		return;
	}
	int mid = (s+e)/2;
	update(s, mid, node*2, l, r, k);
	update(mid+1, e, node*2+1, l, r, k);
	tree[node] = tree[node*2] + tree[node*2+1];
}

ll query(int s, int e, int node, int l, int r) {
	propagate(s, e, node);
	if(l > e || r < s) return 0;
	if(l <= s && r >= e) return tree[node];
	int mid = (s+e)/2;
	return query(s, mid, node*2, l, r) + query(mid+1, e, node*2+1, l, r);
}

void dfs(int v) {
	in[v] = ++cnt;
	for(auto &i : adj[v]) {
		if(!in[i]) dfs(i);
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

	cin>>N;
	for(int i = 1; i <= N; ++i) {
		cin>>boss[i];
		adj[boss[i]].push_back(i);
	}

	dfs(1);

	update(1, N, 1, in[1], out[1], 1);

	cin>>M;
	while(M--) {
		int op, i;
		cin>>op>>i;

		if(op == 1) {
			update(1, N, 1, in[i]+1, out[i], 1);
		}
		else if(op == 2) {
			update(1, N, 1, in[i]+1, out[i], 0);
		}
		else {
			cout<<query(1, N, 1, in[i]+1, out[i])<<'\n';
		}
		// cout<<'\n';
	}
	return 0;
}