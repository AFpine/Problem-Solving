#include <bits/stdc++.h>

// 5817 고통받는 난쟁이들

// 221015

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
const long long MOD = 1e9+7;
const int MAX = 202020;

int N, M, seq[MAX], pos[MAX];
int mintree[4*MAX], maxtree[4*MAX];

void minupdate(int s, int e, int node, int p, int k) {
	if(p > e || p < s) return;
	if(s == e) {
		mintree[node] = k;
		return;
	}
	int mid = (s+e)/2;
	minupdate(s, mid, node*2, p, k);
	minupdate(mid+1, e, node*2+1, p, k);
	mintree[node] = min(mintree[node*2], mintree[node*2+1]);
}

int minquery(int s, int e, int node, int l, int r) {
	if(l > e || r < s) return INF;
	if(l <= s && r >= e) return mintree[node];
	int mid = (s+e)/2;
	return min(minquery(s, mid, node*2, l, r), minquery(mid+1, e, node*2+1, l, r));
}

void maxupdate(int s, int e, int node, int p, int k) {
	if(p > e || p < s) return;
	if(s == e) {
		maxtree[node] = k;
		return;
	}
	int mid = (s+e)/2;
	maxupdate(s, mid, node*2, p, k);
	maxupdate(mid+1, e, node*2+1, p, k);
	maxtree[node] = max(maxtree[node*2], maxtree[node*2+1]);
}

int maxquery(int s, int e, int node, int l, int r) {
	if(l > e || r < s) return -1;
	if(l <= s && r >= e) return maxtree[node];
	int mid = (s+e)/2;
	return max(maxquery(s, mid, node*2, l, r), maxquery(mid+1, e, node*2+1, l, r));
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill(mintree, mintree + 4*MAX, INF);
	fill(maxtree, maxtree + 4*MAX, -1);

	cin>>N>>M;
	for(int i = 1; i <= N; ++i) {
		cin>>seq[i];
		pos[seq[i]] = i;
        minupdate(1, N, 1, seq[i], i);
        maxupdate(1, N, 1, seq[i], i);
	}

	while(M--) {
		int op, a, b;
		cin>>op>>a>>b;
		if(op == 1) {
			a = seq[a];
			b = seq[b];
			minupdate(1, N, 1, a, pos[b]);
			minupdate(1, N, 1, b, pos[a]);
			maxupdate(1, N, 1, a, pos[b]);
			maxupdate(1, N, 1, b, pos[a]);
			swap(seq[pos[a]], seq[pos[b]]);
			swap(pos[a], pos[b]);
		}
		else {
			int pivot = b-a;
			int res = maxquery(1, N, 1, a, b) - minquery(1, N, 1, a, b);
			if(res == pivot) cout<<"YES\n";
			else cout<<"NO\n";
		}
	}
	return 0;
}