#include <bits/stdc++.h>

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
const int MAX = 2020;

struct Point { ll x, y; };

int N;
Point l1, l2, r1, r2, r3, r4;

ll ccw(const Point& a, const Point& b, const Point& c) {
    // res > 0 -> ccw, res < 0 -> cw, res = 0 -> colinear
    ll res = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
    return (res > 0 ? 1 : (res < 0 ? -1 : 0));
}

// Does the line segment ab and cd intersect?
bool isCross(const Point& a, const Point& b, const Point& c, const Point& d) {
    ll ab = ccw(a, b, c) * ccw(a, b, d);
    ll cd = ccw(c, d, a) * ccw(c, d, b);
    if (ab == 0 && cd == 0) {
        pii A = { a.x, a.y }, B = { b.x, b.y }, C = { c.x, c.y }, D = { d.x, d.y };
        if (A > B) swap(A, B);
        if (C > D) swap(C, D);
        return (A <= D && C <= B);
    }
    else return (ab <= 0 && cd <= 0);
}

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N;
	while(N--) {
		cin>>l1.x>>l1.y>>l2.x>>l2.y>>r1.x>>r1.y>>r3.x>>r3.y;

		r2.x = r3.x;
		r2.y = r1.y;
		r4.x = r1.x;
		r4.y = r3.y;

		bool result = false;
		if(isCross(l1, l2, r1, r2)) result = true;
		if(isCross(l1, l2, r2, r3)) result = true;
		if(isCross(l1, l2, r3, r4)) result = true;
		if(isCross(l1, l2, r4, r1)) result = true;
		if(l1.x >= min(r1.x, r3.x) && l1.x <= max(r1.x, r3.x) && l1.y >= min(r1.y, r3.y) && l1.y <= max(r1.y, r3.y) && l2.x >= min(r1.x, r3.x) && l2.x <= max(r1.x, r3.x) && l2.y >= min(r1.y, r3.y) && l2.y <= max(r1.y, r3.y)) result = true;

		if(result) cout<<"T\n";
		else cout<<"F\n";
	}
	
	return 0;
}