#include <bits/stdc++.h>

// 13547 수열과 쿼리 5

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

int N, M, rtN;
int arr[MAX], check[1000005], result[MAX];

struct Query {
	int l, r, idx;
	bool operator<(const Query &O) {
		if((l/rtN) == (O.l/rtN)) return r < O.r;
		return (l/rtN) < (O.l/rtN);
	}
};
Query query[MAX];

void input() {
	cin>>N;
	rtN = sqrt(N);
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
	int cnt = 0;
	for(int i = l; i <= r; ++i) {
		if(check[arr[i]]++ == 0) cnt++;
	}
	result[query[1].idx] = cnt;

	for(int i = 2; i <= M; ++i) {
		while(query[i].l > l) {
			if(check[arr[l++]]-- == 1) cnt--;
		}
		while(query[i].l < l) {
			if(check[arr[--l]]++ == 0) cnt++;
		}
		while(query[i].r > r) {
			if(check[arr[++r]]++ == 0) cnt++;
		}
		while(query[i].r < r) {
			if(check[arr[r--]]-- == 1) cnt--;
		}
		
		result[query[i].idx] = cnt;
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