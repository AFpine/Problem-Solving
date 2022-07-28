#include <bits/stdc++.h>

// 13511 트리와 쿼리 2

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
int idx[MAX], depth[MAX], parent[MAX], subsize[MAX], chain[MAX], cost[MAX];
bool visited[MAX];
pii edge[MAX];
vector<int> adj[MAX], child[MAX];
ll tree[4*MAX];

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

void update(int s, int e, int node, int pos, ll k) {
	if(pos > e || pos < s) return;
	if(s == e) {
		tree[node] = k;
		return;
	}
	int mid = (s+e)/2;
	update(s, mid, node*2, pos, k);
	update(mid+1, e, node*2+1, pos, k);
	tree[node] = tree[node*2] + tree[node*2+1];
}

ll qry(int s, int e, int node, int l, int r) {
	if(l > e || r < s) return 0;
	if(l <= s && r >= e) return tree[node];
	int mid = (s+e)/2;
	return qry(s, mid, node*2, l, r) + qry(mid+1, e, node*2+1, l, r);
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

int getkth(int cur, int k) {
	if(k == 1) return cur;
	int temp = depth[cur] - depth[chain[cur]];
	if(temp == 0) {
		return getkth(parent[cur], k-1);
	}
	else if(k <= temp + 1) {
		k--;
		while(k--) cur = parent[cur];
		return cur;
	}
	else {
		return getkth(chain[cur], k - temp);
	}
}

int kthquery(int u, int v, int k) {
	int tempu = u, tempv = v;
	while(chain[tempu] != chain[tempv]) {
		if(depth[chain[tempu]] < depth[chain[tempv]]) tempv = parent[chain[tempv]];
		else tempu = parent[chain[tempu]];
	}
	int lca = (idx[tempu] < idx[tempv]) ? tempu : tempv;

	if(k <= depth[u] - depth[lca] + 1) {
		return getkth(u, k);
	}
	else {
		int temp = k - (depth[u] - depth[lca]);
		temp = (depth[v] - depth[lca] + 1) - temp;
		return getkth(v, temp + 1);
	}
}

void input() {
	cin>>N;
	for(int i = 1; i < N; ++i) {
		int u, v;
		cin>>u>>v>>cost[i];
		adj[u].push_back(v);
		adj[v].push_back(u);
		edge[i].first = u, edge[i].second = v;
	}

	chain[1] = 1;
	depth[1] = 0;
	visited[1] = true;
	makeTree(1), dfs(1), hld(1);

	for(int i = 1; i < N; ++i) {
		if(parent[edge[i].second] == edge[i].first) swap(edge[i].first, edge[i].second);
		update(1, N, 1, idx[edge[i].first], cost[i]);
	}
}

void solve() {
	cin>>M;
	while(M--) {
		int op;
		cin>>op;
		if(op == 1) {
			int u, v;
			cin>>u>>v;
			cout<<query(u, v)<<'\n';
		}
		else {
			int u, v, k;
			cin>>u>>v>>k;
			cout<<kthquery(u, v, k)<<'\n';
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