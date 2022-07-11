#include <bits/stdc++.h>

// 14165 Team Building

// update 220711

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<long long, long long> pll;
typedef pair<int,int> pii;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 1005;
const long long MOD = 1e9+9;

int N, M, K;
int fj[MAX], fp[MAX];
//dp[i][j][k] : 구간 [i,N), [j,M) 에서 조건을 만족하는 K길이의 부분수열을 고를 수 있는 경우의 수
ll dp[MAX][MAX][11];
ll psum[MAX][MAX][11];

void solve() {
	for(int k = 1; k <= K; ++k) {
		for(int i = 1; i <= N; ++i) {
			for(int j = 1; j <= M; ++j) {
				if(fj[i] > fp[j]) {
					if(k > 1) dp[i][j][k] = psum[i][j][k-1];
					else dp[i][j][k] = 1;
				}
			}
		}
		for(int i = 1; i <= N; ++i) {
			for(int j = 1; j <= M; ++j) {
				psum[i+1][j+1][k] = (psum[i][j+1][k] + psum[i+1][j][k] - psum[i][j][k] + dp[i][j][k] + MOD) % MOD;
			}
		}
	}
	cout<<psum[N+1][M+1][K] % MOD<<'\n';
}

void input() {
	cin>>N>>M>>K;
	for(int i = 1; i <= N; ++i) cin>>fj[i];
	for(int i = 1; i <= M; ++i) cin>>fp[i];

	sort(fj+1, fj+1+N);
	sort(fp+1, fp+1+M);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}