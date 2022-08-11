#include <bits/stdc++.h>

// 5480 전함

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
const int MAX = 300005;

struct BS {
	int x1, x2, y1, y2, w;
};

int N, K, I;
vector<BS> bs;
vector<int> xV, yV;
vector<pii> laser;
int result[MAX];
int xtree[4*MAX], ytree[4*MAX];

void xupdate(int s, int e, int node, int pos, int k) {
	if(pos > e || pos < s) return;
	if(s == e) {
		xtree[node] = min(xtree[node], k);
		return;
	}
	int mid = (s+e)/2;
	xupdate(s, mid, node*2, pos, k);
	xupdate(mid+1, e, node*2+1, pos, k);
	xtree[node] = min(xtree[node*2], xtree[node*2+1]);
}

int xquery(int s, int e, int node, int l, int r) {
	if(l > e || r < s) return INF;
	if(l <= s && r >= e) return xtree[node];
	int mid = (s+e)/2;
	return min(xquery(s, mid, node*2, l, r), xquery(mid+1, e, node*2+1, l, r));
}

void yupdate(int s, int e, int node, int pos, int k) {
	if(pos > e || pos < s) return;
	if(s == e) {
		ytree[node] = min(ytree[node], k);
		return;
	}
	int mid = (s+e)/2;
	yupdate(s, mid, node*2, pos, k);
	yupdate(mid+1, e, node*2+1, pos, k);
	ytree[node] = min(ytree[node*2], ytree[node*2+1]);
}

int yquery(int s, int e, int node, int l, int r) {
	if(l > e || r < s) return INF;
	if(l <= s && r >= e) return ytree[node];
	int mid = (s+e)/2;
	return min(yquery(s, mid, node*2, l, r), yquery(mid+1, e, node*2+1, l, r));
}

void init() {
	xV.clear();
	yV.clear();
	bs.clear();
	laser.clear();
	fill(xtree, xtree+4*MAX, INF);
	fill(ytree, ytree+4*MAX, INF);
	fill(result, result+MAX, 0);
}

void input() {
	cin>>N>>K>>I;
	for(int i = 1; i <= K; ++i) {
		int x1, x2, y1, y2, w;
		cin>>x1>>y1>>x2>>y2>>w;
		bs.push_back({min(x1, x2), max(x1, x2), min(y1, y2), max(y1, y2), w});
		xV.push_back(x1);
		xV.push_back(x2);
		yV.push_back(y1);
		yV.push_back(y2);
	}
	for(int i = 1; i <= I; ++i) {
		int a, b;
		cin>>a>>b;
		laser.push_back({a, b});
		if(b == 0) yV.push_back(a);
		else xV.push_back(a);
	}
	sort(xV.begin(), xV.end());
	sort(yV.begin(), yV.end());
	xV.erase(unique(xV.begin(), xV.end()), xV.end());
	yV.erase(unique(yV.begin(), yV.end()), yV.end());
	for(auto &s : bs) {
		s.x1 = lower_bound(xV.begin(), xV.end(), s.x1) - xV.begin();
		s.x2 = lower_bound(xV.begin(), xV.end(), s.x2) - xV.begin();
		s.y1 = lower_bound(yV.begin(), yV.end(), s.y1) - yV.begin();
		s.y2 = lower_bound(yV.begin(), yV.end(), s.y2) - yV.begin();
	}
	for(auto &l : laser) {
		if(l.second == 0) l.first = lower_bound(yV.begin(), yV.end(), l.first) - yV.begin();
		else l.first = lower_bound(xV.begin(), xV.end(), l.first) - xV.begin();
	}
}

void solve() {
	for(int i = 0; i < I; ++i) {
		auto l = laser[i];
		if(l.second == 0) yupdate(0, MAX-1, 1, l.first, i);
		else xupdate(0, MAX-1, 1, l.first, i);
	}

	for(int i = 0; i < K; ++i) {
		auto s = bs[i];
		auto curx = xquery(0, MAX-1, 1, s.x1, s.x2);
		auto cury = yquery(0, MAX-1, 1, s.y1, s.y2);
		curx = min(curx, cury);
		if(curx == INF) continue;
		result[curx] = max(result[curx], s.w);
	}

	for(int i = 0; i < I; ++i) {
		cout<<result[i]<<"\n";
	}
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