#include <bits/stdc++.h>

// 7469 K번째 수

// update 220712

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<long long, long long> pll;
typedef pair<int,int> pii;

const int INF = 1e9+5;
const long long llINF = 1e18;
const long long minllINF = -1e18;
const int minINF = -2e9-1;
const int MAX = 300005;
const long long MOD = 1e9+7;

int N, Q;
int arr[MAX];
vector<int> tree[4*MAX];

void seginit(int s, int e, int node) {
	if(s == e) {
		tree[node].push_back(arr[s]);
		return;
	}
	int mid = (s+e) / 2;

	seginit(s, mid, node*2);
	seginit(mid+1, e, node*2+1);

	tree[node].resize(tree[node*2].size() + tree[node*2+1].size());

	merge(tree[node*2].begin(), tree[node*2].end(), tree[node*2+1].begin(), tree[node*2+1].end(), tree[node].begin());
}

int query(int s, int e, int node, int l, int r, int k) {
	if(l > e || r < s) return 0;
	if(l <= s && r >= e) {
		//자신보다 작거나 같은 값의 수
		return upper_bound(tree[node].begin(), tree[node].end(), k) - tree[node].begin();
	}
	int mid = (s+e) / 2;

	return query(s, mid, node*2, l, r, k) + query(mid+1, e, node*2+1, l, r, k);
}

void solve() {
	while(Q--) {
		int i, j, k;
		cin>>i>>j>>k;

		int l = -1e9, r = 1e9;

		int result = -1;
		while(l <= r) {
			int mid = (l+r) / 2;
			int temp = query(1, N, 1, i, j, mid);

			if(temp < k) l = mid+1;
			else r = mid-1;
		}
		cout<<l<<'\n';
	}
}

void input() {
	cin>>N>>Q;
	for(int i = 1; i <= N; ++i) cin>>arr[i];
	seginit(1, N, 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}