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

int N;
int A[MAX], B[MAX];
int tA[MAX], tB[MAX];

void solve() {
	int ret = 0;
	int lidx = 0, ridx = 99;
	int lcnt = 0, rcnt = 0;
	while(lidx <= 99 && ridx >= 1) {
		if(tA[lidx] == 0) {
			lidx++;
			continue;
		}
		if(tB[ridx] == 0) {
			ridx--;
			continue;
		}
		ret = max(ret, lidx + ridx);
		int diff = min(tA[lidx], tB[ridx]);
		tA[lidx] -= diff;
		tB[ridx] -= diff;
	}

	cout<<ret<<'\n';
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
	for(int i = 1; i <= N; ++i) {
		int a, b;
		cin>>a>>b;
		A[a]++;
		B[b]++;
		for(int i = 1; i <= 99; ++i) {
			tA[i] = A[i];
			tB[i] = B[i];
		}
		solve();
	}

	return 0;
}
