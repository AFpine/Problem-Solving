#include <bits/stdc++.h>

// 14676 영우는 사기꾼?

// update 220930

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
const int MAX = 100005;

int N, M, K, ind[MAX], cnt[MAX];
vector<int> adj[MAX];
set<int> s[MAX];
bool incorrect = false;

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>M>>K;
	for(int i = 0; i < M; ++i) {
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		ind[v]++;
	}

	while(K--) {
		int op, x;
		cin>>op>>x;
		if(op == 1) {
			if(sz(s[x]) < ind[x]) { incorrect = true; break; }
			if(++cnt[x] == 1) {
				for(auto &i : adj[x]) s[i].insert(x);
			}
		}
		else {
			if(!cnt[x]) { incorrect = true; break; }
			if(--cnt[x] == 0) {
				for(auto &i : adj[x]) s[i].erase(x);
			}
		}
	}

	if(incorrect) cout<<"Lier!";
	else cout<<"King-God-Emperor";

	return 0;
}