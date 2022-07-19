#include <bits/stdc++.h>

// 12899 데이터 구조

// update 220719

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<long long, long long> pll;
typedef pair<int,int> pii;

const int INF = 1e9+5;
const long long llINF = 1e18;
const long long minllINF = -1e18;
const int minINF = -2e9-1;
const int MAX = 2000005;
const long long MOD = 1e9+7;

int N;
int tree[4*MAX];

void update(int s, int e, int node, int pos, int k) {
	if(pos < s || pos > e) return;
	if(s == e) {
		tree[node] += k;
		return;
	}
	int mid = (s+e)/2;
	update(s, mid, node*2, pos, k);
	update(mid+1, e, node*2+1, pos, k);
	tree[node] = tree[node*2] + tree[node*2+1];
}

int kthquery(int s, int e, int node, int k) {
	if(s == e) return s;
	int mid = (s+e)/2;
	int pivot = tree[node*2];
	if(k <= pivot) return kthquery(s, mid, node*2, k);
	else return kthquery(mid+1, e, node*2+1, k-pivot);
}

void input() {
	cin>>N;
}

void solve() {
	while(N--) {
		int op, x;
		cin>>op>>x;
		if(op == 1) {
			update(1, MAX, 1, x, 1);
		}
		else {
			int temp = kthquery(1, MAX, 1, x);
			cout<<temp<<'\n';
			update(1, MAX, 1, temp, -1);
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