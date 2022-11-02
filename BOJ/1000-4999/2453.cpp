#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

// 2453

// 221102

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
const int MAX = 10101;

int N, M, A, B, cnt, sum, uf[MAX], color[MAX];
vector<vector<int>> dp;
bool visited[MAX], incorrect;
vector<pii> adj[MAX];
map<int, int> maping;
vector<int> compdiff;

void init() {
	fill(uf, uf+MAX, -1);
	fill(visited, visited+MAX, false);
	fill(color, color+MAX, -1);
	cnt = sum = 0;
	incorrect = false;
	maping.clear();
	compdiff.clear();
	for(int i = 0; i < MAX; ++i) adj[i].clear();
	dp.clear();
}

int find(int a) {
	if(uf[a] < 0) return a;
	return uf[a] = find(uf[a]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if(a == b) return;
	uf[a] += uf[b];
	uf[b] = a;
}

void input() {
	cin>>N>>M;
	for(int i = 1; i <= M; ++i) {
		int op, x, y;
		cin>>op>>x>>y;
		adj[x].push_back({ op, y });
		adj[y].push_back({ op, x });
		if(op == 1) {
			merge(x, y);
		}
	}
}

int f(int n, int k) {
	auto &ret = dp[n][k];
	if(ret != -1) return ret;
	if(n == sz(compdiff)) return ret = abs(k-sum);
	
	ret = INF;
	ret = min(ret, f(n+1, k+compdiff[n]));
	ret = min(ret, f(n+1, k-compdiff[n]));
	return ret;
}

void dfs(int v, int flag) {
	if(flag) A++;
	else B++;

	for(auto &e : adj[v]) {
		if(visited[e.second]) continue;
		visited[e.second] = true;
		dfs(e.second, color[e.second]);
	}
}

void cycle(int v, int flag) {
	for(auto &e : adj[v]) {
		int nf = 0;
		if(e.first == 1) nf = flag;
		else nf = flag ^ 1;
		if(visited[e.second]) {
			if(color[e.second] != nf) incorrect = true;
		}
		else {
			visited[e.second] = true;
			color[e.second] = nf;
			cycle(e.second, nf);
		}
	}
}

void solve() {
	for(int i = 1; i <= N; ++i) {
		if(maping[find(i)] == 0) maping[find(i)] = ++cnt;
	}

	for(int i = 1; i <= N; ++i) {
		if(visited[i]) continue;
		visited[i] = true;
		color[i] = 0;
		cycle(i, 0);
	}

	fill(visited, visited+MAX, false);
	for(int i = 1; i <= N; ++i) {
		if(visited[i]) continue;
		A = B = 0;
		visited[i] = true;
		dfs(i, color[i]);
		compdiff.push_back(abs(A-B));
		sum += abs(A-B);
	}
	if(incorrect) { cout<<"-1\n"; return; }
	// for(auto &c : compdiff) cout<<c<<" ";

	dp.resize(sz(compdiff)+1, vector<int>(sum * 2 + 5, -1));
	auto ans = f(0, sum);
	cout<<ans<<'\n';
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for(int T = 1; T <= 5; ++T) {
		init();
		input();
		solve();
	}

	return 0;
}
