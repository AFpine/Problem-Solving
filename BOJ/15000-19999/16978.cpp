#include <bits/stdc++.h>

// 16978 수열과 쿼리 22

// update 220714

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<long long, long long> pll;
typedef pair<int,int> pii;

const int INF = 1e9+5;
const long long llINF = 1e18;
const long long minllINF = -1e18;
const int minINF = -2e9-1;
const int MAX = 200005;
const long long MOD = 1e9+7;

int N, M, cnt;
ll arr[MAX], tree[4*MAX];
vector<pll> Q1;
vector<pair<pii, pii>> Q2;
ll result[MAX];

ll seginit(int s, int e, int node) {
	if(s == e) return tree[node] = arr[s];
	int mid = (s+e)/2;
	return tree[node] = seginit(s, mid, node*2) + seginit(mid+1, e, node*2+1);
}

void update(int s, int e, int node, int pos, ll k) {
	if(s > pos || e < pos) return;
	if(s == e) {
		tree[node] = k;
		return;
	}
	int mid = (s+e)/2;
	update(s, mid, node*2, pos, k);
	update(mid+1, e, node*2+1, pos, k);
	tree[node] = tree[node*2] + tree[node*2+1];
}

ll query(int s, int e, int node, int l, int r) {
	if(l > e || r < s) return 0;
	if(l <= s && r >= e) return tree[node];
	int mid = (s+e)/2;
	return query(s, mid, node*2, l, r) + query(mid+1, e, node*2+1, l, r);
}

void solve() {
	int idx = 0;
	cnt = 0;
	for(auto &q : Q1) {
		while(Q2[idx].first.second == cnt) {
			result[Q2[idx].first.first] = (query(1, N, 1, Q2[idx].second.first, Q2[idx].second.second));
			idx++;
		}
		cnt++;
		update(1, N, 1, q.first, q.second);
	}
	while(Q2[idx].first.second == cnt) {
		result[Q2[idx].first.first] = (query(1, N, 1, Q2[idx].second.first, Q2[idx].second.second));
		idx++;
	}

	for(int i = 1; i < MAX; ++i) {
		if(result[i] < 0) continue;
		cout<<result[i]<<'\n';
	}
}

void input() {
	cin>>N;
	for(int i = 1; i <= N; ++i) cin>>arr[i];
	seginit(1, N, 1);

	cin>>M;
	while(M--) {
		int op;
		cin>>op;
		if(op == 1) {
			ll i, v;
			cin>>i>>v;
			Q1.push_back({i, v});
		}
		else {
			int k, i, j;
			cin>>k>>i>>j;
			Q2.push_back({{++cnt, k}, {i, j}});
		}
	}
	sort(Q2.begin(), Q2.end(), [] (pair<pii,pii> a, pair<pii,pii> b) {
		return a.first.second < b.first.second;
	});
	fill(result, result+MAX, -1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	input();
	solve();

	return 0;
}