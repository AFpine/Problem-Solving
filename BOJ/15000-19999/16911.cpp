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
const int MAX = 17;

int N;
pdd city[MAX];
double dp[MAX][1<<MAX];
bool check[MAX][1<<MAX];

double dist(int a, int b) {
	return sqrt(pow(city[b].first-city[a].first, 2) + pow(city[b].second-city[a].second, 2));
}

double f(int idx, int bit) {
	if(bit == (1<<(N+1))-1) {
		return dist(idx, 1);
	}
	auto &ret = dp[idx][bit];
	if(check[idx][bit]) return ret;

	check[idx][bit] = true;
	ret = INF;

	for(int i = 1; i <= N; ++i) {
		if(!(bit & (1<<i))) {
			ret = min(ret, f(i, bit | (1<<i)) + dist(i, idx));
		}
	}
	return ret;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cout<<fixed;
	cout.precision(14);

	cin>>N;
	for(int i = 1; i <= N; ++i) {
		cin>>city[i].first>>city[i].second;
	}

	cout<<f(1, (1<<1)|1);

	return 0;
}