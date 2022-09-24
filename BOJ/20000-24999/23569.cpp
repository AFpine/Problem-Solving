#include <bits/stdc++.h>

// 23569 Friendship Graphs

// update 220924

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
const int MAX = 1005;

int N, M, color[MAX], res0 = 0, res1 = 0;
bool incorrect = false, f[MAX][MAX];
vector<int> adj[MAX];
vector<int> res;
int dp[MAX][2*MAX];

int knap(int idx, int cur) {
	if(idx == sz(res)) return abs(cur);
	int &ret = dp[idx][MAX+cur];
	if(ret != INF) return ret;

	ret = min(ret, knap(idx+1, cur + res[idx]));
	ret = min(ret, knap(idx+1, cur - res[idx]));
	return ret;
}

void dfs(int cur, int prv, int co) {
	if(co) res1++;
	else res0++;

	for(auto &e : adj[cur]) {
		if(e == prv) continue;
		if(color[e] == color[cur]) incorrect = true;
		if(color[e] == -1) {
			color[e] = (co ^ 1);
			dfs(e, cur, color[e]);
		}
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

	fill(color, color+MAX, -1);

	cin>>N>>M;
	for(int i = 1; i <= M; ++i) {
		int u, v;
		cin>>u>>v;
		f[u][v] = f[v][u] = true;
	}
	for(int i = 1; i <= N; ++i) {
		for(int j = i+1; j <= N; ++j) {
			if(f[i][j]) continue;
			adj[i].push_back(j);
			adj[j].push_back(i);
		}
	}
	
	for(int i = 1; i <= N; ++i) {
		if(color[i] == -1) {
			res0 = res1 = 0;
			color[i] = 0;
			dfs(i, -1, 0);
			if(res0 != res1) res.push_back(abs(res0 - res1));
		}
	}
	
	if(incorrect) { cout<<"-1"; return 0; }

	for(int i = 0; i < MAX; ++i) {
		for(int j = 0; j < 2*MAX; ++j) dp[i][j] = INF;
	}
	cout<<knap(0, 0);

	return 0;
}