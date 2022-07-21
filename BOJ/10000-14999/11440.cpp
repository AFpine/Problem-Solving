#include <bits/stdc++.h>

// 11440 피보나치 수의 제곱의 합

// update 220721
 
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef pair<double, double> pdd;
 
const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const long long MOD = 1e9+7;
const int MAX = 100005;

using Matrix = vector<vector<ll>>;

ll N;
ll result;

Matrix mul(Matrix a, Matrix b) {
	Matrix res = {{0, 0}, {0, 0}};
	for(int i = 0; i < 2; ++i) {
		for(int j = 0; j < 2; ++j) {
			for(int k = 0; k < 2; ++k) {
				res[i][j] += (a[i][k] * b[k][j]);
				res[i][j] %= MOD;
			}
		}
	}
	return res;
}

void input() {
	cin>>N;
}

void solve() {
	Matrix base = {{1, 0}, {0, 1}};
	Matrix P = {{1, 1}, {1, 0}};

	while(N > 0) {
		if(N % 2) base = mul(base, P);
		N /= 2;
		P = mul(P, P);
	}
	cout<<(base[0][0] * base[0][1]) % MOD;
	//그냥 공식 사용하는 문제인듯..
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	input();
	solve();

	return 0;
}