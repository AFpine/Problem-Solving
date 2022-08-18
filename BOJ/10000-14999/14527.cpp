#include <bits/stdc++.h>
 
// 14527 Paired Up

// update 220818

using namespace std;
#define sz(a) (int)(a.size()) 
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
const long long MOD = 9999991;
const int MAX = 100005;

int N;
vector<pll> arr;
ll maxv = 0, minv = llINF;

void input() {
	cin>>N;
	for(int i = 1; i <= N; ++i) {
		ll x, y;
		cin>>x>>y;
		arr.push_back({y, x});
	}
}

void solve() {
	ll result = 0;
	sort(arr.begin(), arr.end());
	int l = 0, r = N-1;
	while(l <= r) {
		result = max(result, arr[l].first + arr[r].first);

		if(arr[l].second > arr[r].second) {
			arr[l].second -= arr[r].second;
			r--;
		}
		else if(arr[l].second < arr[r].second) {
			arr[r].second -= arr[l].second;
			l++;
		}
		else {
			l++;
			r--;
		}
	}
	cout<<result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}