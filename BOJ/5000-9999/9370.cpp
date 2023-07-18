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

struct wv {
	ll w; int v;
	bool operator<(const wv& rhs) const {
		return w > rhs.w;
	}
};

int tt;
int N, M, T, s, g, h, mid;
vector<int> result;
vector<int> dest;
vector<wv> adj[MAX];
ll dist1[MAX], dist2[MAX], dist3[MAX];

void solve(int s, int g, int h) {
	priority_queue<wv> pq;
	pq.push({ 0, s });
	dist1[s] = 0;
	while (!pq.empty()) {
		auto [w, v] = pq.top();
		pq.pop();
		if (w > dist1[v]) continue;
		for (auto& i : adj[v]) {
			if (dist1[i.v] > w + i.w) {
				dist1[i.v] = w + i.w;
				pq.push({ w + i.w, i.v });
			}
		}
	}

	pq.push({ 0, g });
	dist2[g] = 0;
	while (!pq.empty()) {
		auto [w, v] = pq.top();
		pq.pop();
		if (w > dist2[v]) continue;
		for (auto& i : adj[v]) {
			if (dist2[i.v] > w + i.w) {
				dist2[i.v] = w + i.w;
				pq.push({ w + i.w, i.v });
			}
		}
	}

	pq.push({ 0, h });
	dist3[h] = 0;
	while (!pq.empty()) {
		auto [w, v] = pq.top();
		pq.pop();
		if (w > dist3[v]) continue;
		for (auto& i : adj[v]) {
			if (dist3[i.v] > w + i.w) {
				dist3[i.v] = w + i.w;
				pq.push({ w + i.w, i.v });
			}
		}
	}

	for(auto &d : dest) {
		if(dist1[d] == INF) continue;
		if(dist1[d] == min((dist2[s] + mid + dist3[d]), (dist3[s] + mid + dist2[d]))) result.push_back(d);
	}
}

void init() {
	for(int i = 0; i < MAX; ++i) {
		adj[i].clear();
		dist1[i] = INF;
		dist2[i] = INF;
		dist3[i] = INF;
	}
	dest.clear();
	result.clear();
	mid = INF;
}

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>tt;
	while(tt--) {
		init();
		cin>>N>>M>>T;
		cin>>s>>g>>h;
		for(int i = 1; i <= M; ++i) {
			int a, b, d;
			cin>>a>>b>>d;
			adj[a].push_back({d, b});
			adj[b].push_back({d, a});
			if((a == g && b == h) || (a == h && b == g)) mid = d;
		}
		for(int i = 1; i <= T; ++i) {
			int x;
			cin>>x;
			dest.push_back(x);
		}
		solve(s, g, h);
		sort(result.begin(), result.end());
		for(auto &i : result) cout<<i<<" ";
		cout<<'\n';
	}
	
	return 0;
}