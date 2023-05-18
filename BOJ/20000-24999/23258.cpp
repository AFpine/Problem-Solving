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
const int MAX = 310;

int N, Q;
ll adj[MAX][MAX][MAX];

void init() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			for(int k = 0; k < MAX; ++k) {
                adj[i][j][k] = INF;
            }
		}
	}
}

void floyd() {
	for (int i = 1; i <= N; i++) adj[i][i][0] = 0;
	for (int k = 1; k <= N; k++) {
		for (int u = 1; u <= N; u++) {
			for (int v = 1; v <= N; v++) {
				adj[u][v][k] = min(adj[u][v][k-1], adj[u][k][k-1] + adj[k][v][k-1]);
			}
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

    init();

    cin>>N>>Q;

    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            ll k;
            cin>>k;
            if(k > 0) adj[i][j][0] = k;
        }
    }

    floyd();

    for(int i = 1; i <= Q; ++i) {
        int c, s, e;
        cin>>c>>s>>e;
        if(adj[s][e][c-1] == INF) cout<<"-1\n";
        else cout<<adj[s][e][c-1]<<'\n';
    }

	return 0;
}