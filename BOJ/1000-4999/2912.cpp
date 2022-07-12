#include <bits/stdc++.h>

// 2912 백설공주와 난쟁이

// update 220712

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

int N, C, M;
int arr[MAX];
vector<int> tree[4*MAX];
vector<int> CV[10005];
vector<int> S;

void seginit(int s, int e, int node) {
	if(s == e) {
		tree[node].push_back(arr[s]);
		return;
	}
	int mid = (s+e) / 2;

	seginit(s, mid, node*2);
	seginit(mid+1, e, node*2+1);

	tree[node].resize(tree[node*2].size() + tree[node*2+1].size());

	merge(tree[node*2].begin(), tree[node*2].end(), tree[node*2+1].begin(), tree[node*2+1].end(), tree[node].begin());
}

void query(int s, int e, int node, int l, int r) {
	if(l > e || r < s) return;
	if(l <= s && r >= e) {
		int k = tree[node].size();
		if(s == e) {
			S.push_back(tree[node][0]);
		}
		else if(tree[node][k/2-1] == tree[node][k/2] || tree[node][k/2] == tree[node][k/2+1]) {
			S.push_back(tree[node][k/2]);
		}
		return;
	}
	int mid = (s+e) / 2;
	query(s, mid, node*2, l, r);
	query(mid+1, e, node*2+1, l, r);
}

void solve() {
	cin>>M;
	while(M--) {
		int a, b;
		bool flag = false;

		cin>>a>>b;
		
		query(1, N, 1, a, b);

		for(auto &s : S) {
			int temp = upper_bound(CV[s].begin(), CV[s].end(), b) - lower_bound(CV[s].begin(), CV[s].end(), a);
			if(temp > ((b - a + 1)/2)) {
				cout<<"yes "<<s<<'\n';
				flag = true;
				break;
			}
		}
		
		if(!flag) cout<<"no\n";

		S.clear();
	}
}

void input() {
	cin>>N>>C;
	for(int i = 1; i <= N; ++i) {
		cin>>arr[i];
		CV[arr[i]].push_back(i);
	}
	
	seginit(1, N, 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}