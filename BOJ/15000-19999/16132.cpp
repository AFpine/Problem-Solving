#include <bits/stdc++.h>
 
// 16132 그룹 나누기 (Subset)

// update 220721
 
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef pair<double, double> pdd;
 
const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 1305;
const long long MOD = 1e9+7;

int N;
int sum;
ll dp[55][MAX];

void input() {
	cin>>N;
	for(int i = 1; i <= N; ++i) sum += i;
}

ll f(int n, int w) {
	ll &ret = dp[n][w];
	if(n > N || w > sum/2) return 0;
	if(w == sum/2) return 1;
	if(ret != -1) return ret;

	ret = f(n+1, w) + f(n+1, w+n);
	return ret;
}

void solve() {
	if(sum % 2) {
		cout<<"0";
		return;
	}
	memset(dp, -1, sizeof(dp));

	cout<<f(0, 0)/2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	input();
	solve();

	return 0;
}