// #define LOCAL_TEST

#include <bits/stdc++.h>

// 23248 Treasure Hunter

// update 220905

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
const int MAX = 100005;

int N, M, K;
pii arr[MAX];
vector<pii> v;

bool comp(pii a, pii b) {
	if(a.first < b.first && a.second > b.second) return true;
	else return false;
}

void input() {
	cin>>N>>M>>K;
	for(int i = 1; i <= K; ++i) cin>>arr[i].first>>arr[i].second;
}

void solve() {
	sort(arr+1, arr+1+K);
	for(int i = 1; i <= K; ++i) {
		auto it = lower_bound(v.begin(), v.end(), arr[i], comp);
		if(it == v.end()) v.push_back(arr[i]);
		else (*it) = arr[i];
	}
	cout<<sz(v);
}

int main() {

	#ifdef LOCAL_TEST
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