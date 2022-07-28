#include <bits/stdc++.h>

// 13510 트리와 쿼리 1

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

int N, M, pv;
int depth[MAX], top[MAX], parent[MAX], subsize[MAX], in[MAX], cost[MAX];
bool visited[MAX];
pair<int, pii> edge[MAX];
vector<int> adj[MAX];
vector<int> child[MAX];

int tree[4*MAX];

void makeTree(int cur) {
	visited[cur] = true;
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

void HLD(int cur) {
	in[cur] = ++pv;
	for(auto &e : child[cur]) {
		top[e] = (e == child[cur][0]) ? top[cur] : e;
		HLD(e);
	}
}


void update(int s, int e, int node, int pos, int k) {
	if(pos > e || pos < s) return;
	if(s == e) {
		tree[node] = k;
		return;
	}
	int mid = (s+e)/2;
	update(s, mid, node*2, pos, k);
	update(mid+1, e, node*2+1, pos, k);
	tree[node] = max(tree[node*2], tree[node*2+1]);
}

int query(int s, int e, int node, int l, int r) {
	if(l > e || r < s) return 0;
	if(l <= s && r >= e) return tree[node];
	int mid = (s+e)/2;
	return max(query(s, mid, node*2, l, r), query(mid+1, e, node*2+1, l, r));
}

int query2(int a, int b) {
	int ret = 0;
	while(top[a] != top[b]) {	//같은 chain에 속한 정점이 아니라면
		if(depth[top[a]] < depth[top[b]]) swap(a, b);
		ret = max(ret, query(1, N, 1, in[top[a]], in[a]));
		a = parent[top[a]];
	}
	// a, b가 같은 chain에 속해있다
	if(depth[a] > depth[b]) swap(a, b);
	ret = max(ret, query(1, N, 1, in[a]+1, in[b]));
	return ret;
}

void input() {
	cin>>N;
	for(int i = 1; i < N; ++i) {
		cin>>edge[i].second.first>>edge[i].second.second>>edge[i].first;
		adj[edge[i].second.first].push_back(edge[i].second.second);
		adj[edge[i].second.second].push_back(edge[i].second.first);
	}
	cost[1] = 0;
	depth[1] = 0;
	visited[1] = true;

	makeTree(1);
	dfs(1);
	HLD(1);

	for(int i = 1; i < N; ++i) {
		if(parent[edge[i].second.second] == edge[i].second.first) swap(edge[i].second.first, edge[i].second.second);
		update(1, N, 1, in[edge[i].second.first], edge[i].first);
	}
}

void solve() {
	cin>>M;
	while(M--) {
		int op, a, b;
		cin>>op>>a>>b;
		
		if(op == 1) {
			update(1, N, 1, in[edge[a].second.first], b);
		}
		else {
			cout<<query2(a, b)<<'\n';
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