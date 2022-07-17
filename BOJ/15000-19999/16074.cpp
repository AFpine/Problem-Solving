#include <bits/stdc++.h>

// 16074 Mountaineers

// update 220717

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<long long, long long> pll;
typedef pair<int,int> pii;

const int INF = 1e9+5;
const long long llINF = 1e18;
const long long minllINF = -1e18;
const int minINF = -2e9-1;
const int MAX = 300005;
const long long MOD = 1e9+7;
const int d = 505;

int M, N, Q, heightcnt;
int grid[505][505], uf[MAX];
pii qry[100005], lr[100005];
vector<int> adj[MAX];
vector<pii> V;
vector<int> G[MAX];
int result[MAX];
map<int, int> heightM;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int find(int a) {
	if(uf[a] < 0) return a;
	return uf[a] = find(uf[a]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if(a == b) return;
	uf[a] += uf[b];
	uf[b] = a;
}

void input() {
	set<int> S;
	cin>>M>>N>>Q;
	for(int i = 1; i <= M; ++i) {
		for(int j = 1; j <= N; ++j) {
			cin>>grid[i][j];
			S.insert(grid[i][j]);
			V.push_back({grid[i][j], (i*d + j)});
		}
	}

	for(int i = 1; i <= M; ++i) {
		for(int j = 1; j <= N; ++j) {
			for(int dir = 0; dir < 4; ++dir) {
				int x = i + dx[dir];
				int y = j + dy[dir];
				if(x < 1 || x > M || y < 1 || y > N) continue;
				adj[i*d + j].push_back(x*d + y);
			}
		}
	}

	map<int, int> maping;
	for(auto &s : S) {
		maping[s] = ++heightcnt;
		heightM[heightcnt] = s;
	}
	for(auto &v : V) {
		v.first = maping[v.first];
	}
	sort(V.begin(), V.end());

	for(int i = 1; i <= Q; ++i) {
		int x1,x2,y1,y2;
		cin>>x1>>y1>>x2>>y2;
		qry[i].first = (x1*d + y1);
		qry[i].second = (x2*d + y2);
	}

	for(int i = 1; i <= Q; ++i) {
		lr[i].first = 1;
		lr[i].second = heightcnt;
	}
}	

void solve() {
	while(true) {
		bool flag = false;
		for(int i = 1; i <= heightcnt; ++i) G[i].clear();
		for(int i = 1; i <= Q; ++i) {
			if(lr[i].first <= lr[i].second) {
				flag = true;
				G[(lr[i].first + lr[i].second)/2].push_back(i);
			}
		}
		if(!flag) break;

		fill(uf, uf+MAX, -1);
		bool opened[MAX] = {false};
		for(int i = 1, j = 0; i <= heightcnt; ++i) {
			while(j < V.size() && V[j].first == i) {
				int cur = V[j++].second;
				opened[cur] = true;
				for(auto &e : adj[cur]) {
					if(opened[e]) merge(cur, e);
				}
			}

			for(auto &k : G[i]) {
				auto cur = qry[k];
				if(opened[cur.first] && opened[cur.second] && find(cur.first) == find(cur.second)) {
					result[k] = i;
					lr[k].second = i-1;
				}
				else lr[k].first = i+1;
			}
		}
	}
	for(int i = 1; i <= Q; ++i) cout<<heightM[result[i]]<<'\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	input();
	solve();

	return 0;
}