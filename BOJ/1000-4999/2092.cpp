// #pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
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
const long long MOD = 1000000LL;
const int MAX = 222;

int T, A, S, B;
int cnt[MAX];
ll dp[4040][MAX];
ll result;

ll f(int i, int j) {
    if(j == 0) {
        if(i == 0) return 1;
        else return 0;
    }

    auto &ret = dp[i][j];
    if(ret != -1) return ret;

    ret = 0;
    for(int k = 0; k <= min(i, cnt[j]); ++k) {
        ret = (ret + f(i-k, j-1)) % MOD;
    }
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

    cin>>T>>A>>S>>B;
    for(int i = 1; i <= A; ++i) {
        int t;
        cin>>t;
        cnt[t]++;
    }

    for(int i = S; i <= B; ++i) {
        result = (result + f(i, T)) % MOD;
    }
    cout<<result;

	return 0;
}