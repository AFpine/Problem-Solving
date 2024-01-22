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

const int MAX = 101010;

int N;
int cnt[MAX];
int ans = 0;
vector<int> adj[MAX];

void f(int v) {
	int cur = cnt[v];
	int s = sz(adj[v]);
	for(int i = 0; i < 30; ++i) {
		if(cur >= s) {
			ans += i;
			break;
		}
		cur *= 2;
	}

	for(auto &e : adj[v]) {
		if(cnt[e]) continue;
		ans++;
		cnt[e] = 1;
		f(e);
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

	cin>>N;
	for(int i = 1; i < N; ++i) {
		int a, b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	adj[1].push_back(0);
	cnt[0] = 1;
	cnt[1] = 1;
	f(1);

	cout<<ans;
	
	return 0;
}