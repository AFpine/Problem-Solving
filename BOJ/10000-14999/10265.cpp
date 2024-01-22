#pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
#define sz(a) (ll)(a.size()) 
#define all(a) (a).begin(), (a).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef pair<long double, long double> pdd;
typedef complex<double> cplx;

const int MAX = 1010;

int N, K;
int cycle_cnt = 0;
int nxt[MAX], cycle[MAX], snake[MAX];
int cycle_sz[MAX], snake_sz[MAX];
bool visited[MAX];

int dp[MAX][MAX];

bool iscycle(int v, int st) {
	visited[v] = true;
	if(visited[nxt[v]]) {
		if(nxt[v] == st) return true;
		else return false;
	}
	return iscycle(nxt[v], st);
}

void numbering_cycle(int v, int num) {
	cycle[v] = num;
	if(cycle[nxt[v]]) return;
	else numbering_cycle(nxt[v], num);
}

int merge_cycle(int v) {
	if(cycle[nxt[v]]) return cycle[nxt[v]];
	else return merge_cycle(nxt[v]);
}

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>K;
	for(int i = 1; i <= N; ++i) cin>>nxt[i];

	for(int i = 1; i <= N; ++i) {
		for(int j = 0; j < MAX; ++j) visited[j] = false;
		if(cycle[i]) continue;

		if(iscycle(i, i)) {
			cycle_cnt++;
			numbering_cycle(i, cycle_cnt);
		}
	}

	for(int i = 1; i <= N; ++i) {
		if(cycle[i]) continue;
		snake[i] = merge_cycle(i);
	}

	for(int i = 1; i <= N; ++i) {
		if(cycle[i]) cycle_sz[cycle[i]]++;
		else snake_sz[snake[i]]++;
	}

	for(int i = 0; i < MAX; ++i) {
		for(int j = 0; j < MAX; ++j) dp[i][j] = -1000000000;
	}

	dp[0][0] = 0;
	for(int k = 0; k <= K; ++k) {
		for(int i = 1; i <= cycle_cnt; ++i) {
			dp[i][k] = max(dp[i][k], dp[i-1][k]);
			if(k - cycle_sz[i] >= 0) dp[i][k] = max(dp[i][k], dp[i-1][k - cycle_sz[i]] + snake_sz[i]);
		}
	}

	int ans = 0;
	for(int k = 0; k <= K; ++k) {
		ans = max(ans, dp[cycle_cnt][k] + k);
	}
	if(ans >= K) cout<<K;
	else cout<<ans;

	return 0;
}