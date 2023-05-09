#include <bits/stdc++.h>

using namespace std;
#define sz(a) (int)(a.size()) 
#define all(a) (a).begin(), (a).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef pair<long double, long double> pdd;
typedef complex<double> cplx;

const double PI = acos(-1);
const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const long long MOD = 1e9+7;
const int MAX = 111;

int N, M, P;
ll dp[MAX][MAX];

ll f(int a, int b) {
	if(a == 0) {
		if(b == 0) return 1;
		else return 0;
	}
	auto &ret = dp[a][b];
	if(ret != -1) return ret;

	ret = 0;
	ret = (ret + (N-b+1) * f(a-1, b-1)) % MOD;
	if(b >= M) ret = (ret + (b-M) * f(a-1, b)) % MOD;

	return ret;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(dp, -1, sizeof(dp));

	cin>>N>>M>>P;

    cout<<f(P, N);

	return 0;
}