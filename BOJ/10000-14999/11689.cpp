#include <bits/stdc++.h>

// 11689 GCD(n, k) = 1

// update 220920

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
const int MAX = 1000005;

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll N, ans;

	cin>>N;
	ans = N;
	for(ll i = 2LL; i <= sqrt(N); ++i) {
		if(N % i == 0) {
			ans /= i;
			ans *= (i - 1);
			while(N % i == 0) N /= i;
		}
	}
	if(N > 1) {
		ans /= N;
		ans *= (N-1);
	}

	cout<<ans;
}