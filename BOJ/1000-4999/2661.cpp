#pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
#define sz(a) (ll)(a.size()) 
#define all(a) (a).begin(), (a).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef pair<long double, long double> pdd;
typedef complex<double> cplx;

const int MAX = 100;

int N;
string ans;
bool finish = false;

void f(int n, string s) {
	if(finish) return;
	if(n == N) {
		ans = s;
		finish = true;
		return;
	}

	string ns = s + "1";
	for(int i = 1; i <= 3; ++i) {
		bool invalid = false;
		ns[n] = '0' + i;

		for(int j = 1; j <= (n+1)/2; ++j) {
			bool flag = true;
			for(int k = 0; k < j; ++k) {
				if(ns[n-k] != ns[n-j-k]) flag = false;
			}
			if(flag) invalid = true;
		}

		if(invalid) continue;
		f(n+1, ns);
	}
}

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N;

	f(1, "1");

	cout<<ans;

	return 0;
}