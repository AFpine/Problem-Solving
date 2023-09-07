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
const long long MOD = 1e9 + 7;
const int MAX = 111;

int T;
ll fibo[MAX];
map<ll, int> mp;
vector<ll> fibcnt;

ll sol(ll n) {
	if(n <= 0) return -1;
	if(n <= 3) return fibo[n];
	if(mp[n] > 0) {
		ll r = sol(mp[n]);
		if(r <= 0) return -1;
		else if(r > 86) return -1;
		else return fibo[r];
	}
	else {
		ll t = n - (lower_bound(fibcnt.begin(), fibcnt.end(), n) - fibcnt.begin());
		if(t % 2) {
			if(mp[n+1]) return n+2;
			else return n+1;
		}
		else {
			ll r = n;
			if(mp[n-1]) {
				r = n-2;
			}
			else {
				r = n-1;
			}
			if(r > 86) return -1;
			else return fibo[r];
		}
	}
}

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fibo[1] = 1;
	mp[fibo[1]] = 1;
	fibo[2] = 2;
	mp[fibo[2]] = 2;
	fibo[3] = 3;
	mp[fibo[3]] = 3;
	for(int i = 4; i <= 86; ++i) {
		fibo[i] = fibo[i-1] + fibo[i-2];
		mp[fibo[i]] = i;
	}
	for(int i = 1; i <= 86; ++i) fibcnt.push_back(fibo[i]);

	cin>>T;
	while(T--) {
		ll n;
		cin>>n;
		cout<<sol(n)<<'\n';
	}

	return 0;
}
