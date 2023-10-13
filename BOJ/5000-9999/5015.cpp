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
const int MAX = 111;

string P, S;
int N;
int dp[MAX][MAX];
int n, m;

void init() {
	memset(dp, -1, sizeof(dp));
}

int f(int i, int j) {
	if(i > n || j > m) return 0;
	if(i == n && j == m) return 1;

	auto &ret = dp[i][j];
	if(ret != -1) return ret;

	ret = 0;
	if(P[i] == '*') {
		ret |= f(i, j+1);
		ret |= f(i+1, j);
		ret |= f(i+1, j+1);
	}
	else if(P[i] == S[j]){
		ret |= f(i+1, j+1);
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

	cin>>P;
	n = P.length();
	cin>>N;
	while(N--) {
		init();
		cin>>S;
		m = S.length();

		if(f(0, 0) == 1) cout<<S<<"\n";
	}

	return 0;
}
