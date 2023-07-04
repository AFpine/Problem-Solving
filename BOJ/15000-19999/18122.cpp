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
const int MAX = 1010101;

int N, mid[4][4];
int check[MAX];
ll dp[4][4][MAX];

ll f(int i, int j, int k) {
	if(k <= 0) return 0;
	if(k == 1) {
		return 2LL;
	}
	auto &ret = dp[i][j][k];
	if(ret != -1) {
		return ret;
	}
	ret = 0;
	ret = (ret + f(i, mid[i][j], k-1)) % MOD;
	ret = (ret + 2LL) % MOD;
	ret = (ret + f(mid[i][j], j, k-1)) % MOD;
	return ret % MOD;
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

	cin>>N;
	mid[1][2] = mid[2][1] = 3;
	mid[1][3] = mid[3][1] = 2;
	mid[2][3] = mid[3][2] = 1;

	ll result = 3;
	result = (result + f(1, 3, N-1)) % MOD;
	result = (result + f(3, 2, N-1)) % MOD;
	result = (result + f(3, 1, N-1)) % MOD;
	result = (result + f(1, 3, N-1)) % MOD;
	cout<<result;

	return 0;
}