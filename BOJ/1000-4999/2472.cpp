#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

// 2472

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
const int MAX = 101010;

struct wv {
	ll w; int v;
	bool operator<(const wv& rhs) const {
		return w > rhs.w;
	}
};

int N, M, ST[3];
vector<wv> adj[MAX];
ll dist[3][MAX];
vector<int> seq;
ll tree[4*MAX];
bool ans[MAX];

void update(int s, int e, int node, int pos, ll k) {
	if(pos > e || pos < s) return;
	if(s == e) {
		tree[node] = min(tree[node], k);
		return;
	}
	int mid = (s+e)/2;
	update(s, mid, node*2, pos, k);
	update(mid+1, e, node*2+1, pos, k);
	tree[node] = min(tree[node*2], tree[node*2+1]);
}

ll query(int s, int e, int node, int l, int r) {
	if(l > e || r < s) return INF;
	if(l <= s && r >= e) return tree[node];
	int mid = (s+e)/2;
	return min(query(s, mid, node*2, l, r), query(mid+1, e, node*2+1, l, r));
}

void input() {
	fill(tree, tree+4*MAX, INF);
	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < MAX; ++j) dist[i][j] = INF;
	}
	cin>>N;
	for(int i = 0; i < 3; ++i) cin>>ST[i];

	seq.resize(N+1);
	for(int i = 1; i <= N; ++i) seq[i] = i;
	cin>>M;
	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w, v });
		adj[v].push_back({ w, u });
	}
}

void dijkstra(int cnt, int st) {
	priority_queue<wv> pq;

	pq.push({ 0, st });
	dist[cnt][st] = 0;

	while (!pq.empty()) {
		int v = pq.top().v;
		ll w = pq.top().w;
		pq.pop();

		if (w > dist[cnt][v]) continue;

		for (auto& i : adj[v]) {
			if (dist[cnt][i.v] > w + i.w) {
				dist[cnt][i.v] = w + i.w;
				pq.push({ w + i.w, i.v });
			}
		}
	}
}

void cc() {
	vector<ll> a, b, c;
	a.push_back(-1);
	b.push_back(-1);
	c.push_back(-1);
	for(int i = 1; i <= N; ++i) {
		a.push_back(dist[0][i]);
		b.push_back(dist[1][i]);
		c.push_back(dist[2][i]);
	}
	sort(all(a)); sort(all(b)); sort(all(c));
	a.erase(unique(all(a)), a.end());
	b.erase(unique(all(b)), b.end());
	c.erase(unique(all(c)), c.end());
	for(int i = 1; i <= N; ++i) {
		dist[0][i] = lower_bound(all(a), dist[0][i]) - a.begin();
		dist[1][i] = lower_bound(all(b), dist[1][i]) - b.begin();
		dist[2][i] = lower_bound(all(c), dist[2][i]) - c.begin();
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

	for(int i = 0; i < 3; ++i) dijkstra(i, ST[i]);
	
	cc();
	
	sort(seq.begin()+1, seq.begin()+1+N, [](int a, int b) {
		if(dist[0][a] ^ dist[0][b]) return dist[0][a] < dist[0][b];
		if(dist[1][a] ^ dist[1][b]) return dist[1][a] > dist[1][b];
		return dist[2][a] > dist[2][b];
	});

	for(int i = 1; i <= N; ++i) {
		int cur = seq[i];
		if(query(1, N, 1, 1, dist[1][cur]-1) >= dist[2][cur]) ans[cur] = true;
		update(1, N, 1, dist[1][cur], min(dist[2][cur], query(1, N, 1, dist[1][cur], dist[1][cur])));
	}
	
	cin>>M;
	while(M--) {
		int q;
		cin>>q;
		cout<<(ans[q] ? "YES" : "NO")<<'\n';
	}


	return 0;
}
