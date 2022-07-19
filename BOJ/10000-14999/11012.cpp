#include <bits/stdc++.h>

// 11012 Egg

// update 220719

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<long long, long long> pll;
typedef pair<int,int> pii;

const int INF = 1e9+5;
const long long llINF = 1e18;
const long long minllINF = -1e18;
const int minINF = -2e9-1;
const int MAX = 200010;
const long long MOD = 1e9+7;

struct Node {
	ll val {0} ;
	Node *l {nullptr}, *r {nullptr};
};

int T, N, M;
pii point[MAX/10];
int idx[MAX];
pair<pii, pii> qry[MAX/4];

void seginit(int s, int e, Node* tree) {
	if(s == e) {
		tree->val = 0;
		return;
	}
	int mid = (s+e)/2;
	tree->l = new Node();
	tree->r = new Node();
	seginit(s, mid, tree->l);
	seginit(mid+1, e, tree->r);
	tree->val = tree->l->val + tree->r->val;
}

void update(int s, int e, Node* prv, Node* tree, int pos, ll x) {
	if(s > pos || e < pos) return;
	if(s == e) {
		tree->val = prv->val + x;
		return;
	}
	int mid = (s+e)/2;
	if(pos <= mid) {
		tree->l = new Node();
		tree->r = prv->r;
		update(s, mid, prv->l, tree->l, pos, x);
	}
	else {
		tree->r = new Node();
		tree->l = prv->l;
		update(mid+1, e, prv->r, tree->r, pos, x);
	}
	tree->val = tree->l->val + tree->r->val;
}

ll query(int s, int e, Node* tree, int l, int r) {
	if(l > e || r < s) return 0;
	if(l <= s && r >= e) return tree->val;
	int mid = (s+e)/2;
	return query(s, mid, tree->l, l, r) + query(mid+1, e, tree->r, l, r);
}

void init() {
	fill(idx, idx+MAX, -1);
}

void input() {
	cin>>N>>M;
	vector<int> tempV;
	tempV.push_back(-1);

	for(int i = 1; i <= N; ++i) {
		cin>>point[i].first>>point[i].second;
		tempV.push_back(point[i].second);
	}
	for(int i = 1; i <= M; ++i) {
		cin>>qry[i].first.first>>qry[i].first.second>>qry[i].second.first>>qry[i].second.second;
		tempV.push_back(qry[i].second.first);
		tempV.push_back(qry[i].second.second);
	}
	sort(tempV.begin(), tempV.end());
	tempV.erase(unique(tempV.begin(), tempV.end()), tempV.end());

	for(int i = 1; i <= N; ++i) {
		point[i].second = lower_bound(tempV.begin(), tempV.end(), point[i].second) - tempV.begin();
	}
	for(int i = 1; i <= M; ++i) {
		qry[i].second.first = lower_bound(tempV.begin(), tempV.end(), qry[i].second.first) - tempV.begin();
		qry[i].second.second = lower_bound(tempV.begin(), tempV.end(), qry[i].second.second) - tempV.begin();
	}
	sort(point+1, point+1+N, [] (pii a, pii b) {
		return a.second < b.second;
	});
}

void solve() {
	vector<Node*> tree(MAX, nullptr);
	tree[0] = new Node();
	seginit(0, 100000, tree[0]);
	idx[0] = 0;

	for(int i = 1; i <= N; ++i) {
		tree[i] = new Node();
		idx[point[i].second] = i;
		update(0, 100000, tree[i-1], tree[i], point[i].first, 1);
	}
	for(int i = 0; i < MAX-1; ++i) {
		if(idx[i+1] == -1) idx[i+1] = idx[i];
	}

	ll result = 0;
	for(int i = 1; i <= M; ++i) {
		int t = idx[qry[i].second.second];
		int b = idx[qry[i].second.first-1];
		if(b == 0) {
			result += query(0, 100000, tree[t], qry[i].first.first, qry[i].first.second);
		}
		else {
			result += (query(0, 100000, tree[t], qry[i].first.first, qry[i].first.second) - query(0, 100000, tree[b], qry[i].first.first, qry[i].first.second));
		}
	}
	cout<<result<<'\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>T;
	while(T--) {
		init();
		input();
		solve();
	}

	return 0;
}