#include <bits/stdc++.h>

// 25402

// 221029

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
const int MAX = 252525;

int N, Q, K, p[MAX], parent[MAX];
set<int> S;
vector<int> adj[MAX];
bool selected[MAX];
bool visited[MAX];
bool unionselected[MAX];

int find(int a) {
	if(p[a] < 0) return a;
	return p[a] = find(p[a]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if(a == b) return;
	p[a] += p[b];
	p[b] = a;
}

void dfs(int v) {
	for(auto &e : adj[v]) {
		if(parent[e] != -1) continue;
		parent[e] = v;
		dfs(e);
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

	fill(p, p+MAX, -1);
	fill(parent, parent+MAX, -1);

	cin>>N;
	for(int i = 1; i < N; ++i) {
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	parent[1] = 0;
	dfs(1);
	
	cin>>Q;
	while(Q--) {
		cin>>K;
		for(int i = 1; i <= K; ++i) {
			int t;
			cin>>t;
			S.insert(t);
		}
		for(auto &i : S) {
			if(S.find(parent[i]) != S.end()) merge(i, parent[i]);
		}

		ll ans = 0;
		for(auto &i : S) {
			if(unionselected[find(i)]) continue;
			unionselected[find(i)] = true;
			ll t = -p[find(i)];
			ans += (t*(t-1)) / 2;
		}
		cout<<ans<<'\n';

		for(auto &i : S) {
			selected[i] = false;
			p[i] = -1;
			unionselected[i] = false;
		}
		S.clear();
	}
	return 0;
}