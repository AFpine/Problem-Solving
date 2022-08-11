#include <bits/stdc++.h>

// 3770 대한민국

// update 220811

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
const int MAX = 1005;

int N, M, K;
pii arr[400005];
ll tree[4*MAX];

void update(int s, int e, int node, int pos) {
	if(pos > e || pos < s) return;
	if(s == e) {
		tree[node] += 1;
		return;
	}
	int mid = (s+e)/2;
	update(s, mid, node*2, pos);
	update(mid+1, e, node*2+1, pos);
	tree[node] = tree[node*2] + tree[node*2+1];
}

ll query(int s, int e, int node, int l, int r) {
	if(l > e || r < s) return 0;
	if(l <= s && r >= e) return tree[node];
	int mid = (s+e)/2;
	return query(s, mid, node*2, l, r) + query(mid+1, e, node*2+1, l, r);
}

void init() {
	fill(tree, tree+4*MAX, 0);
}

void input() {
	cin>>N>>M>>K;
	for(int i = 1; i <= K; ++i) {
		cin>>arr[i].second>>arr[i].first;
	}
	sort(arr+1, arr+1+K);
}

void solve() {
	ll result = 0;
	for(int i = 1; i <= K; ++i) {
		result += query(1, 1000, 1, arr[i].second+1, 1000);
		update(1, 1000, 1, arr[i].second);
	}
	cout<<result<<'\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tt;
	cin>>tt;
	for(int t = 1; t <= tt; ++t) {
		cout<<"Test case "<<t<<": ";
		init();
		input();
		solve();
	}

	return 0;
}