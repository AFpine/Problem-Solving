// #define LOCAL_TEST

#include <bits/stdc++.h>

// 23245 Similarity

// update 220905

using namespace std;
#define sz(a) (int)(a.size()) 
#define all(a) (a).begin(), (a).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef pair<long double, long double> pdd;
typedef complex<double> cplx;

const double PI = acos(-1);
const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const long long MOD = 1000000007;
const int MAX = 100005;
const int tMAX = 1000000;

int N;
pii pq[MAX];
ll tree[4*(tMAX+5)], cnt[MAX], psum[MAX];

void update(int s, int e, int node, int pos, ll k) {
	if(pos > e || pos < s) return;
	if(s == e) {
		tree[node] += k;
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

void input() {
	cin>>N;
	for(int i = 1; i <= N; ++i) cin>>pq[i].first;
	for(int i = 1; i <= N; ++i) cin>>pq[i].second;
}

void solve() {
	sort(pq+1, pq+1+N, [](pii a, pii b) {
		if(a.first == b.first) return a.second > b.second;
		return a.first < b.first;
	});

	cnt[0] = 0;
	for(int i = 1; i <= N; ++i) {
		cnt[i] = query(0, tMAX, 1, 0, pq[i].second - 1);
		update(0, tMAX, 1, pq[i].second, 1);
		psum[i] = psum[i-1] + cnt[i];
	}
	ll result = 0;
	memset(tree, 0, sizeof(tree));
	for(int i = 1; i <= N; ++i) {
		result += query(0, tMAX, 1, 0, pq[i].second - 1);
		update(0, tMAX, 1, pq[i].second, cnt[i]);
	}
	cout<<result;
}

int main() {

	#ifdef LOCAL_TEST
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cout<<fixed;
	cout.precision(6);

	input();
	solve();

	return 0;
}