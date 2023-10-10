#pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
const long long MOD = 998244353;
const int MAX = 555;


int N, K;
pii location[MAX];
int dp[MAX][MAX];

int dist(int i, int j) {
	return abs(location[i].first - location[j].first) + abs(location[i].second - location[j].second);
}

int f(int i, int j) {
	if(i > N) return INF;
	if(j > K) return INF;
	if(i == N) return 0;

	auto &ret = dp[i][j];
	if(ret != -1) return ret;

	ret = INF;
	for(int k = 0; k <= K-j; ++k) {
		ret = min(ret, f(i+k+1, j+k) + dist(i, i+k+1));
	}
	return ret;
}


int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(dp, -1, sizeof(dp));

	cin>>N>>K;
	for(int i = 1; i <= N; ++i) {
		cin>>location[i].first>>location[i].second;
	}

	cout<<f(1, 0);

	return 0;
}
