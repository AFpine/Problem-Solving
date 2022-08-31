// #define LOCAL_TEST

#include <bits/stdc++.h>

// 5051 피타고라스의 정리

// update 220831

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
const long long MOD = 1000000007;
const int MAX = 500005;

ll N;
vector<ll> A, B, V;

void FFT(vector<cplx> &a, bool inv) {
	int n = sz(a), j = 0;
	vector<cplx> roots(n/2);
	for(int i = 1; i < n; ++i) {
		int bit = (n >> 1);
		while(j >= bit) {
			j -= bit;
			bit >>= 1;
		}
		j += bit;
		if(i < j) swap(a[i], a[j]);
	}

	for(int k = 1; k < n; k *= 2) {
		double angle = (inv ? PI/k : -PI/k);
		cplx dir(cos(angle), sin(angle));
		
		for(int i = 0; i < n; i += k*2) {
			cplx unit(1, 0);
			for(int j = 0; j < k; ++j) {
				cplx u = a[i+j];
				cplx v = a[i+j+k] * unit;

				a[i+j] = u+v;
				a[i+j+k] = u-v;

				unit *= dir;
			}
		}
	}

	if(inv) for(int i = 0; i < n; ++i) a[i] /= n;
}

vector<ll> mult(vector<ll> &v, vector<ll> &w) {
	vector<cplx> fv(v.begin(), v.end()), fw(w.begin(), w.end());
	ll n = 2;
	while(n < sz(v) + sz(w)) n <<= 1;
	fv.resize(n), fw.resize(n);

	FFT(fv, false);
	FFT(fw, false);
	for(int i = 0; i < n; ++i) fv[i] *= fw[i];
	FFT(fv, true);

	vector<ll> ret(n);
	for(int i = 0; i < n; ++i) ret[i] = (ll)round(fv[i].real());
	return ret;
}

void input() {
	cin>>N;
	A.resize(N*2), B.resize(N*2), V.resize(N*2);
}

void solve() {
	for(ll i = 1; i < N; ++i) {
		ll cur = (i*i) % N;
		A[cur]++;
		B[cur]++;
		V[(cur*2) % N]++;
	}
	auto tA = A;
	auto C = mult(A, B);

	ll result = 0, res = 0, res2 = 0;

	for(int i = 0; i < 2*N; ++i) {
		res += C[i] * tA[i % N];
	}
	for(int i = 0; i < 2*N; ++i) {
		res2 += V[i] * tA[i % N];
	}
	
	// cout<<res<<" "<<res2<<'\n';
	cout<<(res-res2)/2 + res2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

#ifdef LOCAL_TEST
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	input();
	solve();

	return 0;
}