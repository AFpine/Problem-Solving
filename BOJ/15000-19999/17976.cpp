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
const int MAX = 101010;

int N;
pii th[MAX];

bool solve(ll p) {
	bool invalid = false;
	ll prv = th[1].first;

	for(int i = 2; i <= N; ++i) {
		if(th[i].second < (prv + p)) invalid = true;
		else if(th[i].first > (prv + p)) prv = th[i].first;
		else prv += p;
	}
	
	if(invalid) return false;
	else return true;
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
		cin>>th[i].first>>th[i].second;
		th[i].second += th[i].first;
	}

	sort(th+1, th+1+N, [](pii a, pii b) {
		return a.first < b.first;
	});

	ll result = 0;
	ll l = 0, r = 2*1e9;
	while(l <= r) {
		ll mid = (l+r)/2;

		if(solve(mid)) {
			result = max(result, mid);
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}

	cout<<result;

	return 0;
}
