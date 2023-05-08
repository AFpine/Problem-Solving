#include <bits/stdc++.h>

// 

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
const long long MOD = 1000003;
const int MAX = 1010101;

string A, B;
bool isPrime[MAX + 1];
vector<int> prime(1, 2);
vector<pii> Hash[MAX];

void getPrime() {
	fill(isPrime + 2, isPrime + MAX + 1, 1);
	for (ll i = 4; i <= MAX; i += 2)
		isPrime[i] = 0;
	for (ll i = 3; i <= MAX; i += 2) {
		if (!isPrime[i]) continue;
		prime.push_back(i);
		for (ll j = i * i; j <= MAX; j += i * 2)
			isPrime[j] = 0;
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

	getPrime();

	cin>>A>>B;

	int result = 0;
	for(int i = 0; i < A.length(); ++i) {
		int h1 = 1;
		int h2 = 1;
		for(int j = i; j < A.length(); ++j) {
			int len = j - i + 1;
			h1 = (h1 * prime[A[j]-'a']) % MOD;
			h2 = (h2 * prime[A[j]-'a'+26]) % MOD;
			Hash[h1].push_back({h2, len});
		}
	}
	for(int i = 0; i < B.length(); ++i) {
		int h1 = 1;
		int h2 = 1;
		for(int j = i; j < B.length(); ++j) {
			int len = j - i + 1;
			h1 = (h1 * prime[B[j]-'a']) % MOD;
			h2 = (h2 * prime[B[j]-'a'+26]) % MOD;
			for(auto x : Hash[h1]) {
				if(h2 == x.first && len == x.second) result = max(result, len);
			}
		}
	}

	cout<<result;

	return 0;
}