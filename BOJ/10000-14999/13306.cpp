#include <bits/stdc++.h>

// 13306 트리

// update 220713

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<long long, long long> pll;
typedef pair<int,int> pii;

const int INF = 1e9+5;
const long long llINF = 1e18;
const long long minllINF = -1e18;
const int minINF = -2e9-1;
const int MAX = 400005;
const long long MOD = 1e9+7;

int N, Q;
int uf[MAX];
int seq[MAX];
int parent[MAX];
stack<int> Q1;
stack<pii> Q2;
stack<int> result;

int find(int a) {
	if(uf[a] < 0) return a;
	return uf[a] = find(uf[a]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if(a == b) return;
	uf[b] = a;
}

void solve() {
	for(int i = 0; i < Q+N-1; ++i) {
		if(seq[i] == 0) {
			int a = Q1.top();
			Q1.pop();
			merge(parent[a], a);
		}
		else {
			pii a = Q2.top();
			Q2.pop();
			if(find(a.first) == find(a.second)) result.push(1);
			else result.push(0);
		}
	}

	while(!result.empty()) {
		if(result.top() == 1) {
			cout<<"YES\n";
		}
		else {
			cout<<"NO\n";
		}
		result.pop();
	}
}

void input() {
	fill(uf, uf+MAX, -1);

	cin>>N>>Q;
	for(int i = 2; i <= N; ++i) {
		int a;
		cin>>a;
		parent[i] = a;
	}

	int q = Q + N-1;
	while(q--) {
		int x;
		int a,b;
		cin>>x;
		seq[q] = x;
		if(x == 0) {
			cin>>a;
			Q1.push(a);
		}
		else {
			cin>>a>>b;
			Q2.push({a,b});
		}
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