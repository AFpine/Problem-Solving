// #define LOCAL_TEST

#include <bits/stdc++.h>

// 17616 등수 찾기

// update 220830

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

int N, M, X, cnt;
vector<int> adj[MAX], arcadj[MAX];
int subsz[MAX], arcsz[MAX];

bool visited[MAX];

void dfs(int cur) {
	cnt++;
	for(auto &e : adj[cur]) {
		if(visited[e]) continue;
		visited[e] = true;
		dfs(e);
	}
}

void arcdfs(int cur) {
	cnt++;
	for(auto &e : arcadj[cur]) {
		if(visited[e]) continue;
		visited[e] = true;
		arcdfs(e);
	}
}

void input() {
	cin>>N>>M>>X;
	for(int i = 1; i <= M; ++i) {
		int a, b;
		cin>>a>>b;
		adj[a].push_back(b);
		arcadj[b].push_back(a);
	}
}

void solve() {
	cnt = 0;
	fill(visited, visited+MAX, false);
	visited[X] = true;
	arcdfs(X);
	int hi = 1+cnt-1;

	cnt = 0;
	fill(visited, visited+MAX, false);
	visited[X] = true;
	dfs(X);
	int lo = N-cnt+1;

	cout<<hi<<" "<<lo;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

#ifdef LOCAL_TEST
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	input();
	solve();

	return 0;
}