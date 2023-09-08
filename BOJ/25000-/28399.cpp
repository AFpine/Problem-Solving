// #pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
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
const long long MOD = 998244353;
const int MAX = 202020;

struct wv {
	ll w; int v; bool P;
	bool operator<(const wv& rhs) const {
		return w > rhs.w;
	}
};

int N, M, K;
vector<wv> adj[MAX];
int path[MAX], st[MAX], en[MAX], nxt[MAX];
ll dist[2][MAX];

void dijkstra() {
	for(int i = 0; i < MAX; ++i) dist[0][i] = dist[1][i] = llINF;

	priority_queue<wv> pq;
	bool start = st[1];
	dist[start][1] = 0;
	pq.push({0, 1, start});

	while(!pq.empty()) {
		auto cur = pq.top();
		pq.pop();

		if(dist[cur.P][cur.v] < cur.w) continue;

		for(auto &e : adj[cur.v]) {
			auto nP = st[e.v] || (cur.P && nxt[cur.v] == e.v);
			if(nP && en[e.v]) continue;
			if(dist[nP][e.v] > cur.w + e.w) {
				dist[nP][e.v] = cur.w + e.w;
				pq.push({cur.w + e.w, e.v, nP});
			}
		}
	}
}

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>M>>K;
	for(int i = 0; i < M; ++i) {
		int u, v, w;
		cin>>u>>v>>w;
		adj[u].push_back({w, v, false});
	}
	for(int i = 1; i <= K; ++i) {
		int l;
		int prv = -1;
		cin>>l;
		for(int j = 1; j <= l; ++j) {
			int x;
			cin>>x;
			path[x] = i;
			if(j == 1) st[x] = 1;
			else if(j == l) en[x] = 1;
			if(prv > 0) nxt[prv] = x;
			prv = x;
		}
	}
	
	dijkstra();

	for(int i = 1; i <= N; ++i) {
		ll t = min(dist[0][i], dist[1][i]);
		if(t >= llINF) cout<<"-1 ";
		else cout<<t<<" ";
	}

	return 0;
}
