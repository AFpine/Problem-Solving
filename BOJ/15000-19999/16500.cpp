#pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
#define sz(a) (ll)(a.size()) 
#define all(a) (a).begin(), (a).end()
typedef unsigned long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef pair<long double, long double> pdd;
typedef complex<double> cplx;

int N;
string S;
string arr[111];
int dp[111];

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>S>>N;
	for(int i = 1; i <= N; ++i) cin>>arr[i];

	dp[sz(S)] = 1;
	for(int j = sz(S)-1; j >= 0; --j) {
		for(int i = 1; i <= N; ++i) {	
			bool invalid = false;
			if((j + sz(arr[i])) > sz(S)) continue;

			for(int k = 0; k < sz(arr[i]); ++k) {
				if(arr[i][k] != S[j+k]) invalid = true;
			}
			
			if(invalid) continue;
			dp[j] |= dp[j + sz(arr[i])];
		}
	}

	cout<<dp[0];

	return 0;
}