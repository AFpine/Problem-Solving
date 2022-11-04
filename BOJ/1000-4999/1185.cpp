#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

// 1185

// 221103

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
const int INF = 1e9+7;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const long long MOD = 1e9+7;
const int MAX = 10101;

// Union find
vector<int> p(MAX, -1);

int find(int x) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

void merge(int a, int b) {
	int A = find(a), B = find(b);
	if (A == B) return;
	p[A] += p[B];
	p[B] = A;
}

// Kruskal's algorithm
struct wv {
	ll w; int v;
};

struct wuv {
	ll w; int u, v;
	bool operator<(const wuv& rhs) const {
		return w < rhs.w;
	}
};

int n, m;
ll cost[MAX], mn = INF;
ll ans;
vector<wuv> a;
vector<wv> adj[MAX];

void input() {
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) { cin>>cost[i]; mn = min(mn, cost[i]);}
	a.resize(m);
	for (auto& i : a) { cin >> i.u >> i.v >> i.w; i.w = i.w*2 + (cost[i.u] + cost[i.v]); }
}

void makingMST() {
    sort(a.begin(), a.end());

	for (auto& i : a) {
		if (find(i.u) == find(i.v)) continue;
		merge(i.u, i.v);
		ans += i.w;
		adj[i.u].push_back({ i.w, i.v });
		adj[i.v].push_back({ i.w, i.u });
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

	input();

	makingMST();

	cout<<ans+mn;

	return 0;
}
