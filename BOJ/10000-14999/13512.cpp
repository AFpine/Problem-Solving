#include <bits/stdc++.h>
 
// 13512 트리와 쿼리 3

// update 220809

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

int N, M, cnt;
int parent[MAX], depth[MAX], top[MAX], in[MAX], out[MAX], subsz[MAX], inv[MAX];
bool visited[MAX];
vector<int> adj[MAX], child[MAX];
int tree[4*MAX];

void dfs1(int cur) {
	visited[cur] = true;
	for(auto &e : adj[cur]) {
		if(visited[e]) continue;
		visited[e] = true;
		child[cur].push_back(e);
		dfs1(e);
	}
}

void dfs2(int cur) {
	subsz[cur] = 1;
	for(auto &e : child[cur]) {
		depth[e] = depth[cur] + 1;
		parent[e] = cur;
		dfs2(e);
		subsz[cur] += subsz[e];
		if(subsz[e] > subsz[child[cur][0]]) swap(e, child[cur][0]);
	}
}

void hld(int cur) {
	in[cur] = ++cnt;
	inv[cnt] = cur;
	for(auto &e : child[cur]) {
		if(child[cur][0] == e) top[e] = top[cur];
		else top[e] = e;
		hld(e);
	}
	out[cur] = cnt;
}

void update(int s, int e, int node, int pos) {
	if(pos > e || pos < s) return;
	if(s == e) {
		tree[node] ^= 1;
		return;
	}
	int mid = (s+e)/2;
	update(s, mid, node*2, pos);
	update(mid+1, e, node*2+1, pos);
	tree[node] = tree[node*2] + tree[node*2+1];
}

int sum(int s, int e, int node, int l, int r) {
	if(l > e || r < s) return 0;
	if(l <= s && r >= e) return tree[node];
	int mid = (s+e)/2;
	return sum(s, mid, node*2, l, r) + sum(mid+1, e, node*2+1, l, r);
}

int query(int v) {
	int ret = -1;
	while(top[v] != top[1]) {
		int t = top[v];
		if(sum(1, N, 1, in[t], in[v]) > 0) {
			int l = in[t], r = in[v];
			while(l <= r) {
				int mid = (l+r)/2;
				if(sum(1, N, 1, in[t], mid) > 0) {
					ret = inv[mid];
					r = mid - 1;
				}
				else {
					l = mid + 1;
				}
			}
		}
		v = parent[t];
	}
	if(sum(1, N, 1, in[1], in[v]) > 0) {
		int l = in[1], r = in[v];
		while(l <= r) {
			int mid = (l+r)/2;
			if(sum(1, N, 1, in[1], mid) > 0) {
				ret = inv[mid];
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}
	}
	return ret;
}

void input() {
	cin>>N;
	for(int i = 1; i <= N-1; ++i) {
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

void solve() {
	top[1] = 1;
	dfs1(1);
	dfs2(1);
	hld(1);
	
	cin>>M;
	while(M--) {
		int op, q;
		cin>>op>>q;
		if(op == 1) {
			update(1, N, 1, in[q]);
		}
		else {
			cout<<query(q)<<'\n';
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