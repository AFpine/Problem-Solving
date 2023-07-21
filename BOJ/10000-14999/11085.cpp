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
const int MAX = 1010;

int P, W, st, en;
vector<pii> adj[MAX];
bool visited[MAX];

bool solve(int p) {
	memset(visited, false, sizeof(visited));
	queue<int> Q;
	visited[st] = true;
	Q.push(st);

	while(!Q.empty()) {
		auto cur = Q.front(); 
		Q.pop();

		for(auto &e : adj[cur]) {
			if(visited[e.first] || e.second < p) continue;
			visited[e.first] = true;
			Q.push(e.first);
		}
	}

	if(visited[en]) return true;
	else return false;
}

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>P>>W>>st>>en;
	for(int i = 1; i <= W; ++i) {
		int a, b, c;
		cin>>a>>b>>c;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}

	int l = 1, r = 1000;
	int result = 0;
	while(l <= r) {
		int mid = (l+r)/2;
		if(solve(mid)) {
			result = max(result, mid);
			l = mid + 1;
		}
		else r = mid - 1;
	}

	cout<<result;

	return 0;
}