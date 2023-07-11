// #include <bits/stdc++.h>

// using namespace std;
// #define sz(a) (int)(a.size()) 
// #define all(a) (a).begin(), (a).end()
// typedef long long ll;
// typedef long double ld;
// typedef pair<int,int> pii;
// typedef pair<long long, long long> pll;
// typedef pair<long double, long double> pdd;
// typedef complex<double> cplx;

// const double PI = acos(-1);
// const int INF = 1e9+5;
// const long long llINF = 1e18;
// const int minINF = -2e9-1;
// const long long MOD = 1e9+7;
// const int MAX = 101010;

// ll dp[6][MAX];

// int main() {
//     #ifndef ONLINE_JUDGE
// 	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
// 	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
// 	#endif

// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cout.tie(NULL);

// 	dp[1][1] = 1;
// 	for(int i = 2; ; ++i) {
// 		dp[0][i] += dp[1][i] = (dp[1][i-1] + dp[2][i-1] + dp[3][i-1] + dp[4][i-1] + dp[5][i-1]);
// 		dp[0][i] += dp[2][i] = (dp[1][i-1] + dp[3][i-1]);
// 		dp[0][i] += dp[3][i] = (dp[1][i-1] + dp[2][i-1]);
// 		dp[0][i] += dp[4][i] = dp[1][i-1];
// 		dp[0][i] += dp[5][i] = dp[1][i-1];
// 		if(dp[0][i] >= (1LL<<32)) break;
// 	}

// 	int T;
// 	cin>>T;
// 	while(T--) {
// 		int N;
// 		cin>>N;
// 		cout<<dp[0][N]<<'\n';
// 	}
	
// 	return 0;
// }

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
const int MAX = 101010;

ll N, K, Q, x, y;

ll parent(ll a) {
	ll r = a % K;
	if(r <= 1) return a/K;
	else return a/K + 1;
}

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>K>>Q;
	if(K == 1) {
		for(int i = 1; i <= Q; ++i) {
			cin>>x>>y;
			cout<<abs(x-y)<<'\n';
		}
	}
	else {
		for(int i = 1; i <= Q; ++i) {
			cin>>x>>y;
			ll result = 0;
			while(x != y) {
				if(x > y) {
					x = parent(x);
				}
				else {
					y = parent(y);
				}
				result++;
			}
			cout<<result<<'\n';
		}
	}


	return 0;
}