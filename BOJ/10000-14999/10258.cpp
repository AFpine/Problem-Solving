#include <bits/stdc++.h>

// 10258 스위치 배열

// update 220916

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
const int MAX = 35;

void solve() {
	ll ans = 0;	
	string S;
	cin>>S;
	for(int i = 0; i < sz(S); ++i) {
		if(S[i] == '0') continue;
		else {
			ans += (1 << (sz(S) - 1 - i));
			S[i] = '0';
			if(i != sz(S)-1) {
				if(S[i+1] == '0') S[i+1] = '1';
				else S[i+1] = '0';
			}
		}
	}
	cout<<ans<<'\n';
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin>>tc;
	for(int tt = 1; tt <= tc; ++tt) {
		solve();
	}
}