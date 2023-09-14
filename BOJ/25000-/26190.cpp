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
const int MAX = 10101;

int N;
double arr[MAX];
int ans[MAX];

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
	
	double mn = 20000.0;
	
	cin>>N;
	for(int i = 1; i <= N; ++i) {
		cin>>arr[i];
		mn = min(mn, arr[i]);
	}
	for(int i = 1; i <= N; ++i) {
		arr[i] /= mn;
	}
	double gap = 1e9;
	for(int j = 1; j <= 10000; ++j) {
		double g = 0;
		for(int i = 1; i <= N; ++i) {
			g = max(abs((arr[i]*j) - round(arr[i]*j)), g);
		}
		if(g < gap) {
			gap = g;
			for(int i = 1; i <= N; ++i) ans[i] = (int)round(arr[i] * j);
		}
	}
	int g = ans[1];
	for(int i = 1; i <= N; ++i) g = gcd(g, ans[i]);
	for(int i = 1; i <= N; ++i) ans[i] /= g;
	for(int i = 1; i <= N; ++i) cout<<ans[i]<<"\n";

	return 0;
}
