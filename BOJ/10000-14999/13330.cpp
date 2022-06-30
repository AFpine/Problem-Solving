#include <bits/stdc++.h>

// 13330 유사 팰린드롬

// update 220630

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 10005;
const int MOD = 1e9+7;

int N,K,L;
double theta;
int dp[MAX][MAX];
string S;

bool isPalin(int s, int e) {
	if(s >= e) {
		return false;
	}
	int w = e - s + 1;
	int u = 0;
	int m = w / 2;

	for(int i = 0; i < m; ++i) {
		if(S[s + i] == S[e - i]) {
			u++;
		}
		else {
			break;
		}
	}

	if(theta <= ((2.0*u) / w)) return true;
	else return false;
}

int recur(int s, int e) {
	int &ret = dp[s][e];

	if(s >= e) {
		return INF;
	}
	if(ret != -1) {
		return ret;
	}

	if(isPalin(s,e)) return 1;

	ret = INF;
	for(int i = s + 1; i <= e-2; ++i) {
		if(isPalin(s, i)) {
            //optimazation
			ret = min(ret, recur(s, i) + recur(i + 1, e));
		}
	}
	return ret;
}

void input() {
	cin>>N>>K>>L;
	cin>>S;
	theta = (double)K / L;
}

void solve() {
	int result = recur(0,N-1);
	if(result == INF) cout<<"0";
	else cout<<result;
}

void init() {
	memset(dp,-1,sizeof(dp));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	init();
	input();
	solve();

	return 0;
}