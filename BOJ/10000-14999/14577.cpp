#include <bits/stdc++.h>

// 14577 일기예보

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
const int MAX = 200005;
const long long MOD = 1e9+7;

int N, M, cnt;
ll arr[MAX], temp[MAX], tree[4*MAX], inv[2*MAX], Q[MAX][3];
unordered_map<ll, int> H;
set<ll> S;

void update(int s, int e, int node, int pos, ll k) {
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

ll query(int s, int e, int node, int l, int r) {
	if(l > e || r < s) return 0;
	if(l <= s && r >= e) return tree[node];
	int mid = (s+e)/2;
	return query(s, mid, node*2, l, r) + query(mid+1, e, node*2+1, l, r);
}

ll binaryquery(int s, int e, int node, ll val) {
	if(s == e) return s;
	int mid = (s+e)/2;
	if(tree[node*2] >= val) return binaryquery(s, mid, node*2, val);
	else return binaryquery(mid+1, e, node*2+1, val-tree[node*2]);
}

void solve() {
	for(auto &s : S) {
		H[s] = ++cnt;
		inv[cnt] = s;
	}

	for(int i = 1; i <= N; ++i) {
		update(1, cnt, 1, H[arr[i]], 1);
	}

	for(int i = 1; i <= M; ++i) {
		int op = Q[i][0];
		if(op == 1) {
			update(1, cnt, 1, H[arr[Q[i][1]]], -1);
			arr[Q[i][1]] += Q[i][2];
			update(1, cnt, 1, H[arr[Q[i][1]]], 1);
		}
		else if(op == 2) {
			update(1, cnt, 1, H[arr[Q[i][1]]], -1);
			arr[Q[i][1]] -= Q[i][2];
			update(1, cnt, 1, H[arr[Q[i][1]]], 1);
		}
		else if(op == 3) {
			cout<<query(1, cnt, 1, H[Q[i][1]], H[Q[i][2]])<<'\n';
		}
		else {
			// ll val = N+1-Q[i][1];
			// int result = binaryquery(1, cnt, 1, val);
            int l = 1, r = cnt;
            while(l <= r) {
                int mid = (l+r)/2;
                if(query(1, cnt, 1, 1, mid) >= N+1-Q[i][1]) {
                    r = mid-1;
                }
                else {
                    l = mid+1;
                }
            }
			cout<<inv[l]<<'\n';
		}
	}
}

void input() {
	cin>>N>>M;
	for(int i = 1; i <= N; ++i) {
		cin>>arr[i];
		temp[i] = arr[i];
		S.insert(arr[i]);
	}

	for(int i = 1; i <= M; ++i) {
		cin>>Q[i][0];
		if(Q[i][0] == 1) {
			cin>>Q[i][1]>>Q[i][2];
			temp[Q[i][1]] += Q[i][2];
			S.insert(temp[Q[i][1]]);
		}
		else if(Q[i][0] == 2) {
			cin>>Q[i][1]>>Q[i][2];
			temp[Q[i][1]] -= Q[i][2];
			S.insert(temp[Q[i][1]]);
		}
		else if(Q[i][0] == 3) {
			cin>>Q[i][1]>>Q[i][2];
			S.insert(Q[i][1]);
			S.insert(Q[i][2]);
		}
		else {
			cin>>Q[i][1];
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