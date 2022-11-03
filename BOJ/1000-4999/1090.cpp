#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

// 1090

// 221102

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
const int MAX = 55;

int N;
vector<pll> arr, center;
ll ans[MAX];

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill(ans, ans+MAX, llINF);

	cin>>N;
	arr.resize(N);
	for(int i = 0; i < N; ++i) cin>>arr[i].first>>arr[i].second;
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) center.push_back({arr[i].first, arr[j].second});
	}
	
	for(int i = 0; i < sz(center); ++i) {
		vector<ll> tmp;
		auto cur = center[i];
		
		for(int j = 0; j < N; ++j) tmp.push_back({abs(arr[j].first - cur.first) + abs(arr[j].second - cur.second)});
		sort(all(tmp));
		ll tmp2 = 0;
		for(int j = 0; j < N; ++j) {
			tmp2 += tmp[j];
			ans[j+1] = min(ans[j+1], tmp2);
		}
	}

	for(int i = 1; i <= N; ++i) cout<<ans[i]<<" ";

	return 0;
}
