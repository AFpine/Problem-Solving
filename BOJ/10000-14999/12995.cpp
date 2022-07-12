#include <bits/stdc++.h>

// 12995 트리나라

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
const int MAX = 55;
const long long MOD = 1e9+7;

int N, K;
ll dp[MAX][MAX];
vector<int> adj[MAX];
vector<int> child[MAX];
bool selected[MAX];

void dfs(int cur) {
	for(auto &e : adj[cur]) {
		if(!selected[e]) {
			selected[e] = true;
			child[cur].push_back(e);
			dfs(e);
		}
	}
}

void DP(int cur) {
	ll temp[MAX][MAX] = {0};
	int cnt = 0;

	for(auto &e : child[cur]) {
		//자식 e에 대한 dp값을 먼저 구함
		DP(e);
		if(cnt == 0) {
			//첫(제일 왼쪽) 자식일 때는 그냥 그 자식의 dp값을 가져온다
			for(int k = 1; k <= K; ++k) {
				temp[cnt][k] = dp[e][k-1];
			}
		}
		else {	//첫 자식이 아닐 때
			for(int k = 0; k <= K; ++k) {
				//현재 자식이 아닌, 그 전의 자식들에서만 선택할 때 (누적 합)
				temp[cnt][k] = temp[cnt-1][k];
				for(int i = 1; i < k; ++i) {
					//현재 자식에서 i개를 선택하면, 그 전의 자식들에서는 알아서 잘 k-i개를 선택할 것
					//자식은 무조건 1개 이상, k(루트를 포함한 수)개 미만 선택해야 한다
					temp[cnt][k] = (temp[cnt][k] + temp[cnt-1][k-i]*dp[e][i]) % MOD;
				}
			}
		}
		cnt++;
	}

	//마지막에 본 자식의 dp값인 temp[cnt-1]에 그보다 더 왼쪽에 있는 형제들의 값들이 누적되어 들어있다
	for(int k = 2; k <= K; ++k) {
		dp[cur][k] = temp[cnt-1][k];
	}
	
	dp[cur][0] = dp[cur][1] = 1;
}

void solve() {
	selected[1] = true;
	dfs(1);
	DP(1);

	ll result = 0;
	for(int i = 1; i <= N; ++i) {
		result = (result + dp[i][K]) % MOD;
	}
	cout<<result;
}

void input() {
	cin>>N>>K;
	for(int i = 1; i <= N-1; ++i) {
		int a, b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
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