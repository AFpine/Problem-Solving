#include <bits/stdc++.h>
 
// 8916 이진 검색 트리

// update 220804

using namespace std;
#define sz(a) (int)(a.size()) 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef pair<long double, long double> pdd;
 
const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const long long MOD = 9999991;
const int N = 25;

// array to store inverse of 1 to N
ll factorialNumInverse[N + 1];

// array to precompute inverse of 1! to N!
ll naturalNumInverse[N + 1];

// array to store factorial of first N numbers
ll fact[N + 1];

// Function to precompute inverse of numbers
void InverseofNumber(ll p) {
	naturalNumInverse[0] = naturalNumInverse[1] = 1;
	for (int i = 2; i <= N; i++)
		naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
}
// Function to precompute inverse of factorials
void InverseofFactorial(ll p) {
	factorialNumInverse[0] = factorialNumInverse[1] = 1;

	// precompute inverse of natural numbers
	for (int i = 2; i <= N; i++)
		factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
}

// Function to calculate factorial of 1 to N
void factorial(ll p) {
	fact[0] = 1;

	// precompute factorials
	for (int i = 1; i <= N; i++) {
		fact[i] = (fact[i - 1] * i) % p;
	}
}

// Function to return nCr % p in O(1) time
ll Binomial(ll N, ll R, ll p) {
	// n C r = n!*inverse(r!)*inverse((n-r)!)
	ll ans = ((fact[N] * factorialNumInverse[R])
			% p * factorialNumInverse[N - R])
			% p;
	return ans;
}

int n;
int arr[N];
int l[N], r[N];
int szl[N], szr[N];
ll result = 1;

void bst(int cur, int k) {
	if(cur > k) {
		szl[cur]++;
		if(l[cur] == -1) {
			l[cur] = k;
		}
		else bst(l[cur], k);
	}
	else {
		szr[cur]++;
		if(r[cur] == -1) {
			r[cur] = k;
		}
		else bst(r[cur], k);
	}
}

void bstquery(int cur) {
	if(l[cur] != -1 && r[cur] != -1) {
		result *= Binomial(szl[cur] + szr[cur], szl[cur], MOD);
		result %= MOD;
		bstquery(l[cur]);
		bstquery(r[cur]);	
	}
	else if(l[cur] != -1) {
		bstquery(l[cur]);
	}
	else if(r[cur] != -1) {
		bstquery(r[cur]);
	}
}

void init() {
	fill(l, l + N, -1);
	fill(r, r + N, -1);
	fill(szl, szl + N, 0);
	fill(szr, szr + N, 0);
	result = 1;
}

void input() {
	ll p = 9999991;
	InverseofNumber(p);
	InverseofFactorial(p);
	factorial(p);

	cin>>n;
	for(int i = 1; i <= n; ++i) {
		cin>>arr[i];
	}
}

void solve() {
	int root = arr[1];
	for(int i = 2; i <= n; ++i) {
		bst(root, arr[i]);
	}
	bstquery(root);

	cout<<result<<'\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tt;
	cin>>tt;
	while(tt--) {
		init();
		input();
		solve();
	}

	return 0;
}