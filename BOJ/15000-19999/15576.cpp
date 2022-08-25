#include <bits/stdc++.h>
 
// 15576 큰 수 곱셈 (2)

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
const int MAX = 300005;

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

	double ang = 2 * PI / n * (inv ? -1 : 1);
	for(int i = 0; i < n/2; ++i) {
		roots[i] = cplx(cos(ang * i), sin(ang * i));
	}
	
	for(int i = 2; i <= n; i <<= 1) {
		int step = n/i;
		for(int j = 0; j < n; j += i) {
			for(int k = 0; k < i/2; ++k) {
				cplx u = a[j+k], v = a[j+k+i/2] * roots[step*k];
				a[j+k] = u+v;
				a[j+k+i/2] = u-v;
			}
		}
	}
	if(inv) for(int i = 0; i < n; ++i) a[i] /= n;
}

vector<ll> mult(vector<ll> &v, vector<ll> &w) {
	vector<cplx> fv(v.begin(), v.end()), fw(w.begin(), w.end());
	int n = 2;
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
	for(int i = sz(A) - 1; i >= 0; --i) vA.push_back(A[i] - '0');
	for(int i = sz(B) - 1; i >= 0; --i) vB.push_back(B[i] - '0');
}

void solve() {
	auto result = mult(vA, vB);
	ll carry = 0;
	for(int i = 0; i < sz(result); ++i) {
		result[i] += carry;
		carry = result[i]/10;
		result[i] %= 10;
	}
	
	bool st = false;
	for(int i = sz(result)-1; i >= 0; --i) {
		if(!st && result[i] == 0) continue;
		st = true;
		cout<<result[i];
	}
	if(!st) cout<<"0";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}