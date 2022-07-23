#include <bits/stdc++.h>
 
// 1273 샷

// update 220723

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef pair<long double, long double> pdd;
 
const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const long long MOD = 1e9+7;
const int MAXN = 300005;
const int MAXH = 3000005;

int N, M;
int idx[MAXN];
ll psum[MAXH];
int tree[4*MAXH];

void seginit(int s, int e, int node) {
	if(s == e) {
		tree[node] = 1;
		return;
	}
	int mid = (s+e)/2;
	seginit(s, mid, node*2);
	seginit(mid+1, e, node*2+1);
	tree[node] = tree[node*2] + tree[node*2+1];
}

void update(int s, int e, int node, int pos, int k) {
	if(pos > e || pos < s) return;
	if(s == e) {
		tree[node] += k;
		return;
	}
	int mid = (s+e)/2;
	update(s, mid, node*2, pos, k);
	update(mid+1, e, node*2+1, pos, k);
	tree[node] = tree[node*2] + tree[node*2+1];
}

int query(int s, int e, int node, int k) {
	if(s == e) return s;
	int mid = (s+e)/2;
	if(tree[node*2] >= k) return query(s, mid, node*2, k);
	else return query(mid+1, e, node*2+1, k-tree[node*2]);
}

void input() {
	cin>>N;
	ll temp;
	for(int i = 1; i <= N; ++i) {
		cin>>temp;
		psum[idx[i] + 1] += 1;
		psum[idx[i] + temp + 1] -= 1;
		idx[i] += temp;
	}
	for(int i = 1; i <= N; ++i) {
		cin>>temp;
		psum[idx[i] + 1] += 2;
		psum[idx[i] + temp + 1] -= 2;
		idx[i] += temp;
	}
	for(int i = 1; i <= N; ++i) {
		cin>>temp;
		psum[idx[i] + 1] += 5;
		psum[idx[i] + temp + 1] -= 5;
		idx[i] += temp;
	}
	for(int i = 1; i < MAXH; ++i) {
		psum[i] += psum[i-1];
	}
}

void solve() {
	seginit(1, MAXH-1, 1);

	cin>>M;
	int h;
	while(M--) {
		cin>>h;
		int p = query(1, MAXH-1, 1, h);
		update(1, MAXH-1, 1, p, -1);

		cout<<psum[p]<<'\n';
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