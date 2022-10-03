#include <bits/stdc++.h>

// 10273 고대 동굴 탐사

// update 221003

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
const int MAX = 20005;

int N, E;
int nxt[MAX];
ll V[MAX], dp[MAX];
vector<pll> adj[MAX];

ll f(int idx) {
	ll &ret = dp[idx];
	if(ret != -1) return ret;

	ret = 0;
	for(auto &e : adj[idx]) {
		if(f(e.first) - e.second > ret) {
			ret = f(e.first) - e.second;
			nxt[idx] = e.first;
		}
	}
	ret += V[idx];
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

	int tc;
	cin>>tc;
	while(tc--) {
		fill(dp, dp+MAX, -1);
		fill(nxt, nxt+MAX, 0);
		fill(V, V+MAX, 0);
		for(int i = 0; i < MAX; ++i) adj[i].clear();
		
		cin>>N>>E;

		for(int i = 1; i <= N; ++i) cin>>V[i];
		for(int i = 1; i <= E; ++i) {
			int a, b, c;
			cin>>a>>b>>c;
			adj[a].push_back({b, c});
		}

		cout<<f(1)<<" ";

		int idx = 1;
		vector<int> ans;
		while(idx) {
			ans.push_back(idx);
			idx = nxt[idx];
		}
		cout<<sz(ans)<<'\n';
		for(auto &i : ans) cout<<i<<" ";
		cout<<'\n';
	}
	return 0;
}