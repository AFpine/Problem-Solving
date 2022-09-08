#include <bits/stdc++.h>

// 17371 이사

// update 220908

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
const long long MOD = 1000000007;
const int MAX = 1005;

int N;
pll arr[MAX];

void input() {
	cin>>N;
	for(int i = 1; i <= N; ++i) cin>>arr[i].first>>arr[i].second;
}

void solve() {
	ll ans = -1, minv = llINF;
	for(int i = 1; i <= N; ++i) {
		ll t = 0;
		for(int j = 1; j <= N; ++j) {
			t = max(t, (arr[i].first - arr[j].first)*(arr[i].first - arr[j].first) + (arr[i].second- arr[j].second)*(arr[i].second - arr[j].second));
		}
		
		if(minv > t) {
			minv = t;
			ans = i;
		}
	}
	cout<<arr[ans].first<<" "<<arr[ans].second;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}