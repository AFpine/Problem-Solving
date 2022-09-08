#include <bits/stdc++.h>

// 17367 공교육 도박

// update 220908

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
const long long MOD = 1000000007;
const int MAX = 1005;

int N;
double dp[MAX][7][7];
bool vis[MAX][7][7];

ll calculate(ll i, ll j, ll k) {
	if(i == j && j == k) {
		return 10000 + (i)*1000;
	}
	else if(i == j) {
		return 1000 + (i)*100;
	}
	else if(j == k) {
		return 1000 + (j)*100;
	}
	else if(i == k) {
		return 1000 + (k)*100;
	}
	else {
		if(i > j && i > k) return i * 100;
		else if(j > i && j > k) return j * 100;
		else return k * 100;
	}
}

double f(int n, int i, int j) {
	if(n <= 0) return 0;
	auto &ret = dp[n][i][j];
	if(vis[n][i][j]) return ret;
	vis[n][i][j] = true;
	ret = 0;

	for(int k = 1; k <= 6; ++k) {
		ret += max((double)calculate(i, j, k), f(n-1, j, k));
	}
	ret /= 6;
	return ret;
}

void input() {
	cin>>N;
}

void solve() {
	double res = 0;
	for(int i = 1; i <= 6; ++i) {
		for(int j = 1; j <= 6; ++j) {
			res += f(N-2, i, j);
		}
	}
	cout<<res/36;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cout<<fixed;
	cout.precision(16);

	input();
	solve();

	return 0;
}