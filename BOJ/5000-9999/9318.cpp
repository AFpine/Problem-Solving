#include <bits/stdc++.h>
 
// 9318 위성 사진

// update 220811

using namespace std;
#define sz(a) (int)(a.size()) 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef pair<long double, long double> pdd;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const long long MOD = 9999991;
const int MAX = 1000005;

struct Line {
	int x, y1, y2, w; 
};

int N;
vector<Line> line;
ll tree[4*MAX], lenTree[4*MAX];

void update(int s, int e, int node, int l, int r, int k) {
	if(l > e || r < s) return;
	if(l <= s && r >= e) {
		tree[node] += k;
	}
	else {
		int mid = (s+e)/2;
		update(s, mid, node*2, l, r, k);
		update(mid+1, e, node*2+1, l, r, k);
	}
	if(tree[node]) lenTree[node] = e-s+1;
	else {
		if(s == e) lenTree[node] = 0;
		else lenTree[node] = lenTree[node*2] + lenTree[node*2+1];
	}
}

ll sum(int s, int e, int node, int l, int r) {
	if(l > e || r < s) return 0;
	if(l <= s && r >= e) return lenTree[node];
	int mid = (s+e)/2;
	return sum(s, mid, node*2, l, r) + sum(mid+1, e, node*2+1, l, r);
}

void init() {
	line.clear();
	fill(tree, tree+4*MAX, 0);
	fill(lenTree, lenTree+4*MAX, 0);
}

void input() {
	cin>>N;
	for(int i = 1; i <= N; ++i) {
		int x1, y1, x2, y2;
		cin>>x1>>y1>>x2>>y2;
		line.push_back({x1, y1, y2-1, 1});
		line.push_back({x2, y1, y2-1, -1});
	}
	sort(line.begin(), line.end(), [] (Line a, Line b) {
		if(a.x == b.x) return a.y1 < b.y1;
		return a.x < b.x;
	});
}

void solve() {
	ll result = 0;
	update(0, 1000000, 1, line[0].y1, line[0].y2, line[0].w);
	int prv = line[0].x;
	for(int i = 1; i < sz(line); ++i) {
		auto l = line[i];
		int cur = l.x;
		result += 1LL*(cur-prv)*sum(0, 1000000, 1, 0, 1000000);
		update(0, 1000000, 1, l.y1, l.y2, l.w);
		prv = cur;
		// cout<<result<<'\n';
	}
	cout<<result<<"\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tt;
	cin>>tt;
	while(tt--) {
		init();
		input();
		solve();
	}

	return 0;
}