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
const int MAX = 2020;

int N;
string S;
int dp[MAX];
bool palin[MAX][MAX];

void getPalin() {
	for(int i = 0; i < N; ++i) palin[i][i] = true;
	for(int i = 0; i < N-1; ++i) {
		if(S[i] == S[i+1]) palin[i][i+1] = true;
	}

	for(int k = 2; k < N; ++k) {
		for(int i = 0; i <= N-k; ++i) {
			int j = i + k;
			if(S[i] == S[j] && palin[i+1][j-1] == true) palin[i][j] = true;
		}
	}
}

int f(int l) {
	if(l == 0) return 1;
	auto &ret = dp[l];
	if(ret != -1) return ret;

	ret = INF;
	if(palin[0][l]) return ret = 1;
	for(int i = 1; i <= l; ++i) {
		if(palin[i][l]) {
			ret = min(ret, f(i-1) + 1);
		}
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

	cin>>S;
	N = sz(S);

	getPalin();

	cout<<f(N-1);
	
	return 0;
}