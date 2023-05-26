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
const int MAX = 222;

struct wv {
	ll w; int v;
	bool operator<(const wv& rhs) const {
		return w > rhs.w;
	}
};

int N, M;
vector<wv> adj[MAX];
ll dist[MAX];
ll result = INF;

void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ 2*w, v });
		adj[v].push_back({ 2*w, u });
	}
}

void init() {
	fill(dist, dist+MAX, INF);
}

void dijkstra(int st) {
	priority_queue<wv> pq;
	pq.push({ 0, st });
	dist[st] = 0;
	while (!pq.empty()) {
		auto [w, v] = pq.top();
		pq.pop();
		if (w > dist[v]) continue;
		for (auto& i : adj[v]) {
			if (dist[i.v] > w + i.w) {
				dist[i.v] = w + i.w;
				pq.push({ w + i.w, i.v });
			}
		}
	}
}

ll query(int st) {
	ll ret = 0;
	init();
	dijkstra(st);
	for(int i = 1; i <= N; ++i) {
		ret = max(ret, dist[i]);
		for(auto &e : adj[i]) {
			ret = max(ret, (e.w - abs(dist[i] - dist[e.v])) / 2 + max(dist[i], dist[e.v]));
		}
	}
	return ret;
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

	for(int i = 1; i <= N; ++i) {
		result = min(result, query(i));
	}

	if(result % 2) cout<<result/2<<".5";
	else cout<<result/2<<".0";

	return 0;
}