#include <bits/stdc++.h>

// 19577 수학은 재밌어

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

ll eulerP(ll x) {
	ll ret = x;
	for(ll i = 2LL; i <= sqrt(x); ++i) {
		if(x % i == 0) {
			ret /= i;
			ret *= (i - 1);
			while(x % i == 0) x /= i;
		}
	}
	if(x > 1) {
		ret /= x;
		ret *= (x-1);
	}
	return ret;
}

vector<ll> p;
ll N, ans, num;

void f(int idx, int sz, ll cur) {
	if(idx == sz) return;
	ll tmpcur = cur * p[idx];
	if(tmpcur * eulerP(tmpcur) == N) ans = min(ans, tmpcur);
	f(idx+1, sz, cur);
	f(idx+1, sz, tmpcur);
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	num = N;
	for(ll x = 2LL; x <= sqrt(num); ++x) {
		while(num % x == 0) {
			p.push_back(x);
			num /= x;
		}
	}
	if(num > 1) p.push_back(num);
	
	if(N == 1) { cout<<"1"; return 0; }

	ans = llINF;
	f(0, sz(p), 1);

	if(ans == llINF) cout<<"-1";
	else cout<<ans;

	// for(auto &i : p) cout<<i<<" ";
}