#include <bits/stdc++.h>

// 16229

// 221029

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
const int MAX = 101010;

int N, K, z[MAX];
string S;

vector<int> getpi(const string& P) {
	vector<int> pi(sz(P));
	for (int i = 1, j = 0; i < sz(P); i++) {
		while (j > 0 && P[i] != P[j]) j = pi[j - 1];

		if (P[i] == P[j]) pi[i] = ++j;
	}
	return pi;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>K>>S;

	if(K >= N) { cout<<N; return 0; }	

	auto fail = getpi(S);

	int ans = 0;
	for(int i = fail[N-1]; i; i = fail[i-1]) {
		int p = N - i;
		int r = (N + K) / p;
		if(r >= 2 && r * p >= N) ans = max(ans, p);
	}

	cout<<ans;

	return 0;
}