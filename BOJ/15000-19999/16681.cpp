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
const ll INF = 1e18;
// const long long llINF = 1e18;
const int minINF = -2e9-1;
const long long MOD = 1e9+9;
const int MAX = 101010;

struct wv {
	ll w; int v;
	bool operator<(const wv& rhs) const {
		return w > rhs.w;
	}
};

int N, M, D, E, st;
int height[MAX];
vector<wv> adj[MAX];
vector<ll> dist1(MAX, INF), dist2(MAX, INF);

void dijkstra1(int st) {
	priority_queue<wv> pq;
	pq.push({ 0, st });
	dist1[st] = 0;
	while (!pq.empty()) {
		auto [w, v] = pq.top();
		pq.pop();
		if (w > dist1[v]) continue;
		for (auto& i : adj[v]) {
			if ((height[i.v] > height[v]) && (dist1[i.v] > w + i.w)) {
				dist1[i.v] = w + i.w;
				pq.push({ w + i.w, i.v });
			}
		}
	}
}

void dijkstra2(int st) {
	priority_queue<wv> pq;
	pq.push({ 0, st });
	dist2[st] = 0;
	while (!pq.empty()) {
		auto [w, v] = pq.top();
		pq.pop();
		if (w > dist2[v]) continue;
		for (auto& i : adj[v]) {
			if ((height[i.v] > height[v]) && (dist2[i.v] > w + i.w)) {
				dist2[i.v] = w + i.w;
				pq.push({ w + i.w, i.v });
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

	cin>>N>>M>>D>>E;
	for(int i = 1; i <= N; ++i) cin>>height[i];

	for(int i = 1; i <= M; ++i) {
		int a, b, n;
		cin>>a>>b>>n;
		adj[a].push_back({n, b});
		adj[b].push_back({n, a});
	}
	
	dijkstra1(1);
	dijkstra2(N);

	ll result = -INF;
	for(int i = 2; i < N; ++i) {
		if(dist1[i] != INF && dist2[i] != INF) {
			result = max(result, (1LL * E * height[i]) - 1LL*(dist1[i] + dist2[i])*D);
		}
	}
	if(result == -INF) cout<<"Impossible";
	else cout<<result;

	return 0;
}