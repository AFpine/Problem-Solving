#include <bits/stdc++.h>

// 13430 합 구하기

// update 220711

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<long long, long long> pll;
typedef pair<int,int> pii;

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 55;
const long long MOD = 1e9+7;

int N, K;
vector<vector<ll>> dummy(MAX, vector<ll>(MAX, 0));
// ll sk[MAX][2];


vector<vector<ll>> mult(vector<vector<ll>> a, vector<vector<ll>> b) {
	vector<vector<ll>> ret (MAX, vector<ll>(MAX, 0));

	for(int k = 1; k <= K+2; ++k) {
		for(int i = 1; i <= K+2; ++i) {
			for(int j = 1; j <= K+2; ++j) {
				ret[i][j] = (ret[i][j] + (a[i][k] * b[k][j])) % MOD;
			}
		}
	}
	return ret;
}

vector<vector<ll>> matrixMultiply(vector<vector<ll>> mat, int n) {
	if(n <= 1) return mat;
	auto half = matrixMultiply(mat, n/2);

	if(n % 2) {
		return mult(mult(half, half), mat);
	}
	else {
		return mult(half, half);
	}
}

void input() {
	cin>>K>>N;

	for(int i = 1; i <= K+2; ++i) {
		for(int j = 1; j <= i; ++j) {
			dummy[i][j] = 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();

	if(N == 1) {
		cout<<"1";
		return 0;
	}

	dummy = matrixMultiply(dummy, N-1);

	// for(int i = 1; i <= K+2; ++i) {
	// 	for(int j = 1; j <= K+2; ++j) {
	// 		cout<<dummy[i][j]<<" ";
	// 	}
	// 	cout<<'\n';
	// }

	ll result = 0;
	for(int i = 1; i <= K+2; ++i) {
		result = (result + dummy[K+2][i]) % MOD;
	}

	cout<<result;

	return 0;
}