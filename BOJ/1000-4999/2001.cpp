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
const long long MOD = 1e9+9;
const int MAX = 111;

int N, M, K;
bool visited[MAX][1<<15];
vector<pii> adj[MAX];
map<int, int> mp;
int result;

void bfs() {
	queue<pii> Q;

	visited[0][0] = true;
	Q.push({0, 0});

	while(!Q.empty()) {
		auto cur = Q.front();
		Q.pop();
		
		auto tmp = cur.second;
		auto cnt = 0;
		while(tmp) {
			if(tmp % 2) cnt++;
			tmp /= 2;
		}
		
		for(auto &e : adj[cur.first]) {
			if(visited[e.first][cur.second]) continue;
			if(e.second < cnt) continue;
			visited[e.first][cur.second] = true;
			Q.push({e.first, cur.second});
		}
		if(mp[cur.first] > 0) {
			for(auto &e : adj[cur.first]) {
				if(visited[e.first][cur.second | (1 << mp[cur.first])]) continue;
				if(e.second < (cnt+1)) continue;
				visited[e.first][cur.second | (1 << mp[cur.first])] = true;
				Q.push({e.first, cur.second | (1 << mp[cur.first])});
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

	cin>>N>>M>>K;
	for(int i = 1; i <= K; ++i) {
		int t;
		cin>>t;
		mp[t] = i;
	}
	for(int i = 1; i <= M; ++i) {
		int a, b, c;
		cin>>a>>b>>c;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}

	adj[0].push_back({1, 111});
	adj[1].push_back({0, 111});
	bfs();

	for(int i = 0; i < (1 << (K+1)); ++i) {
		if(visited[0][i]) {
			int t = i;
			int cnt = 0;
			while(t) {
				if(t % 2) cnt++;
				t /= 2;
			}
			result = max(result, cnt);
		}
	}

	cout<<result;

	return 0;
}