#include <bits/stdc++.h>

// 1506 경찰서

// 221015

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
const int MAX = 105;

int N;
int cost[MAX];
vector<int> adj[MAX], radj[MAX];
int in[MAX], out[MAX], num, p[2*MAX];
int vi[MAX], cnt;
vector<vector<int>> scc;

void input() {
	string S;
	cin>>N;
	for(int i = 1; i <= N; ++i) cin>>cost[i];
	for(int i = 1; i <= N; ++i) {
		cin>>S;
		for(int j = 1; j <= N; ++j) {
			if(S[j-1] == '1') {
				adj[i].push_back(j);
				radj[j].push_back(i);
			}
		}
	}
}
void dfs(int v) {
	in[v] = ++num;
	for(auto &i : radj[v]) {
		if(!in[i]) dfs(i);
	}
	out[v] = ++num;
	p[num] = v;
}
void flood(int v) {
	scc[cnt].push_back(v);
	vi[v] = cnt;
	for(auto &i : adj[v]) {
		if(!vi[i]) flood(i);
	}
}
void kosaraju() {
	for(int v = 1; v <= N; ++v) {
		if(!in[v]) dfs(v);
	}
	for(int v = 2*N; v >= 1; --v) {
		if(!p[v]) continue;
		if(vi[p[v]]) continue;
		cnt++;
		scc.resize(cnt+1);
		flood(p[v]);
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
	kosaraju();
	ll ans = 0;
	for(int i = 1; i < sz(scc); ++i) {
		int tmp = INF;
		for(auto &j : scc[i]) {
			tmp = min(tmp, cost[j]);
		}
		ans += tmp;
	}

	cout<<ans;

	return 0;
}