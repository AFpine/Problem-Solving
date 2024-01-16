#pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
#define sz(a) (int)(a.size()) 
#define all(a) (a).begin(), (a).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef pair<long double, long double> pdd;
typedef complex<double> cplx;

const int MAX = 101010;
const ll MOD = 1e9+7;

int N, K;
int colored[MAX];
bool visited[MAX];

ll dp[MAX][5];

vector<int> adj[MAX];
vector<int> child[MAX];
vector<int> roots;

ll ans = 0;

void buildTree(int v) {
	visited[v] = true;
	for(auto &e : adj[v]) {
		if(visited[e]) continue;
		visited[e] = true;
		child[v].push_back(e);
		buildTree(e);
	}
}

ll f(int i, int j) {
	auto &ret = dp[i][j];
	if(ret != -1) return ret;

	ret = 1;
	for(auto &e : child[i]) {
		ll tret = 0;
		if(colored[e]) {
			if(colored[e] == j) {
				ret = 0;
				return 0;
			}
			tret = (tret + f(e, colored[e])) % MOD;
		}
		else {
			for(int nj = 1; nj <= 3; ++nj) {
				if(nj == j) continue;
				tret = (tret + f(e, nj)) % MOD;
			}
		}
		ret = (ret * tret) % MOD;
	}
	return ret;
}

void treeDP(int s) {
	if(colored[s]) ans = f(s, colored[s]) % MOD;
	else {
		for(int i = 1; i <= 3; ++i) {
			ans = (ans + f(s, i)) % MOD;
		}
	}
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
	for(int i = 1; i < N; ++i) {
		int x, y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	for(int i = 1; i <= K; ++i) {
		int b, c;
		cin>>b>>c;
		colored[b] = c;
	}

	for(int i = 1; i <= N; ++i) {
		if(!visited[i]) {
			roots.push_back(i);
			buildTree(i);
		}
	}
	
	memset(dp, -1, sizeof(dp));

	treeDP(1);

	cout<<ans<<"\n";

	return 0;
}