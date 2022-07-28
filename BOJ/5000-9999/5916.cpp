#include <bits/stdc++.h>

// 5916 농장 관리

// update 220728

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<long long, long long> pll;
typedef pair<int,int> pii;

const int INF = 1e9+5;
const long long llINF = 1e18;
const long long minllINF = -1e18;
const int minINF = -2e9-1;
const int MAX = 100005;
const long long MOD = 1e9+7;

int N, M, cnt;
int idx[MAX], depth[MAX], parent[MAX], subsize[MAX], chain[MAX];
bool visited[MAX];
vector<int> adj[MAX], child[MAX];
ll tree[4*MAX], lazy[4*MAX];

void makeTree(int cur) {
	for(auto &e : adj[cur]) {
		if(visited[e]) continue;
		visited[e] = true;
		child[cur].push_back(e);
		makeTree(e);
	}
}

int dfs(int cur) {
	subsize[cur] = 1;
	for(auto &e : child[cur]) {
		depth[e] = depth[cur] + 1;
		parent[e] = cur;
		subsize[cur] += dfs(e);
		if(subsize[e] > subsize[child[cur][0]]) swap(e, child[cur][0]);
	}
	return subsize[cur];
}

void hld(int cur) {
	idx[cur] = ++cnt;
	for(auto &e : child[cur]) {
		if(e == child[cur][0]) chain[e] = chain[cur];
		else chain[e] = e;
		hld(e);
	}
}

void propagate(int s, int e, int node) {
	if(lazy[node] != 0) {
		tree[node] += (e-s+1) * lazy[node];
		if(s != e) {
			lazy[node*2] += lazy[node];
			lazy[node*2+1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void upd(int s, int e, int node, int l, int r, ll k) {
	propagate(s, e, node);
	if(l > e || r < s) return;
	if(l <= s && r >= e) {
		lazy[node] += k;
		propagate(s, e, node);
		return;
	}
	int mid = (s+e)/2;
	upd(s, mid, node*2, l, r, k);
	upd(mid+1, e, node*2+1, l, r, k);
	tree[node] = tree[node*2] + tree[node*2+1];
}

ll qry(int s, int e, int node, int l, int r) {
	propagate(s, e, node);
	if(l > e || r < s) return 0;
	if(l <= s && r >= e) return tree[node];
	int mid = (s+e)/2;
	return qry(s, mid, node*2, l, r) + qry(mid+1, e, node*2+1, l, r);
}

void update(int a, int b) {
	while(chain[a] != chain[b]) {
		if(depth[chain[a]] < depth[chain[b]]) swap(a, b);
		upd(1, N, 1, idx[chain[a]], idx[a], 1);
		a = parent[chain[a]];
	}
	if(depth[a] > depth[b]) swap(a, b);
	upd(1, N, 1, idx[a]+1, idx[b], 1);
}

ll query(int a, int b) {
	ll ret = 0;
	while(chain[a] != chain[b]) {
		if(depth[chain[a]] < depth[chain[b]]) swap(a, b);
		ret += qry(1, N, 1, idx[chain[a]], idx[a]);
		a = parent[chain[a]];
	}
	if(depth[a] > depth[b]) swap(a, b);
	ret += qry(1, N, 1, idx[a]+1, idx[b]);
	return ret;
}

void input() {
	cin>>N>>M;
	for(int i = 1; i < N; ++i) {
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	chain[1] = 1;
	depth[1] = 0;
	visited[1] = true;
	makeTree(1), dfs(1), hld(1);
}

void solve() {
	while(M--) {
		char op;
		int u, v;
		cin>>op>>u>>v;
		if(op == 'P') {
			update(u, v);
		}
		else {
			cout<<query(u, v)<<'\n';
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}