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
const int MAX = 17;

int N, result;
int edge[MAX][MAX];
int dp[MAX][1<<17];
string dict[MAX];

int solve(int cur, int bit) {
	if(bit == (1<<N)-1) {
		return 0;
	}
	auto &ret = dp[cur][bit];
	if(ret != -1) return ret;

	ret = 0;
	for(int i = 0; i < N; ++i) {
		if(bit & (1<<i)) continue;
		if(dict[cur].back() == dict[i].front())ret = max(ret, solve(i, bit|(1<<i)) + sz(dict[i]));
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

	cin>>N;
	for(int i = 0; i < N; ++i) {
		cin>>dict[i];
	}

	for(int i = 0; i < N; ++i) {
		memset(dp, -1, sizeof(dp));
		result = max(result, solve(i, (1<<i)) + sz(dict[i]));
	}
	cout<<result;

	return 0;
}