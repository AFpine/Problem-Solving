#include <bits/stdc++.h>

// 13976

// 221027

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
const int MAX = 1010101;

struct Matrix {
	vector<vector<ll>> a;
	Matrix operator*(const Matrix& rhs) const {
		Matrix ret;
		ret.a.resize(sz(a), vector<ll>(sz(rhs.a[0])));
		for (int y = 0; y < sz(ret.a); y++) {
			for (int x = 0; x < sz(ret.a[y]); x++) {
				ll sum = 0;
				for (int i = 0; i < sz(a[y]); i++) {
					sum = (sum + a[y][i] * rhs.a[i][x] + MOD) % MOD;
				}
				ret.a[y][x] = sum;
			}
		}
		return ret;
	}
};

ll N;

Matrix power(ll k, Matrix m) {
	if(k <= 1) return m;
	auto tmp = power(k/2, m);
	if(k % 2) {
		return m * (tmp * tmp);
	}
	return tmp * tmp;
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
	if(N % 2) { cout<<0; return 0; }
	if(N == 2) { cout<<3; return 0; }

	N /= 2;

	Matrix m, ans;
	m.a = {{4, -1}, {1, 0}};
	ans.a = {{3}, {1}};

	auto tmp = power(N-1, m);

	ans = tmp * ans;

	cout<<ans.a[0][0] % MOD;

	return 0;
}