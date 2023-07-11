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
const int MAX = 4040;

struct wv {
	ll w; int v; int ae = 0;
	bool operator<(const wv& rhs) const {
		return w > rhs.w;
	}
};

int N, M;
vector<wv> adj[MAX];
ll dist1[MAX], dist2[2][MAX];

void dijkstra1(int st) {
	priority_queue<wv> pq;
	pq.push({ 0, st, 0 });
	dist1[st] = 0;
	while (!pq.empty()) {
		auto [w, v, ae] = pq.top();
		pq.pop();
		if (w > dist1[v]) continue;
		for (auto& i : adj[v]) {
			if (dist1[i.v] > w + i.w) {
				dist1[i.v] = w + i.w;
				pq.push({ w + i.w, i.v, 0 });
			}
		}
	}
}	

void dijkstra2(int st) {
	priority_queue<wv> pq;
	pq.push({ 0, st, 0 });
	dist2[0][st] = 0;
	while (!pq.empty()) {
		auto [w, v, ae] = pq.top();
		pq.pop();
		if (w > dist2[ae][v]) continue;
		for (auto& i : adj[v]) {
			if (ae == 0 && dist2[ae^1][i.v] > w + (i.w/2)) {
				dist2[ae^1][i.v] = w + (i.w/2);
				pq.push({ w + (i.w/2), i.v, ae^1 });
			}
			else if (ae == 1 && dist2[ae^1][i.v] > w + i.w*2LL) {
				dist2[ae^1][i.v] = w + i.w*2LL;
				pq.push({ w + i.w*2LL, i.v, ae^1 });
			}
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

	memset(dist1, INF, sizeof(dist1));
	memset(dist2, INF, sizeof(dist2));

	cin>>N>>M;
	for(int i = 1; i <= M; ++i) {
		int a, b, c;
		cin>>a>>b>>c;
		adj[a].push_back({c*2LL, b, 0});
		adj[b].push_back({c*2LL, a, 0});
	}

	dijkstra1(1);
	dijkstra2(1);

	int result = 0;
	for(int i = 2; i <= N; ++i) {
		if(dist1[i] < min(dist2[0][i], dist2[1][i])) result++;
	}
	cout<<result;
	
	return 0;
}