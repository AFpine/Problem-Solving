#include <bits/stdc++.h>

// 2699

// 221031

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
const int MAX = 252525;

struct point {
	ll x, y;
	bool operator<(const point& rhs) const {
		if (y != rhs.y) return y < rhs.y;
		return x < rhs.x;
	}
};

int N;
vector<point> p, ans;
vector<int> st;

ll ccw(const point& a, const point& b, const point& c) {
	// res > 0 -> ccw, res < 0 -> cw, res = 0 -> colinear
	ll res = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
	return (res > 0 ? 1 : (res < 0 ? -1 : 0));
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		p.push_back({ x, y });
	}
}

ll dist(const point& p1, const point& p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

bool cmp(const point& p1, const point& p2) {
    return (ccw(p[0], p1, p2) > 0 || (ccw(p[0], p1, p2) == 0 && dist(p[0], p1) < dist(p[0], p2)));
}

void grahamScan() {
	sort(p.begin(), p.end());

	sort(p.begin() + 1, p.end(), cmp);

	st.push_back(0);
	st.push_back(1);
	for (int next = 2; next < N; next++) {
		while (st.size() >= 2) {
			int first = st.back();
			st.pop_back();
			int second = st.back();
			if (ccw(p[second], p[first], p[next]) > 0) {
				st.push_back(first);
				break;
			}
		}
		st.push_back(next);
	}
}

void init() {
	p.clear(); st.clear(); ans.clear();
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int P;
	cin>>P;
	while(P--) {
		init();

		input();

		grahamScan();

		for(auto &i : st) ans.push_back(p[i]);

		pii fir = {-50, -50};
		int pivot = -1;

		for(int i = 0; i < sz(ans); ++i) {
			if(ans[i].y > fir.second) {
				pivot = i;
				fir = {ans[i].x, ans[i].y};
			}
			else if(ans[i].y == fir.second && ans[i].x < fir.first) {
				pivot = i;
				fir = {ans[i].x, ans[i].y};
			}
		}
		
		cout<<sz(ans)<<'\n';
		for(int i = 0; i < sz(ans); ++i) {
			cout<<ans[(pivot-i+sz(ans))%sz(ans)].x<<" "<<ans[(pivot-i+sz(ans))%sz(ans)].y<<'\n';
		}
	}

	return 0;
}
