#include <bits/stdc++.h>

// 13448 SW 역량 테스트

// update 220711

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
const long long MOD = 1e9+9;

int N, T;
int M[MAX], P[MAX], R[MAX];
int seq[MAX];
ll dp[55][MAX];

ll recur(int idx, int t) {
	ll &ret = dp[idx][t];
	if(ret != -llINF) return ret;
	if(idx > N) return ret = 0;

	ret = recur(idx+1, t);

	if(t + R[seq[idx]] <= T) {
		ret = max(ret, recur(idx+1, t + R[seq[idx]]) + (M[seq[idx]] - 1LL*(t+R[seq[idx]])*P[seq[idx]]));
	}

	return ret;
}

void solve() {
	ll result = recur(1, 0);
	cout<<result;
}

void input() {
	cin>>N>>T;

	for(int i = 0; i <= N; ++i) fill(dp[i], dp[i] + MAX, minllINF);

	for(int i = 1; i <= N; ++i) seq[i] = i;
	for(int i = 1; i <= N; ++i) cin>>M[i];
	for(int i = 1; i <= N; ++i) cin>>P[i];
	for(int i = 1; i <= N; ++i) cin>>R[i];

	sort(seq+1, seq+1+N, [] (int a, int b) {
		return 1LL*R[a]*P[b] < 1LL*R[b]*P[a];
	});
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}