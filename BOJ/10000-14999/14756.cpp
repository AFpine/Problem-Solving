#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

// 14756

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
const int MAX = 60606;

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

vector<ll> multiply(vector<ll> &v, vector<ll> &w){
	vector<base> fv(v.begin(), v.end()), fw(w.begin(), w.end());
	int n = 2; while(n < v.size() + w.size()) n <<= 1;
	fv.resize(n); fw.resize(n);
	fft(fv, 0); fft(fw, 0);
	for(int i=0; i<n; i++) fv[i] *= fw[i];
	fft(fv, 1);
	vector<ll> ret(n);
	for(int i=0; i<n; i++) ret[i] = (ll)round(fv[i].real());
	return ret;
}

ll N, L, M, W;
vector<vector<ll>> T, P, res;

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>L>>M>>W;

	T.resize(M+1, vector<ll>(N+1, 0));
	P.resize(M+1, vector<ll>(L+1, 0));

	for(int i = 0; i < M; ++i) {
		for(int j = 0; j < N; ++j) cin>>T[i][j];
	}
	for(int i = 0; i < M; ++i) {
		for(int j = 0; j < L; ++j) cin>>P[i][L-1-j];
	}

	for(int i = 0; i < M; ++i) {
		res.push_back(multiply(T[i], P[i]));
	}

	ll ans = 0;
	for(int i = L-1; i < N; ++i) {
		ll tmp = 0;
		for(int j = 0; j < M; ++j) tmp += res[j][i];
		if(tmp > W) ans++;
	}

	cout<<ans;

	return 0;
}