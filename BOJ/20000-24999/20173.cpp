#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

// 20173

// 221107

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
const int INF = 1e9+7;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const long long MOD = 1e9+7;
const int MAX = 1010101;

int N;
int dp[MAX][2][2], arr[MAX];
bool incorrect;

int f(int idx, int i, int j) {
	auto &ret = dp[idx][i][j];
	if(ret != -1) return ret;
	if(idx == N) {
		if(arr[idx] == 1) return (i == j);
		return (i != j);
	}
	ret = 0;
	if(arr[idx] == 0) {
		if(i == j) {
			ret |= f(idx+1, 1, 1);
			ret |= f(idx+1, 0, 0);
		}
		else if(i > j) {
			ret |= f(idx+1, 0, 1);
		}
		else {
			ret |= f(idx+1, 1, 0);
		}
	}
	else if(arr[idx] == 1) {
		if(i == j) {
			ret |= f(idx+1, 1, 0);
			ret |= f(idx+1, 0, 1);
		}
		else {
			ret |= f(idx+1, 0, 0);
			ret |= f(idx+1, 1, 1);
		}
	}
	else {
		if(i == j) {
			ret = 1;
		}
		else if(i > j) {
			ret |= f(idx+1, 1, 0);
		}
		else {
			ret |= f(idx+1, 0, 1);
		}
	}
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

	cin>>N;

	for(int i = 1; i <= N; ++i) cin>>arr[i];
	for(int i = 1; i <= N; ++i) if(arr[i] > 2) incorrect = true;
	if(arr[1] > 1 || arr[N] > 1) incorrect = true;

	int ans = 0;
	
	ans = f(1, 0, 0);

	if(incorrect || ans) cout<<"NO";
	else cout<<"YES";

	return 0;
}
