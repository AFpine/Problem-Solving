#include <bits/stdc++.h>
 
// 10715 JOI 공원

// update 220808

using namespace std;
#define sz(a) (int)(a.size()) 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef pair<long double, long double> pdd;
typedef pair<int, char> pic;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const long long MOD = 9999991;
const int MAX = 100005;

struct comp {
	bool operator() (pii a, pii b) {
		return a.second > b.second;
	}
};

int N, M, C;
ll total;
vector<pii> edge[MAX];
int dist[MAX];
bool visited[MAX];

priority_queue<pii, vector<pii>, comp> pq;

void input() {
	cin>>N>>M>>C;
	for(int i = 1; i <= M; ++i) {
		int a, b, c;
		cin>>a>>b>>c;
		edge[a].push_back({b, c});
		edge[b].push_back({a, c});
		total += c;
	}
}

void solve() {
	ll result = total;

	fill(dist, dist+MAX, INF);
	dist[1] = 0;
	pq.push({1, 0});

	int maxdist = 0;
	while(!pq.empty()) {
		auto cur = pq.top().first;
		auto curdist = pq.top().second;
		pq.pop();

		if(curdist > dist[cur]) continue;
		visited[cur] = true;
		for(auto &e : edge[cur]) {
			if(visited[e.first]) total -= e.second;
		}
		result = min(result, 1LL*curdist*C + total);

		for(auto &e : edge[cur]) {
			if(dist[e.first] > curdist + e.second) {
				dist[e.first] = curdist + e.second;
				pq.push({e.first, dist[e.first]});
			}
		}
	}

	cout<<result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}