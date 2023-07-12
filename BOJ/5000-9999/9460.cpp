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
const long long MOD = 1e9+7;
const int MAX = 10101;

int T, N, K;
pll metal[MAX];

bool parametric_search(ll x) {
	int k = 1;
	ll mx = -INF, mn = INF;
	for(int i = 1; i <= N; ++i) {
		mx = max(mx, metal[i].second);
		mn = min(mn, metal[i].second);

		if((mx-mn) > x) {
			mx = metal[i].second;
			mn = metal[i].second;
			k++;
		}
	}
	if(k <= K) return true;
	else return false;
}

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>T;
	while(T--) {
		cin>>N>>K;
		for(int i = 1; i <= N; ++i) {
			cin>>metal[i].first>>metal[i].second;
		}
		sort(metal+1, metal+1+N, [](pll a, pll b) {
			return a.first < b.first;
		});

		ll l = 0, r = 2*1e8;
		ll result = r;
		while(l <= r) {
			ll p = (l+r)/2;
			if(parametric_search(p)) {
				r = p-1;
				result = min(result, p);
			}
			else {
				l = p+1;
			}
		}
		if(result % 2) cout<<result/2<<".5\n";
		else cout<<result/2<<".0\n";
	}

	return 0;
}