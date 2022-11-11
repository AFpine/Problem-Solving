#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

// 1994

// 221111

using namespace std;
#define sz(a) (int)(a.size()) 
#define all(a) (a).begin(), (a).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef pair<long double, long double> pdd;
typedef complex<double> base;

const double PI = acos(-1);
const int INF = 1e9+7;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const long long MOD = 1e9+7;
const int MAX = 2020;

int N, ans;
vector<ll> arr;

ll hasing(ll x, ll y) {
	return 1000000001LL * x + y;
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
	arr.resize(N);
	for(auto &a : arr) cin>>a;

	sort(all(arr));

	int cnt = 0;
	for(int i = 0; i < N; ++i) {
		if(i > 0 && arr[i] == arr[i-1]) cnt++;
		else cnt = 1;
		ans = max(ans, cnt);
	}

	arr.erase(unique(all(arr)), arr.end());

	unordered_map<ll, int> M;
	for(int i = 0; i < sz(arr); ++i) {
		for(int j = i-1; j >= 0; --j) {
			auto it1 = hasing(i, arr[i] - arr[j]);
			auto it2 = hasing(j, arr[i] - arr[j]);

			if(M.find(it2) == M.end()) M[it1] = 2;
			else M[it1] = M[it2] + 1;
			
			ans = max(ans, M[it1]);
		}
	}

	cout<<ans;

	return 0;
}