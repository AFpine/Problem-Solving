#include <bits/stdc++.h>

// 7574 개구리

// update 220812

using namespace std;
#define sz(a) (int)(a.size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<long long, long long> pll;
typedef pair<double, double> pdd;
typedef pair<int,int> pii;

const int INF = 1e9+5;
const long long llINF = 1e18;
const long long minllINF = -1e18;
const int minINF = -2e9-1;
const long long MOD = 1000000007;
const int MAX = 300005;

struct Flower{
	int x, xpr, xmr, y, ypr, ymr, idx;
};

int N, R, D;
vector<int> xV, yV;
vector<Flower> fl;
vector<int> adj[MAX];
bool visited[MAX];
pii tree[4*MAX], xy[MAX];
int result, root;

void init() {
	fill(tree, tree+4*MAX, pii(-1, -1));
}

void xupdate(int s, int e, int node, int pos, Flower f) {
	if(pos > e || pos < s) return;
	if(s == e) {
		if(tree[node].first < f.x) {
			tree[node].first = f.x;
			tree[node].second = f.idx;
		}
		return;
	}
	int mid = (s+e)/2;
	xupdate(s, mid, node*2, pos, f);
	xupdate(mid+1, e, node*2+1, pos, f);
	if(tree[node*2].first < tree[node*2+1].first) tree[node] = tree[node*2+1];
	else tree[node] = tree[node*2];
}

void yupdate(int s, int e, int node, int pos, Flower f) {
	if(pos > e || pos < s) return;
	if(s == e) {
		if(tree[node].first < f.y) {
			tree[node].first = f.y;
			tree[node].second = f.idx;
		}
		return;
	}
	int mid = (s+e)/2;
	yupdate(s, mid, node*2, pos, f);
	yupdate(mid+1, e, node*2+1, pos, f);
	if(tree[node*2].first < tree[node*2+1].first) tree[node] = tree[node*2+1];
	else tree[node] = tree[node*2];
}

pii query(int s, int e, int node, int l, int r) {
	if(l > e || r < s) return pii(-1, -1);
	if(l <= s && r >= e) return tree[node];
	int mid = (s+e)/2;
	return max(query(s, mid, node*2, l, r), query(mid+1, e, node*2+1, l, r));
}

void input() {
	cin>>N>>R;
	for(int i = 1; i <= N; ++i) {
		int r, c;
		cin>>r>>c;
		fl.push_back({r, r+R, r-R, c, c+R, c-R, i-1});
		xV.push_back(r);
		xV.push_back(r+R);
		xV.push_back(r-R);
		yV.push_back(c);
		yV.push_back(c+R);
		yV.push_back(c-R);
		xy[i-1] = {r, c};
		if(r == 0 && c == 0) root = i-1;
	}
	cin>>D;
	sort(xV.begin(), xV.end());
	sort(yV.begin(), yV.end());
	xV.erase(unique(xV.begin(), xV.end()), xV.end());
	yV.erase(unique(yV.begin(), yV.end()), yV.end());
	for(auto &f : fl) {
		f.x = lower_bound(xV.begin(), xV.end(), f.x) - xV.begin();
		f.xpr = lower_bound(xV.begin(), xV.end(), f.xpr) - xV.begin();
		f.xmr = lower_bound(xV.begin(), xV.end(), f.xmr) - xV.begin();
		f.y = lower_bound(yV.begin(), yV.end(), f.y) - yV.begin();
		f.ypr = lower_bound(yV.begin(), yV.end(), f.ypr) - yV.begin();
		f.ymr = lower_bound(yV.begin(), yV.end(), f.ymr) - yV.begin();
	}
}

void dfs(int cur) {
	result = max(result, xy[cur].first+xy[cur].second+R+R);
	for(auto &e : adj[cur]) {
		if(visited[e]) continue;
		visited[e] = true;
		dfs(e);
	}
}

void solve() {
	sort(fl.begin(), fl.end(), [] (Flower a, Flower b) {
		if(a.x == b.x) return a.y < b.y;
		return a.x < b.x;
	});
	init();
	for(int i = 0; i < sz(fl); ++i) {
		auto f = fl[i];
		auto q1 = query(0, MAX-1, 1, f.ymr, f.y);
		auto q2	= query(0, MAX-1, 1, f.y+1, f.ypr);

		if(q1.first != -1 && xy[q1.second].first+R+D >= xy[f.idx].first) adj[q1.second].push_back(f.idx), adj[f.idx].push_back(q1.second);
		if(q2.first != -1 && xy[q2.second].first+R+D >= xy[f.idx].first) adj[q2.second].push_back(f.idx), adj[f.idx].push_back(q2.second);

		xupdate(0, MAX-1, 1, f.y, f);
	}

	sort(fl.begin(), fl.end(), [] (Flower a, Flower b) {
		if(a.y == b.y) return a.x < b.x;
		return a.y < b.y;
	});
	init();
	for(int i = 0; i < sz(fl); ++i) {
		auto f = fl[i];
		auto q1 = query(0, MAX-1, 1, f.xmr, f.x);
		auto q2	= query(0, MAX-1, 1, f.x+1, f.xpr);

		if(q1.first != -1 && xy[q1.second].second+R+D >= xy[f.idx].second) adj[q1.second].push_back(f.idx), adj[f.idx].push_back(q1.second);
		if(q2.first != -1 && xy[q2.second].second+R+D >= xy[f.idx].second) adj[q2.second].push_back(f.idx), adj[f.idx].push_back(q2.second);

		yupdate(0, MAX-1, 1, f.x, f);
	}

	visited[root] = true;
	dfs(root);

	cout<<result<<'\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}