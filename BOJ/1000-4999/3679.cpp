#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

// 3679

// 221110

using namespace std;
#define sz(a) (int)(a.size()) 
#define all(a) (a).begin(), (a).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef pair<long double, long double> pdd;
typedef complex<double> base;

const double PI = acos(-1);
const int INF = 1e9+7;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const long long MOD = 1e9+7;
const int MAX = 2020;

struct point {
	ll x, y, idx;
	bool operator<(const point& rhs) const {
		if (y != rhs.y) return y < rhs.y;
		return x < rhs.x;
	}
};

int N;
vector<point> P;

ll ccw(const point& a, const point& b, const point& c) {
	// res > 0 -> ccw, res < 0 -> cw, res = 0 -> colinear
	ll res = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
	return (res > 0 ? 1 : (res < 0 ? -1 : 0));
}
ll dist(const point& p1, const point& p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}
bool cmp(const point& p1, const point& p2) {
    return (ccw(P[0], p1, p2) > 0 || (ccw(P[0], p1, p2) == 0 && dist(P[0], p1) < dist(P[0], p2)));
}

void init() {
	P.clear();
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin>>T;
	for(int t = 1; t <= T; ++t) {
		init();
		cin>>N;
		
		P.resize(N);
		for(int i = 0; i < N; ++i) { cin>>P[i].x>>P[i].y; P[i].idx = i; }
		
		sort(all(P));
		sort(P.begin()+1, P.end(), cmp);

		int tmp = N-1;
		for(int i = N-1; i > 0; --i) {
			if(ccw(P[0], P[i], P[N-1]) == 0) tmp = i;
			else break;
		}

		for(int i = 0; i < tmp; ++i) cout<<P[i].idx<<" ";
		for(int i = N-1; i >= tmp; --i) cout<<P[i].idx<<" ";
		cout<<'\n';
	}

	return 0;
}