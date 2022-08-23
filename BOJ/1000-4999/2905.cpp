#include <bits/stdc++.h>
 
// 2905 홍준이와 울타리

// update 220823

using namespace std;
#define sz(a) (int)(a.size()) 
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
const long long MOD = 1000000007;
const int MAX = 1000005;

int N, X, H[MAX], mH[MAX];
bool check[MAX];
int mintree[4*MAX], maxtree[4*MAX], lazy[4*MAX];

void mininit(int s, int e, int node) {
	if(s == e) {
		mintree[node] = H[s];
		return;
	}
	int mid = (s+e)/2;
	mininit(s, mid, node*2);
	mininit(mid+1, e, node*2+1);
	mintree[node] = min(mintree[node*2], mintree[node*2+1]);
}

int minquery(int s, int e, int node, int l, int r) {
	if(l > e || r < s) return INF;
	if(l <= s && r >= e) return mintree[node];
	int mid = (s+e)/2;
	return min(minquery(s, mid, node*2, l, r), minquery(mid+1, e, node*2+1, l, r));
}

void propagate(int s, int e, int node) {
	if(lazy[node]) {
		maxtree[node] = max(maxtree[node], lazy[node]);
		if(s != e) {
			lazy[node*2] = max(lazy[node*2], lazy[node]);
			lazy[node*2+1] = max(lazy[node*2+1], lazy[node]);
		}
		lazy[node] = 0;
	}
}

void maxupdate(int s, int e, int node, int l, int r, int k) {
	propagate(s, e, node);
	if(l > e || r < s) return;
	if(l <= s && r >= e) {
		lazy[node] = k;
		propagate(s, e, node);
		return;
	}
	int mid = (s+e)/2;
	maxupdate(s, mid, node*2, l, r, k);
	maxupdate(mid+1, e, node*2+1, l, r, k);
	maxtree[node] = max(maxtree[node*2], maxtree[node*2+1]);
}

int maxquery(int s, int e, int node, int pos) {
	propagate(s, e, node);
	if(pos > e || pos < s) return -1;
	if(s == e) return maxtree[node];
	int mid = (s+e)/2;
	return max(maxquery(s, mid, node*2, pos), maxquery(mid+1, e, node*2+1, pos));
}

void input() {
	cin>>N>>X;
	for(int i = 1; i <= N; ++i) cin>>H[i];
}

void solve() {
	ll res1 = 0, res2 = 0;

	mininit(1, N, 1);
	for(int i = 1; i <= N-X+1; ++i) {
		int t = minquery(1, N, 1, i, i+X-1);
		maxupdate(1, N, 1, i, i+X-1, t);
	}

	for(int i = 1; i <= N; ++i) {
		mH[i] = maxquery(1, N, 1, i);
		res1 += H[i] - mH[i];
	}

	int idx = 1;
	while(idx <= N) {
		if(!check[idx]) {
			res2++;
			int t = idx;
			while(t <= idx+X-1 && t <= N) {
				if(mH[t] == mH[idx]) check[t] = true;
				else break;
				t++;
			}
			idx = t;
		}
		else idx++;
	}

	cout<<res1<<'\n'<<res2<<'\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}