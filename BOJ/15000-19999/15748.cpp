#pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
#define sz(a) (ll)(a.size()) 
#define all(a) (a).begin(), (a).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef pair<long double, long double> pdd;
typedef complex<double> cplx;

ll L, N, rF, rB;
ll ans = 0;
pll arr[101010];

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>L>>N>>rF>>rB;
	for(int i = 1; i <= N; ++i) {
		cin>>arr[i].first>>arr[i].second;
	}

	sort(arr+1, arr+1+N, [](pll a, pll b) {
		return a.second > b.second;
	});
	
	ll cur = 0;
	for(int i = 1; i <= N; ++i) {
		if(cur > arr[i].first) continue;
		ans += (arr[i].first - cur) * (rF - rB) * arr[i].second;
		cur = arr[i].first;
	}

	cout<<ans;

	return 0;
}