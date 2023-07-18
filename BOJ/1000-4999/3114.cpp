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
const int MAX = 1515;

int R, C;
int dp[MAX][MAX];
int apple[MAX][MAX], banana[MAX][MAX];

int conv(string s) {
	int ret = 0;
	for(int i = 1; i < sz(s); ++i) {
		ret *= 10;
		ret += s[i]-'0';
	}
	return ret;
}

int f(int i, int j) {
	if(i == 1 && j == 1) return 0;
	if(i < 1 || j < 1) return -INF;

	auto &ret = dp[i][j];
	if(ret != -1) return ret;

	ret = 0;
	ret = max(ret, f(i-1, j-1) + apple[i][j-1] + banana[i-1][j]);
	ret = max(ret, f(i-1, j) + apple[i][j-1]);
	ret = max(ret, f(i, j-1) + banana[i-1][j]);
	
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

	cin>>R>>C;
	for(int i = 1; i <= R; ++i) {
		for(int j = 1; j <= C; ++j) {
			string s;
			cin>>s;
			if(s[0] == 'A') {
				apple[i][j] = conv(s);
			}
			else {
				banana[i][j] = conv(s);
			}
		}
	}

	for(int i = 1; i <= R; ++i) {
		for(int j = 1; j <= C; ++j) {
			apple[i][j] += apple[i][j-1];
			banana[i][j] += banana[i-1][j];
		}
	}
	
	cout<<f(R, C);
	
	return 0;
}