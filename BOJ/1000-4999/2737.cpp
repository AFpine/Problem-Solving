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
const long long MOD = 1e7;
const int MAX = 101010;

int N, M;
ll sum[MAX];

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for(int i = 1; i < MAX; ++i) {
		sum[i] = sum[i-1] + i;
		if(sum[i] > (1LL<<32)) break;
	}

	cin>>N;
	while(N--) {
		int ans = 0;
		cin>>M;

		for(int i = 2; i < MAX; ++i) {
			if(sum[i] > M) break;
			if((M-sum[i]) % i == 0) ans++;
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}
