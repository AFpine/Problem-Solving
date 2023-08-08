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
const int MAX = 555;

int N;
pii arr[MAX];
bool selected[MAX][MAX];
double dp[MAX][MAX];
double result = INF;

double dist(pii a, pii b) {
    return sqrt((double)(a.first - b.first) * (a.first - b.first) + (a.second - b.second)*(a.second - b.second));
}

double f(int i, int j) {
    if(i == N) {
        return dist(arr[j], arr[N]);
    }
    if(j == N) {
        return dist(arr[i], arr[N]);
    }
    
    auto &ret = dp[i][j];
    if(selected[i][j]) return ret;
    selected[i][j] = true;
    int nxt = max(i, j) + 1;

    ret = INF;
    ret = min(ret, f(nxt, j) + dist(arr[i], arr[nxt]));
    ret = min(ret, f(i, nxt) + dist(arr[j], arr[nxt]));
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

    int T;
    cin>>T;
    while(T--) {
        memset(selected, false, sizeof(selected));
        memset(dp, -1, sizeof(dp));
        cin>>N;
        for(int i = 1; i <= N; ++i) cin>>arr[i].first>>arr[i].second;

        cout<<f(1, 1)<<'\n';
    }
    

	return 0;
}