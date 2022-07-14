#include <bits/stdc++.h>

// 2843 마블

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
const int MAX = 300005;
const long long MOD = 1e9+7;

int N, Q;
int out[MAX], uf[MAX];
bool cycle[MAX], selected[MAX];
stack<pii> query;
stack<int> result;

int find(int a) {
	if(uf[a] < 0) return a;
	return uf[a] = find(uf[a]);
}

//a is root(in this problem, last vertex)
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if(a == b) return;
	uf[a] += uf[b];
	uf[b] = a;
}

void solve() {
	for(int i = 1; i <= N; ++i) {
		if(selected[i] || (out[i] == 0)) continue;

		if(find(out[i]) == find(i)) {
			cycle[find(out[i])] = true;
		}
		merge(out[i], i);
	}

	while(!query.empty()) {
		pii q = query.top();
		query.pop();

		if(q.first == 1) {
			if(cycle[find(q.second)]) {
				result.push(-1);
			}
			else {
				result.push(find(q.second));
			}
		}
		else {
			if(find(out[q.second]) == find(q.second)) {
				cycle[find(out[q.second])] = true;
			}
			merge(out[q.second], q.second);
		}
	}

	while(!result.empty()) {
		if(result.top() == -1) {
			cout<<"CIKLUS\n";
		}
		else {
			cout<<result.top()<<'\n';
		}
		result.pop();
	}
}

void input() {
	cin>>N;
	for(int i = 1; i <= N; ++i) cin>>out[i];
	cin>>Q;
	while(Q--) {
		int a, b;
		cin>>a>>b;
		query.push({a,b});
		if(a == 2) {
			selected[b] = true;
		}
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