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

struct vw {
	int v;
	ll w;
	bool operator<(const vw& rhs) const {
		return w > rhs.w;
	}
};

int N, M;
int A, B, C;
ll dist[3][MAX];
int prv[3][MAX];
vector<vw> adj[MAX];
ll result = INF;
int ans = -1;
vector<pii> answer;

void dijkstra(int idx, int st) {
	priority_queue<vw> pq;
	pq.push({st, 0});
	dist[idx][st] = 0;
	prv[idx][st] = -1;
	while(!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		if(cur.w > dist[idx][cur.v]) continue;
		for(auto &i : adj[cur.v]) {
			if(dist[idx][i.v] > cur.w + i.w) {
				dist[idx][i.v] = cur.w + i.w;
				prv[idx][i.v] = cur.v;
				pq.push({i.v, dist[idx][i.v]});
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

	memset(dist, INF, sizeof(dist));

	cin>>N>>M;
	for(int i = 1; i <= M; ++i) {
		int a, b, c;
		cin>>a>>b>>c;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	cin>>A>>B>>C;

	dijkstra(0, A);
	dijkstra(1, B);
	dijkstra(2, C);

	for(int i = 1; i <= N; ++i) {
		if(result > dist[0][i] + dist[1][i] + dist[2][i]) {
			result = dist[0][i] + dist[1][i] + dist[2][i];
			ans = i;
		}
	}

	int cur = ans;
	int pre = prv[0][cur];
	while(pre != -1) {
		answer.push_back({cur, pre});
		cur = pre;
		pre = prv[0][cur];
	}

	cur = ans;
	pre = prv[1][cur];
	while(pre != -1) {
		answer.push_back({cur, pre});
		cur = pre;
		pre = prv[1][cur];
	}

	cur = ans;
	pre = prv[2][cur];
	while(pre != -1) {
		answer.push_back({cur, pre});
		cur = pre;
		pre = prv[2][cur];
	}
	
	cout<<result<<" "<<sz(answer)<<'\n';
	for(auto &i : answer) cout<<i.first<<" "<<i.second<<'\n';

	return 0;
}