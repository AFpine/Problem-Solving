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
const long long MOD = 1e9+9;
const int MAX = 105;

int L, U;
ll result[13];
ll ans;

void f(int n, int d) {
	while(n) {
		result[n%10] += d;
		n /= 10;
	}
}

void solve(int a, int b, int d) {
	while(a % 10 != 0 && a <= b) {
		f(a, d);
		a++;
	}
	if(a > b) return;
	while(b % 10 != 9 && a <= b) {
		f(b, d);
		b--;
	}

	int t = (b/10 - a/10 + 1);
	for(int i = 0; i < 10; ++i) result[i] += d * t;

	solve(a/10, b/10, d*10);
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>L>>U;
	if(U == 0) { cout<<"0"; return 0; }
	solve(max(1, L), U, 1);

	for(int i = 1; i < 10; ++i) ans += (i * result[i]);

	cout<<ans;

	return 0;
}