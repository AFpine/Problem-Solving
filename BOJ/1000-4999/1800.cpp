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

struct wv {
	ll w; int v;
	bool operator<(const wv& rhs) const {
		return w > rhs.w;
	}
};

int N, P, K;
vector<wv> adj[MAX];
int dist[MAX];

bool check(int p) {
	fill(dist, dist+MAX, INF);
	priority_queue<wv> pq;
	pq.push({ 0, 1 });
	dist[1] = 0;
	while (!pq.empty()) {
		auto [w, v] = pq.top();
		pq.pop();
		if (w > dist[v]) continue;
		for (auto& i : adj[v]) {
			int nxt = w + (i.w > p);
			if (dist[i.v] > nxt) {
				dist[i.v] = nxt;
				pq.push({ nxt, i.v });
			}
		}
	}
	if(dist[N] <= K) return true;
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

	cin>>N>>P>>K;
	for(int i = 1; i <= P; ++i) {
		int a, b, c;
		cin>>a>>b>>c;
		adj[a].push_back({ c, b });
		adj[b].push_back({ c, a });
	}

	int l = 0, r = 1000001;
	int result = INF;
	while(l <= r) {
		int mid = (l+r)/2;
		if(check(mid)) {
			result = min(result, mid);
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}

	if(result == INF) cout<<"-1";
	else cout<<result;
	
	return 0;
}