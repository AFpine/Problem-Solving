#include <bits/stdc++.h>

// 12012 Closing the Farm (Gold)

// update 220714

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<long long, long long> pll;
typedef pair<int,int> pii;

const int INF = 1e9+5;
const long long llINF = 1e18;
const long long minllINF = -1e18;
const int minINF = -2e9-1;
const int MAX = 200005;
const long long MOD = 1e9+7;

int N, M;
vector<int> adj[MAX];
stack<int> Q;
stack<bool> result;
bool selected[MAX];
int uf[MAX];

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

void solve() {
	int cnt = 1;
	while(!Q.empty()) {
		int q = Q.top();
		Q.pop();

		selected[q] = true;
		for(auto &e : adj[q]) {
			if(selected[e]) merge(q, e);
		}
		
		if(uf[find(q)] == -cnt) result.push(1);
		else result.push(0);
		cnt++;
	}

	while(!result.empty()) {
		if(result.top() == true) cout<<"YES\n";
		else cout<<"NO\n";
		result.pop();
	}
}

void input() {
	cin>>N>>M;
	for(int i = 1; i <= M; ++i) {
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for(int i = 1; i <= N; ++i) {
		int q;
		cin>>q;
		Q.push(q);
	}

	fill(uf, uf+MAX, -1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	input();

	solve();

	return 0;
}