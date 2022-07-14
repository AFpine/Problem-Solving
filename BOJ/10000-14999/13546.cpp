#include <bits/stdc++.h>

// 13546 수열과 쿼리 4

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
const int MAX = 100005;
const long long MOD = 1e9+7;

const int sq = 300;
const int sz = 100005/sq + 305;

int N, K, M;
int arr[MAX], result[MAX];
int cnt[MAX], bucket[sz];
list<int> dq[MAX];

struct Query {
	int l, r, idx;
	bool operator<(const Query &O) {
		if((l/sq) == (O.l/sq)) return r < O.r;
		return l < O.l;
	}
};
Query query[MAX];

void Plus(int x, int dir) {
	int now = 0;
	if(!dq[arr[x]].empty()) {
		now = dq[arr[x]].front() - dq[arr[x]].back();
		cnt[now]--;
		bucket[now/sq]--;
	}

	if(dir == 1) dq[arr[x]].push_front(x);
	else dq[arr[x]].push_back(x);

	now = dq[arr[x]].front() - dq[arr[x]].back();
	cnt[now]++;
	bucket[now/sq]++;
}

void Minus(int x, int dir) {
	int now = 0;
	now = dq[arr[x]].front() - dq[arr[x]].back();
	cnt[now]--;
	bucket[now/sq]--;

	if(dir == 1) dq[arr[x]].pop_front();
	else dq[arr[x]].pop_back();

	if(!dq[arr[x]].empty()) {
		now = dq[arr[x]].front() - dq[arr[x]].back();
		cnt[now]++;
		bucket[now/sq]++;
	}
}

int qry() {
	for(int i = sz; i >= 0; --i) {
		if(bucket[i] == 0) continue;
		for(int j = sq-1; j >= 0; --j) {
			if(cnt[i*sq + j] > 0) return i*sq + j;
		}
	}
	return 0;
}

void input() {
	cin>>N>>K;
	for(int i = 1; i <= N; ++i) cin>>arr[i];

	cin>>M;
	for(int i = 1; i <= M; ++i) {
		cin>>query[i].l>>query[i].r;
		query[i].idx = i;
	}
	sort(query+1, query+1+M);
}

void solve() {
	//first query is naive
	int l = query[1].l, r = query[1].r;
	for(int i = l; i <= r; ++i) {
		Plus(i, 1);
	}
	result[query[1].idx] = qry();

	for(int i = 2; i <= M; ++i) {
		while(query[i].l < l) { //increase
			Plus(--l, 0);
		}
		while(query[i].r > r) { //increase
			Plus(++r, 1);
		}
		while(query[i].l > l) {	//decrease
			Minus(l++, 0);
		}
		while(query[i].r < r) { //decrease
			Minus(r--, 1);
		}
		result[query[i].idx] = qry();
	}

	for(int i = 1; i <= M; ++i) cout<<result[i]<<'\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	input();
	solve();

	return 0;
}