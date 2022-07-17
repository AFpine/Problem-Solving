#include <bits/stdc++.h>

// 13208 승현이와 승현이

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

int N, M, Q, costcnt, nodecnt, inv[MAX];
ll C[505], cost[MAX];
vector<int> adj[505];
vector<int> G[MAX];
pll lr[MAX];
pii qry[MAX];
int uf[MAX];
vector<pii> V;
map<pii, int> nodeM;

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
	cin>>N>>M;
	for(int i = 1; i <= N; ++i) cin>>C[i];
	for(int i = 1; i <= M; ++i) {
		int a, b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	cin>>Q;
	for(int i = 1; i <= Q; ++i) {
		cin>>qry[i].first>>qry[i].second;
	}

	set<ll> S;
	for(int i = 1; i <= N; ++i) {
		for(int j = 1; j <= N; ++j) {
			ll temp = C[i] * C[j];
			V.push_back({temp, (i*d + j)});
			S.insert(temp);
			// nodeM[{i, j}] = ++nodecnt;
		}
	}
	
	map<ll, int> maping;
	for(auto &s : S) {
		maping[s] = ++costcnt;
		cost[costcnt] = s;
	}
	//costcnt : 서로 다른 cost의 수 (cost[1, costcnt])
	
	for(auto &v : V) {
		v.first = maping[v.first];
	}

	sort(V.begin(), V.end());

	for(int i = 1; i <= Q; ++i) {
		lr[i].first = 1;
		lr[i].second = costcnt;
	}
}

void solve() {
	int mid[MAX] = {0};
	while(true) {
		bool flag = false;
		for(int i = 0; i <= costcnt; ++i) G[i].clear();

		for(int i = 1; i <= Q; ++i) {
			if(lr[i].first <= lr[i].second) {
				flag = true;
				G[(lr[i].first+lr[i].second)/2].push_back(i);
			}
		}
		if(!flag) break;

		fill(uf, uf+MAX, -1);
		bool opened[MAX] = {false};
		for(int i = 1, j = 0; i <= costcnt; ++i) {
			while(j < V.size() && V[j].first == i) {
				auto cur = V[j++].second;
				int u = cur / d, v = cur % d;
				opened[cur] = true;
				for(auto &e : adj[u]) {
					if(opened[e*d + v]) merge((e*d + v), cur);
				}
				for(auto &e : adj[v]) {
					if(opened[u*d + e]) merge((u*d + e), cur);
				}
			}

			for(int k : G[i]) {
				auto q = qry[k];
				int a = q.first*d + q.second, b = q.second*d + q.first;
				if(opened[a] && opened[b] && (find(a) == find(b))) {
					mid[k] = i;
					lr[k].second = i-1;
				}
				else lr[k].first = i+1;
			}
		}
	}
	for(int i = 1; i <= Q; ++i) {
		cout<<cost[mid[i]]<<'\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	input();
	solve();

	return 0;
}