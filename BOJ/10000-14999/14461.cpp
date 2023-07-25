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
const int MAX = 111;

struct wv {
	int v;
	ll w;
	bool operator<(const wv& rhs) const {
		return w > rhs.w;
	}
};

int N, T;
ll arr[MAX][MAX];
ll dist[4*MAX*MAX];
vector<wv> adj[4*MAX*MAX];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int index(int i, int j, int cnt) {
	return cnt*MAX*MAX + i*MAX + j;
}

void dijkstra(int st) {
	priority_queue<wv> pq;
	pq.push({st, 0});
	dist[st] = 0;
	while(!pq.empty()) {
		auto cur = pq.top();
		pq.pop();

		if(cur.w > dist[cur.v]) continue;
		for(auto &e : adj[cur.v]) {
			if(dist[e.v] > cur.w + e.w) {
				dist[e.v] = cur.w + e.w;
				pq.push({e.v, dist[e.v]});
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

	fill(dist, dist+4*MAX*MAX, INF);

	cin>>N>>T;
	for(int i = 1; i <= N; ++i) {
		for(int j = 1; j <= N; ++j) {
			cin>>arr[i][j];
		}
	}
	for(int i = 1; i <= N; ++i) {
		for(int j = 1; j <= N; ++j) {
			for(int k = 0; k <= 2; ++k) {
				for(int dir = 0; dir < 4; ++dir) {
					int x = i + dx[dir];
					int y = j + dy[dir];
					if(x < 1 || x > N || y < 1 || y > N) continue;

					if(k == 2) adj[index(i, j, k)].push_back({index(x, y, 0), arr[x][y] + T});
					else adj[index(i, j, k)].push_back({index(x, y, k+1), T});
				}
			}
		}
	}

	ll result = INF;
	dijkstra(index(1, 1, 0));
	result = min(result, dist[index(N, N, 0)]);
	result = min(result, dist[index(N, N, 1)]);
	result = min(result, dist[index(N, N, 2)]);
	
	cout<<result;

	return 0;
}