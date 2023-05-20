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
const int MAX = 5050;

int M, N, K;
int dist[MAX];
pll S, T;
vector<pair<pll, pll>> v(MAX);
vector<int> adj[MAX];
queue<int> Q;

ll ccw(const pll& a, const pll& b, const pll& c) {
    // res > 0 -> ccw, res < 0 -> cw, res = 0 -> colinear
    ll res = (b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second);
    return (res > 0 ? 1 : (res < 0 ? -1 : 0));
}

// Does the line segment ab and cd intersect?
bool isCross(const pll& a, const pll& b, const pll& c, const pll& d) {
    ll ab = ccw(a, b, c) * ccw(a, b, d);
    ll cd = ccw(c, d, a) * ccw(c, d, b);
    if (ab == 0 && cd == 0) {
        pll A = { a.first, a.second }, B = { b.first, b.second }, C = { c.first, c.second }, D = { d.first, d.second };
        if (A > B) swap(A, B);
        if (C > D) swap(C, D);
        return (A <= D && C <= B);
    }
    else return (ab <= 0 && cd <= 0);
}

void bfs() {
	while(!Q.empty()) {
		auto cur = Q.front();
		Q.pop();

		for(auto &i : adj[cur]) {
			if(dist[i] != -1) continue;
			dist[i] = dist[cur] + 1;
			Q.push(i);
		}	
	}
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for(int i = 0; i < MAX; ++i) dist[i] = -1;

	cin>>M>>N>>K;

	for(int i = 1; i <= K; ++i) {
		ll b, x1, y1, x2, y2;
		cin>>b>>x1>>y1>>x2>>y2;
		if(x1 > x2) swap(x1, x2);
		if(y1 > y2) swap(y1, y2);
		v[b] = {{x1, y1}, {x2, y2}};
	}
	cin>>S.first>>S.second>>T.first>>T.second;

	for(int i = 1; i <= K; ++i) {
		for(int j = i+1; j <= K; ++j) {
			if(isCross(v[i].first, v[i].second, v[j].first, v[j].second)) {
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
		if(v[i].first.first == v[i].second.first) {
			if(v[i].first.first == S.first && v[i].first.second <= S.second && v[i].second.second >= S.second) {
				adj[0].push_back(i);
			}
			if(v[i].first.first == T.first && v[i].first.second <= T.second && v[i].second.second >= T.second) {
				adj[i].push_back(K+1);
			}
		}
		else {
			if(v[i].first.second == S.second && v[i].first.first <= S.first && v[i].second.first >= S.first) {
				adj[0].push_back(i);
			}
			if(v[i].first.second == T.second && v[i].first.first <= T.first && v[i].second.first >= T.first) {
				adj[i].push_back(K+1);
			}
		}
	}

	dist[0] = 0;
	Q.push(0);
	
	bfs();

	cout<<dist[K+1]-1<<'\n';

	return 0;
}