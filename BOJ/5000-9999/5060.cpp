// #define LOCAL_TEST

#include <bits/stdc++.h>

// 5060 무글 맵스

// update 220902

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
const int MAX = 205;

int H, C;
double house[MAX];
double dp[MAX][MAX];
double err[MAX][MAX];

void getErr() {
	for(int i = 1; i <= H; ++i) {
		for(int j = i; j <= H; ++j) {
			err[i][j] = 0;
			for(int k = i+1; k < j; ++k) {
				err[i][j] += abs(house[k] - (house[i] + (house[j]-house[i]) * (k-i) / (j-i)));
			}
		}
	}
}

double f(int i, int c) {
	if(c <= 2) return err[1][i];
	double &ret = dp[i][c];
	if(ret != -1.0) return ret;
	ret = INF;
	for(int k = 1; k <= i; ++k) {
		ret = min(ret, f(k, c-1) + err[k][i]);
	}
	return ret;
}

void input() {
	for(int i = 0; i < MAX; ++i) {
		for(int k = 0; k < MAX; ++k) dp[i][k] = -1.0;
	}

	cin>>H>>C;
	for(int i = 1; i <= H; ++i) { cin>>house[i]; }
}

void solve() {
	sort(house+1, house+1+H);
	getErr();

	cout<<f(H, C)/(double)H<<'\n';
}

int main() {

	#ifdef LOCAL_TEST
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cout<<fixed;
	cout.precision(4);

	int tt;
	cin>>tt;
	while(tt--) {
		input();
		solve();
	}

	return 0;
}