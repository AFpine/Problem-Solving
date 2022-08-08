#include <bits/stdc++.h>
 
// 14658 하늘에서 별똥별이 빗발친다

// update 220808

using namespace std;
#define sz(a) (int)(a.size()) 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef pair<long double, long double> pdd;
typedef pair<int, char> pic;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const long long MOD = 9999991;
const int MAX = 100005;

int N, M, L, K;
vector<pii> star;

void input() {
	cin>>N>>M>>L>>K;
	for(int i = 1; i <= K; ++i) {
		int x, y;
		cin>>x>>y;
		star.push_back({x, y});
	}
}

int f(int i1, int i2, int j1, int j2) {
	int ret = 0;
	for(int i = 0; i < K; ++i) {
		if(star[i].first >= i1 && star[i].first <= i2 && star[i].second >= j1 && star[i].second <= j2) ret++;
	}
	return ret;
}

void solve() {
	int result = 0;
	for(int i = 0; i < K; ++i) {
		for(int j = 0; j < K; ++j) {
			result = max(result, f(star[i].first, star[i].first+L, star[j].second, star[j].second+L));
		}
	}
	cout<<K-result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}