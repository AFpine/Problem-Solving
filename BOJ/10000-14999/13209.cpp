#include <bits/stdc++.h>
 
// 13209 검역소

// update 220823

using namespace std;
#define sz(a) (int)(a.size()) 
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
const long long MOD = 1000000007;
const int MAX = 100005;

int N, K, tk;
bool incorrect;
ll cost[MAX], dp[MAX];
vector<int> adj[MAX], child[MAX];

void init() {
	for(int i = 0; i < MAX; ++i) {
		adj[i].clear();
		child[i].clear();
		cost[i] = 0;
		dp[i] = -1;
	}
}

void dfs(int cur, int prv = -1) {
	for(auto &e : adj[cur]) {
		if(e == prv) continue;
		child[cur].push_back(e);
		dfs(e, cur);
	}
}

ll dpdfs(int cur, ll m) {
	ll &ret = dp[cur];
	if(ret != -1) return ret;
	ret = cost[cur];
	if(cost[cur] > m) incorrect = true;

	priority_queue<ll, vector<ll>, greater<ll>> pq;
	for(auto &e : child[cur]) {
		pq.push(dpdfs(e, m));
	}

	while(!pq.empty()) {
		ll t = pq.top();
		pq.pop();

		if((ret + t) <= m) ret += t;
		else tk++;
	}

	return ret;
}

bool ps(ll x) {
	memset(dp, -1, sizeof(dp));
	tk = 0;
	incorrect = false;
	dpdfs(1, x);
	
	if(incorrect) return false;

	if(tk <= K) return true;
	else return false;
}

void input() {
	cin>>N>>K;
	for(int i = 1; i <= N; ++i) cin>>cost[i];
	for(int i = 1; i <= N-1; ++i) {
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

void solve() {
	dfs(1);
	ll result = -1;
	ll l = 0, r = 10e15;
	while(l <= r) {
		ll mid = (l+r)/2;
		if(ps(mid)) {
			result = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}

	cout<<result<<'\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tt;
	cin>>tt;
	while(tt--) {
		init();
		input();
		solve();
	}

	return 0;
}