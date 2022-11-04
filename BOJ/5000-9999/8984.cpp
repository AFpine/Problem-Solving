#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

// 8984

// 221104

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
const int INF = 1e9+7;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const long long MOD = 1e9+7;
const int MAX = 202020;

int N, L;
ll tov1[MAX], tov2[MAX];
vector<pii> line;
ll dp[2][MAX];

void cc() {
	vector<int> v1, v2;
	for(auto &l : line) {
		v1.push_back(l.first);
		v2.push_back(l.second);
	}
	sort(all(line)); sort(all(v1)); sort(all(v2));
	v1.erase(unique(all(v1)), v1.end());
	v2.erase(unique(all(v2)), v2.end());

	for(auto &l : line) {
		auto fr = lower_bound(all(v1), l.first) - v1.begin();
		tov1[fr] = l.first;
		l.first = fr;
		auto sc = lower_bound(all(v2), l.second) - v2.begin();
		tov2[sc] = l.second;
		l.second = sc;
	}
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>N>>L;
	line.resize(N);

	for(auto &l : line) cin>>l.first>>l.second;

	cc();

	ll ans = 0;
	for(int i = 0; i < N; ++i) {
		auto cur = line[i];

		auto tmp1 = dp[1][cur.second], tmp0 = dp[0][cur.first];
		dp[0][cur.first] = max(dp[0][cur.first], tmp1 + abs(tov1[cur.first]-tov2[cur.second]) + L);
		dp[1][cur.second] = max(dp[1][cur.second], tmp0 + abs(tov1[cur.first]-tov2[cur.second]) + L);

		ans = max({ans, dp[0][cur.first], dp[1][cur.second]});
	}

	cout<<ans;

	return 0;
}
