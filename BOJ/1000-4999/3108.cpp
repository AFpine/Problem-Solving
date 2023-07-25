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
const int MAX = 1010;

struct Point { ll x, y; };

int N;
int uf[MAX];
set<int> s;
Point line[MAX][4];

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

int find(int a) {
	if(uf[a] < 0) return a;
	return uf[a] = find(uf[a]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if(a == b) return;
	uf[a] += uf[b];
	uf[b] = a;
}

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill(uf, uf+MAX, -1);

	cin>>N;
	for(int i = 1; i <= N; ++i) {
		cin>>line[i][0].x>>line[i][0].y>>line[i][2].x>>line[i][2].y;
		line[i][1].x = line[i][2].x;
		line[i][1].y = line[i][0].y;
		line[i][3].x = line[i][0].x;
		line[i][3].y = line[i][2].y;
	}
	line[0][0].x = line[0][0].y = 0;

	for(int i = 1; i <= N; ++i) {
		for(int j = i+1; j <= N; ++j) {
			for(int l = 0; l < 4; ++l) {
				for(int r = 0; r < 4; ++r) {
					if(isCross(line[i][l], line[i][(l+1)%4], line[j][r], line[j][(r+1)%4])) {
						merge(i, j);
					}
				}
			}
		}
		for(int l = 0; l < 4; ++l) {
			if(isCross(line[0][0], line[0][0], line[i][l], line[i][(l+1)%4])) merge(0, i);
		}
	}
	
	for(int i = 0; i <= N; ++i) s.insert(find(i));

	cout<<s.size()-1;

	return 0;
}