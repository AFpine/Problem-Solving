#include <bits/stdc++.h>

// 15908 복구

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
const int MAX = 100005;
const long long MOD = 1e9+7;

int N;
int A[MAX], B[MAX];
bool restore[MAX];
int psum1[MAX];
int tree[4*MAX];

void update(int s, int e, int node, int pos) {
	if(pos > e || pos < s) return;
	if(s == e) {
		tree[node]++;
		return;
	}
	int mid = (s+e) / 2;
	update(s, mid, node*2, pos);
	update(mid+1, e, node*2+1, pos);
	tree[node] = tree[node*2] + tree[node*2+1];
}

int query(int s, int e, int node, int l, int r) {
	if(l > e || r < s) return 0;
	if(l <= s && r >= e) return tree[node];
	int mid = (s+e) / 2;
	return query(s, mid, node*2, l, r) + query(mid+1, e, node*2+1, l, r);
}

void solve() {
	int l = 0, r = 100000;
	int result = r;
	while(l <= r) {
		fill(restore, restore+MAX, false);
		fill(psum1, psum1+MAX, 0);
		fill(tree, tree+4*MAX, 0);

		restore[N+1] = true;
		update(1, N+1, 1, N+1);

		int mid = (l+r) / 2;

		for(int i = 1; i <= N; ++i) {
			psum1[i] = (B[i] > mid ? 1 : 0);
			psum1[i] += psum1[i-1];
		}

		for(int i = N; i >= 1; --i) {
			if(restore[i+1] && B[i] <= mid) {
				restore[i] = true;
			}
			else {
				int lk = i + A[i] - 1;
				int rk = N;

				int nl = i, nr = N;
				while(nl <= nr) {
					int nm = (nl+nr) / 2;
					
					if(psum1[nm] - psum1[i] <= A[i]-1) {
						rk = nm;
						nl = nm + 1;
					}
					else {
						nr = nm - 1;
					}
				}
				if(lk > rk) restore[i] = false;
				else if(query(1, N+1, 1, lk+1, rk+1) > 0) restore[i] = true;
				else restore[i] = false;
			}
			if(restore[i]) update(1, N+1, 1, i);
		}

		if(restore[1]) {
			result = mid;
			r = mid-1;
		}
		else {
			l = mid+1;
		}
	}
	cout<<result;
}

void input() {
	cin>>N;
	for(int i = 1; i <= N; ++i) cin>>A[i];
	for(int i = 1; i <= N; ++i) cin>>B[i];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	input();
	solve();

	return 0;
}