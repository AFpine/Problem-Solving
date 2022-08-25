#include <bits/stdc++.h>
 
// 22289 큰 수 곱셈 (3)

// update 220825

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
const long long MOD = 1000000007;
const int MAX = 1000005;

string A, B;
vector<ll> vA, vB;

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
	cin>>A>>B;
	for(int i = 0; i < sz(A); ++i) vA.push_back(A[i] - '0');
	for(int i = 0; i < sz(B); ++i) vB.push_back(B[i] - '0');

	reverse(vA.begin(), vA.end());
	reverse(vB.begin(), vB.end());
}

void solve() {
	auto result = mult(vA, vB);
	int len = sz(result);

	ll carry = 0;
	for(int i = 0; i < len-1; ++i) {
		if(result[i] < 10) continue;
		result[i+1] += result[i]/10;
		result[i] %= 10;
	}

	reverse(result.begin(), result.end());
	
	int idx = 0;
	while(result[idx] == 0) idx++;
	if(idx >= len) cout<<"0";
	
	while(idx < len) cout<<result[idx++];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}