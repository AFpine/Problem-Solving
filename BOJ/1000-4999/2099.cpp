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
const int MAX = 222;

int N, K, M;

vector<vector<ll>> matmul(vector<vector<ll>> a, vector<vector<ll>> b) {
	vector<vector<ll>> ret(MAX, vector<ll>(MAX, 0));

	for(int i = 1; i <= N; ++i) {
		for(int j = 1; j <= N; ++j) {
			for(int k = 1; k <= N; ++k) {
				ret[i][j] += a[i][k] * b[k][j];
				// must be modulated 
				ret[i][j] %= MOD;
			}
		}
	}

	return ret;
}

vector<vector<ll>> matpow(vector<vector<ll>> a, int k) {
	if(k == 1) return a;
	auto ret = matpow(a, k/2);
	ret = matmul(ret, ret);
	if(k % 2) ret = matmul(ret, a);
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

	vector<vector<ll>> arr(MAX, vector<ll>(MAX, 0));

	cin>>N>>K>>M;
	for(int i = 1; i <= N; ++i) {
		int v1, v2;
		cin>>v1>>v2;
		arr[i][v1] = arr[i][v2] = 1;
	}

	auto result = matpow(arr, K);

	while(M--) {
		int a, b;
		cin>>a>>b;
		if(result[a][b] > 0) cout<<"death\n";
		else cout<<"life\n";
	}

	return 0;
}