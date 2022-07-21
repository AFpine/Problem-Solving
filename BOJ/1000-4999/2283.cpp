#include <bits/stdc++.h>
 
// 2283 구간 자르기

// update 220720
 
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef pair<double, double> pdd;
 
const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 1000005;
const long long MOD = 1e9+7;

int N, K;
ll psum[MAX];
ll tree[4*MAX], lazy[4*MAX];

void propagate(int s, int e, int node) {
	if(lazy[node] != 0) {
		tree[node] += (s-e+1) * lazy[node];
		if(s != e) {
			lazy[node*2] += lazy[node];
			lazy[node*2+1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int s, int e, int node, int l, int r, ll k) {
	propagate(s, e, node);
	if(l > e || r < s) return;
	if(l <= s && r >= e) {
		lazy[node] += k;
		propagate(s, e, node);
		return;
	}
	int mid = (s+e)/2;
	update(s, mid, node*2, l, r, k);
	update(mid+1, e, node*2+1, l, r, k);
	tree[node] = tree[node*2] + tree[node*2+1];
}

ll sum(int s, int e, int node, int pos) {
	propagate(s, e, node);
	if(pos > e || pos < s) return 0;
	if(s == e) return tree[node];
	int mid = (s+e)/2;
	return sum(s, mid, node*2, pos) + sum(mid+1, e, node*2+1, pos);
}

void input() {
	cin>>N>>K;

	for(int i = 1; i <= N; ++i) {
		int a, b;
		cin>>a>>b;
		update(0, 1000000, 1, a+1, b, 1);
	}

	for(int i = 0; i <= 1000000; ++i) {
		psum[i] = sum(0, 1000000, 1, i);
		if(i > 0) psum[i] += psum[i-1];
	}
}

void solve() {
	pii result = {-1, -1};

	for(int i = 0; i <= 1000000; ++i) {
		int l = i, r = 1000000;
		int res = -1;
		while(l <= r) {
			int mid = (l+r)/2;

			if(psum[mid] - psum[i] >= K) {
				res = mid;
				r = mid-1;
			}
			else l = mid+1;
		}
		if(psum[res] - psum[i] == K) {
			result.first = i;
			result.second = res;
			break;
		}
	}

	if(result.first == -1 && result.second == -1) cout<<"0 0";
	else cout<<result.first<<" "<<result.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	input();
	solve();

	return 0;
}