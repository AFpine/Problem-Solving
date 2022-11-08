#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

// 17105

// 221108

using namespace std;
#define sz(a) (int)(a.size()) 
#define all(a) (a).begin(), (a).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef pair<long double, long double> pdd;
typedef complex<double> base;

const double PI = acos(-1);
const int INF = 1e9+7;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const long long MOD = 1e9+7;
const int MAX = 1<<21;

void fft(vector<base> &a, bool inv){
	int n = a.size(), j = 0;
	vector<base> roots(n/2);
	for(int i=1; i<n; i++){
		int bit = (n >> 1);
		while(j >= bit){
			j -= bit;
			bit >>= 1;
		}
		j += bit;
		if(i < j) swap(a[i], a[j]);
	}
	double ang = 2 * acos(-1) / n * (inv ? -1 : 1);
	for(int i=0; i<n/2; i++){
		roots[i] = base(cos(ang * i), sin(ang * i));
	}
	for(int i=2; i<=n; i<<=1){
		int step = n / i;
		for(int j=0; j<n; j+=i){
			for(int k=0; k<i/2; k++){
				base u = a[j+k], v = a[j+k+i/2] * roots[step * k];
				a[j+k] = u+v;
				a[j+k+i/2] = u-v;
			}
		}
	}
	if(inv) for(int i=0; i<n; i++) a[i] /= n; // skip for OR convolution.
}

void multiply(vector<ll> &a, vector<ll> &b, vector<ll> &res1, vector<ll> &res2){
	vector<base> fa(a.begin(), a.end()), fb(b.begin(), b.end());
	fft(fa, 0); fft(fb, 0);
	vector<base> faa(fa.begin(), fa.end());
	for(int i = 0; i < MAX; ++i) fa[i] *= fb[i];
	for(int i = 0; i < MAX; ++i) faa[i] *= faa[i] * faa[i];
	fft(fa, 1);
	fft(faa, 1);
	for(int i = 0; i < MAX; ++i) {
		res2[i] = ll(fa[i].real() + (fa[i].real() > 0 ? 0.5 : -0.5));
		res1[i] = ll(faa[i].real() + (faa[i].real() > 0 ? 0.5 : -0.5));
	}
}

int T, N;
vector<ll> A(MAX), B(MAX), res1(MAX), res2(MAX);
bool isPrime[MAX + 1];
vector<int> prime(1, 2);

void getPrime() {
	fill(isPrime + 2, isPrime + MAX + 1, 1);
	for (ll i = 4; i <= MAX; i += 2)
		isPrime[i] = 0;
	for (ll i = 3; i <= MAX; i++) {
		if (isPrime[i]) prime.push_back(i);
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

	cin>>T;
	for(int i = 3; i <= 1000000; ++i) {
		if(isPrime[i]) {
			A[i>>1] = 1;
			if(i-1 < 500000) B[i-1] = 1;
		}
	}

	multiply(A, B, res1, res2);
	while(T--) {
		ll ans = 0;
		cin>>N;

		if(N % 3 == 0 && isPrime[N/3]) {
			ans = (res1[(N-3)>>1] - res2[(N-3)>>1]*3LL + 2)/6 + res2[(N-3)>>1];
		}
		else {
			ans = (res1[(N-3)>>1] - res2[(N-3)>>1]*3LL)/6 + res2[(N-3)>>1];
		}
		if(isPrime[N-4]) ans++;
		cout<<ans<<'\n';
	}

	return 0;
}