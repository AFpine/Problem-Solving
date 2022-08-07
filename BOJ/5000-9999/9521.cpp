#include <bits/stdc++.h>

// 9521 색칠 공부

// update 220807

using namespace std;
#define sz(a) (int)(a.size())
typedef long long ll;
typedef long double ld;
typedef pair<long long, long long> pll;
typedef pair<double, double> pdd;
typedef pair<int,int> pii;

const int INF = 1e9+5;
const long long llINF = 1e18;
const long long minllINF = -1e18;
const int minINF = -2e9-1;
const long long MOD = 1000000007;
const int MAX = 1000005;

int N, K, cnt;
int f[MAX], visited[MAX];
ll dp[MAX], powK_1[MAX];
ll result = 1;

void init() {
	powK_1[0] = 1;
	powK_1[1] = K-1;
	for(int i = 2; i <= N; ++i) {
		powK_1[i] = (powK_1[i-1] * (1LL*K-1)) % MOD;
	}
	dp[0] = 1;
	dp[1] = K;
	dp[2] = K * (1LL*K - 1);
	dp[3] = dp[2] * (1LL*K - 2);
	for(int i = 4; i <= N; ++i) {
		dp[i] = (K * powK_1[i-1] - dp[i-1]) % MOD;
	}
}

void input() {
	cin>>N>>K;
	for(int i = 1; i <= N; ++i) {
		cin>>f[i];
	}
}

void solve() {
	int cyclelen = 0;
	cnt = 1;
	for(int i = 1; i <= N; ++i) {
		if(visited[i]) continue;
		int cur = i;
		while(true) {
			visited[cur] = cnt++;
			cur = f[cur];
			if(visited[cur]) {
				if(visited[cur] >= visited[i]) {
					int	len = cnt - visited[cur];
					result = (result * dp[len]) % MOD;
					cyclelen += len;
				}
				break;
			}
		}
	}
	result = (result*(powK_1[N-cyclelen])) % MOD;

	cout<<result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	init();
	solve();

	return 0;
}