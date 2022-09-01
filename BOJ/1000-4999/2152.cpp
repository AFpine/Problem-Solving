// #define LOCAL_TEST

#include <bits/stdc++.h>

// 2152 여행 계획 세우기

// update 220901

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
const long long MOD = 1000000007;
const int MAX = 10005;

int N, M, S, T;
int num, sccNum;
int pre[MAX], post[MAX], bucket[2*MAX], visited[MAX];
vector<int> adj[MAX], radj[MAX], sEdge[MAX];
vector<vector<int>> scc;

int dp[MAX];
bool check[MAX], traveled[MAX];

void flood(int cur) {
	scc[sccNum].push_back(cur);
	visited[cur] = sccNum;
	
	for(auto &e : adj[cur]) {
		if(!visited[e]) flood(e);
	}
}

void dfs(int cur) {
	pre[cur] = ++num;
	for(auto &e : radj[cur]) {
		if(!pre[e]) dfs(e);
	}
	post[cur] = ++num;
	bucket[num] = cur;
}

void kosaraju() {
	for(int i = 1; i <= N; ++i) {
		if(!pre[i]) dfs(i);
	}

	for(int i = N*2; i >= 1; --i) {
		if(!bucket[i]) continue;
		if(visited[bucket[i]]) continue;

		sccNum++;
		scc.resize(sccNum + 1);
		flood(bucket[i]);
	}
}

int travel(int cur) {
	if(cur == T) return sz(scc[cur]);
	int &ret = dp[cur];
	if(ret != -1) return ret;
	ret = -INF;
	for(auto &e : sEdge[cur]) {
		ret = max(sz(scc[cur]) + travel(e), ret);
	}
	return ret;
}

void input() {
	cin>>N>>M>>S>>T;
	for(int i = 0; i < M; ++i) {
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		radj[v].push_back(u);
	}
}

void solve() {
	kosaraju();

	for(int i = 1; i <= sccNum; ++i) {
		for(auto &u : scc[i]) {
			for(auto &v : adj[u]) {
				if(visited[u] == visited[v]) continue;
				sEdge[visited[u]].push_back(visited[v]);
			}
		}
	}

	fill(dp, dp+MAX, -1);
	
	S = visited[S], T = visited[T];
	int result = travel(S);

	if(result <= 0) cout<<"0";
	else cout<<result;
}

int main() {

	#ifdef LOCAL_TEST
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}