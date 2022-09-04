// #define LOCAL_TEST

#include <bits/stdc++.h>

// 23242 Histogram

// update 220904

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
const int MAX = 4005;

int B, N;
ll arr[MAX], psum[MAX], psqsum[MAX];
double dp[MAX][35];
bool vis[MAX][35];

double f(int i, int b) {
	if(b == 1) return (psqsum[i] - 2.0*(psum[i])*((double)psum[i]/i) + 1.0*psum[i]*psum[i]/i);
	double &ret = dp[i][b];
	if(vis[i][b]) return ret;
	vis[i][b] = true;
	ret = (psqsum[i] - 2.0*(psum[i])*((double)psum[i]/i) + 1.0*psum[i]*psum[i]/i);
	for(int k = 1; k < i; ++k) {
		double temp = ((double)psqsum[i]-psqsum[k]) -2.0*(psum[i]-psum[k])*(psum[i]-psum[k])/(i-k) + ((double)psum[i]-psum[k])*((double)psum[i]-psum[k])/(i-k);
		ret = min(ret, f(k, b-1) + temp);
	}
	return ret;
}

void input() {
	cin>>B>>N;
	for(int i = 1; i <= N; ++i) cin>>arr[i];
}

void solve() {
	for(int i = 1; i <= N; ++i) {
		psum[i] = psum[i-1] + arr[i];
		psqsum[i] = psqsum[i-1] + (arr[i] * arr[i]);
	}

	cout<<f(N,B)<<'\n';
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
	cout.precision(6);

	input();
	solve();

	return 0;
}