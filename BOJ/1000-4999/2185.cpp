#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

// 2185

// 221101

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
const long long MOD = 1e9+7;
const int MAX = 20202;
const int D = 10005;

struct Line {
	int x, y1, y2, w;
};

int N;
ll tree[4*MAX], cnt[4*MAX];
vector<Line> row, col;
ll ans;

void update(int s, int e, int node, int l, int r, ll k) {
	if(l > e || r < s) return;
	if(l <= s && r >= e) cnt[node] += k;
	else {
		int mid = (s+e)/2;
		update(s, mid, node*2, l, r, k);
		update(mid+1, e, node*2+1, l, r, k);
	}
	if(cnt[node]) tree[node] = e-s+1;
	else {
		if(s == e) tree[node] = 0;
		else tree[node] = tree[node*2] + tree[node*2+1];
	}
}

void input() {
	cin>>N;
	for(int i = 1; i <= N; ++i) {
		int x1, x2, y1, y2;
		cin>>x1>>y1>>x2>>y2;
		if(x1 > x2) swap(x1, x2);
		if(y1 > y2) swap(y1, y2);
		row.push_back({y1+D, x1+D, x2+D-1, 1});
		row.push_back({y2+D, x1+D, x2+D-1, -1});
		col.push_back({x1+D, y1+D, y2+D-1, 1});
		col.push_back({x2+D, y1+D, y2+D-1, -1});
	}
	sort(all(row), [](Line a, Line b) {
		if(a.x ^ b.x) return a.x < b.x;
		return a.w > b.w;
	});
	sort(all(col), [](Line a, Line b) {
		if(a.x ^ b.x) return a.x < b.x;
		return a.w > b.w;
	});
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();

	ll t1 = 0;
	for(int i = 0; i < 2*N; ++i) {
		auto cur = row[i];

		update(0, MAX-1, 1, cur.y1, cur.y2, cur.w);
		ll t2 = tree[1];
		ans += abs(t2 - t1);

		t1 = t2;
	}

	fill(tree, tree+4*MAX, 0);
	fill(cnt, cnt+4*MAX, 0);

	t1 = 0;
	for(int i = 0; i < 2*N; ++i) {
		auto cur = col[i];

		update(0, MAX-1, 1, cur.y1, cur.y2, cur.w);
		ll t2 = tree[1];
		ans += abs(t2 - t1);

		t1 = t2;
	}

	cout<<ans;

	return 0;
}