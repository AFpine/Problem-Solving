#include <bits/stdc++.h>
 
// 14463 소가 길을 건너간 이유 9

// update 220818

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
const long long MOD = 9999991;
const int MAX = 100005;

int N;
pii arr[MAX];
int tree[4*MAX];

void update(int s, int e, int node, int pos) {
	if(pos > e || pos < s) return;
	if(s == e) {
		tree[node] += 1;
		return;
	}
	int mid = (s+e)/2;
	update(s, mid, node*2, pos);
	update(mid+1, e, node*2+1, pos);
	tree[node] = tree[node*2] + tree[node*2+1];
}

int query(int s, int e, int node, int l, int r) {
	if(l > e || r < s) return 0;
	if(l <= s && r >= e) return tree[node];
	int mid = (s+e)/2;
	return query(s, mid, node*2, l, r) + query(mid+1, e, node*2+1, l, r);
}

void input() {
	cin>>N;
	for(int i = 1; i <= 2*N; ++i) {
		int t;
		cin>>t;
		if(arr[t].first == 0) arr[t].first = i;
		else arr[t].second = i;
	}
}

void solve() {
	sort(arr+1, arr+1+N);


	int result = 0;
	for(int i = 1; i <= N; ++i) {
		result += query(1, 2*N, 1, arr[i].first, arr[i].second);
		update(1, 2*N, 1, arr[i].second);
	}
	
	cout<<result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}