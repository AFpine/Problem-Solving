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

const double PI = acos(-1);
const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const long long MOD = 1e9+7;
const int MAX = 20202;

int T, N, M;
vector<int> adj[MAX], radj[MAX];
int in[MAX], out[MAX], p[2*MAX], vi[MAX], num, cnt;
vector<vector<int>> scc;
int sccin[MAX], sccout[MAX];

void init() {
	num = cnt = 0;
	for(int i = 0; i < MAX; ++i) {
		adj[i].clear();
		radj[i].clear();
		in[i] = out[i] = vi[i] = 0;
		p[i] = p[i+MAX] = 0;
		sccin[i] = sccout[i] = 0;
	}
	scc.clear();
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
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>T;
	while(T--) {
		init();
		cin>>N>>M;
		for(int i = 1; i <= M; ++i) {
			int a, b;
			cin>>a>>b;
			adj[a].push_back(b);
			radj[b].push_back(a);
		}

		kosaraju();

		for(int i = 1; i <= N; ++i) {
			for(auto &e : adj[i]) {
				if(vi[i] != vi[e]) {
					sccout[vi[i]]++;
					sccin[vi[e]]++;
				}
			}
		}

		int a1 = 0, a2 = 0;
		for(int i = 1; i <= cnt; ++i) {
			if(sccout[i] == 0) a1++;
			if(sccin[i] == 0) a2++;
		}

		if(cnt == 1) cout<<"0\n";
		else cout<<max(a1, a2)<<'\n';
	}
	return 0;
}
