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
const long long MOD = 998244353;
const int MAX = 1010;

int N;
vector<ll> edge[MAX];
ll ans;

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N;
	for(int i = 1; i <= N*(N-1)/2; ++i) {
		int u, v;
		ll w;
		cin>>u>>v>>w;
		edge[u].push_back(w);
		edge[v].push_back(w);
	}
	for(int i = 1; i <= N; ++i) {
		sort(edge[i].begin(), edge[i].end(), [](ll a, ll b) {
			return a > b;
		});
		for(int j = 0; j < edge[i].size(); j += 2) {
			ans += edge[i][j];
		}
	}
	cout<<ans;
	
	return 0;
}
