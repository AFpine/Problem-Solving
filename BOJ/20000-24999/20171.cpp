#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

// 20171

// 221107

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
const int MAX = 101010;

int N, K, cnt[MAX], ans;
bool apart[MAX], visited[MAX];
vector<int> child[MAX];
vector<pii> adj[MAX];

int dfs(int v) {
	if(apart[v]) cnt[v]++;
	for(auto &e : adj[v]) {
		if(!visited[e.first]) {
			visited[e.first] = true;
			child[v].push_back(e.first);
			cnt[v] += dfs(e.first);
		}
	}
	return cnt[v];
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>K;
	for(int i = 1; i <= N-1; ++i) {
		int u, v, w;
		cin>>u>>v>>w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	for(int i = 1; i <= K; ++i) {
		int x;
		cin>>x;
		apart[x] = true;
	}

	visited[1] = true;
	dfs(1);

	for(int i = 1; i <= N; ++i) {
		if(apart[i]) { ans++; continue; }

		int tmp = 0;
		bool flag = false;
		for(auto &e : child[i]) {
			if(cnt[e] == K) flag = true;
			tmp += cnt[e];
		}
		if(flag) continue;
		if(tmp == 0) continue;
		ans++;
	}

	cout<<ans;

	return 0;
}
