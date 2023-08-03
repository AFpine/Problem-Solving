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

struct wv {
	ll w;
	int v;
	int idx;
	bool operator<(const wv& rhs) const {
		return w > rhs.w;
	}
};

int N, M;
pair<pii, pii> prv[MAX];
vector<wv> adj[MAX];
ll dist[MAX];
vector<pair<pii, pii>> path;
ll result;

void dijkstra(int f) {
	fill(dist, dist+MAX, INF);
	priority_queue<wv> pq;
	pq.push({0, 1});
	prv[1] = {{-1, -1}, {-1, -1}};
	dist[1] = 0;
	
	while(!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		if(cur.w > dist[cur.v]) continue;
		if(cur.v == N) break;
		for(int i = 0; i < adj[cur.v].size(); ++i) {
			auto nxt = adj[cur.v][i];
			if(dist[nxt.v] > cur.w + nxt.w) {
				dist[nxt.v] = cur.w + nxt.w;
				if(f) prv[nxt.v] = {{cur.v, adj[nxt.v][nxt.idx].idx}, {nxt.v, nxt.idx}};
				pq.push({dist[nxt.v], nxt.v});
			}
		}
	}
	result = max(result, dist[N]);
}

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>M;

	for(int i = 1; i <= M; ++i) {
		int a, b, w;
		cin>>a>>b>>w;
		adj[a].push_back({w, b, sz(adj[b])});
		adj[b].push_back({w, a, sz(adj[a])-1});
	}

	dijkstra(1);
	auto p = prv[N];
	while(p.first.first != -1) {
		path.push_back(p);
		p = prv[p.first.first];
	}

	for(auto &p : path) {
		ll t1 = adj[p.first.first][p.first.second].w;
		ll t2 = adj[p.second.first][p.second.second].w;
		adj[p.first.first][p.first.second].w = adj[p.second.first][p.second.second].w = INF;
		dijkstra(0);
		adj[p.first.first][p.first.second].w = t1;
		adj[p.second.first][p.second.second].w = t2;
	}

	cout<<result;

	return 0;
}