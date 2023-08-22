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
const int MAX = 22;

int N;
double arr[MAX][MAX];
double dp[(1<<20)+10];
bool selected[(1<<20)+10];

double f(int i, int bit) {
    if(i == N) {
        if(bit == (1<<N)-1) return 1;
        else return 0;
    }

    auto &ret = dp[bit];
    if(selected[bit]) return ret;
    selected[bit] = true;

    ret = 0;
    for(int j = 0; j < N; ++j) {
        if(bit & (1<<j)) continue;
        ret = max(ret, f(i+1, bit|(1<<j)) * arr[i][j] / 100);
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

    cout<<fixed;
    cout.precision(16);

    cin>>N;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cin>>arr[i][j];
        }
    }

    double ans = f(0, 0);
    cout<<ans * 100;

	return 0;
}