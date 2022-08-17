#include <bits/stdc++.h>
 
// 1067 이동

// update 220817

using namespace std;
#define sz(a) (int)(a.size()) 
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
const long long MOD = 9999991;
const int MAX = 60005;

int N;
int X[MAX], Y[MAX];
vector<cplx> cX, cY;

void FFT(vector<cplx> &f, cplx w) {
	int n = sz(f);
	if(n == 1) return;

	// n is always even number
	vector<cplx> even(n/2), odd(n/2);
	for(int i = 0; i < n; ++i) {
		if(i % 2) odd[i/2] = f[i];
		else even[i/2] = f[i];
	}

	FFT(even, w*w);
	FFT(odd, w*w);

	cplx wp(1, 0);
	for(int i = 0; i < n/2; ++i) {
		f[i] = even[i] + wp*odd[i];
		f[i + n/2] = even[i] - wp*odd[i];
		wp *= w;
	}
}

vector<cplx> mult(vector<cplx> a, vector<cplx> b) {
	int n = 1;
	while(n < sz(a) + 1 || n < sz(b) + 1) n *= 2;
	n *= 2;
	a.resize(n), b.resize(n);
	vector<cplx> c(n);

	cplx w(cos(2*PI/n), sin(2*PI/n));
	
	FFT(a, w);
	FFT(b, w);

	for(int i = 0; i < n; ++i) c[i] = a[i]*b[i];

	FFT(c, cplx(1, 0)/w);
	
	for(int i = 0; i < n; ++i) {
		c[i] /= cplx(n, 0);
		c[i] = cplx(round(c[i].real()), round(c[i].imag()));
	}
	return c;
}

void input() {
	cin>>N;
	for(int i = 0; i < N; ++i) {
		cin>>X[i];
		cX.push_back({1.0*X[i], 0});
	}
	for(int i = 0; i < N; ++i) {
		cin>>Y[i];
		cY.push_back({1.0*Y[i], 0});
	}
	for(int i = 0; i < N; ++i) cX.push_back({1.0*X[i], 0});
	reverse(cY.begin(), cY.end());
}

void solve() {
	auto res = mult(cX, cY);

	ll result = 0;
	for(int i = N-1; i <= 2*N-2; ++i) {
		result = max(result, (ll)res[i].real());
	}
	cout<<result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}