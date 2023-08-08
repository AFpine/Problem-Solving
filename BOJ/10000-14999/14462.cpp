#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
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
const long long MOD = 1e9+7;
const int MAX = 1010;

int N;
int A[MAX], B[MAX];
int dp[MAX][MAX];

int f(int i, int j) {
    if(i > N || j > N) return 0;

    auto &ret = dp[i][j];
    if(ret != -1) return ret;

    ret = 0;
    ret = f(i+1, j);
    for(int k = j; k <= N; ++k) {
        if(abs(A[i] - B[k]) <= 4) ret = max(ret, f(i+1, k+1) + 1);
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

    cin>>N;
    for(int i = 1; i <= N; ++i) cin>>A[i];
    for(int i = 1; i <= N; ++i) cin>>B[i];

    cout<<f(1, 1);

	return 0;
}