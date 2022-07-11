#include <bits/stdc++.h>

// 15678 연세워터파크

// update 220711

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<long long, long long> pll;
typedef pair<int,int> pii;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 100005;
const long long MOD = 1e9+9;

int N, D;
ll arr[MAX], dp[MAX];
ll tree[MAX*4];

void update(int s, int e, int node, int pos, ll k) {
	if(s > pos || e < pos) return;
	if(s == e) {
		tree[node] = k;
		return;
	}
	int mid = (s+e)/2;
	update(s, mid, node*2, pos, k);
	update(mid+1, e, node*2+1, pos, k);

	tree[node] = max(tree[node*2], tree[node*2+1]);
}

ll query(int s, int e, int node, int l, int r) {
	if(l > e || r < s) return -llINF;
	if(l <= s && r >= e) return tree[node];
	int mid = (s+e)/2;
	return max(query(s, mid, node*2, l, r), query(mid+1, e, node*2+1, l, r));
}

void solve() {
	for(int i = 1; i <= N; ++i) {
		ll temp = query(1, N, 1, (i-D) >= 1 ? (i-D) : 1, i);
		dp[i] = arr[i] + temp;
		update(1, N, 1, i, dp[i]);
	}

	ll result = -llINF;
	for(int i = 1; i <= N; ++i) result = max(result, dp[i]);

	cout<<result;
}

void input() {
	cin>>N>>D;
	for(int i = 1; i <= N; ++i) cin>>arr[i];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}