// #define LOCAL_TEST

#include <bits/stdc++.h>

// 7983 내일 할거야

// update 220830

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
const long long MOD = 1000000007;
const int MAX = 1000005;

int N;
pll arr[MAX];

void input() {
	cin>>N;
	for(int i = 1; i <= N; ++i) {
		cin>>arr[i].first>>arr[i].second;
	}
}

void solve() {
	sort(arr+1, arr+1+N, [](pll a, pll b) {
		if(a.second == b.second) return a.first < b.first;
		return a.second > b.second;
	});

	// for(int i = 1; i <= N; ++i) cout<<arr[i].first<<" "<<arr[i].second<<'\n'; 

	ll cur = arr[1].second;
	for(int i = 1; i <= N; ++i) {
		if(cur > arr[i].second) cur = arr[i].second;
		cur -= arr[i].first;
	}
	cout<<cur;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

#ifdef LOCAL_TEST
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	input();
	solve();

	return 0;
}