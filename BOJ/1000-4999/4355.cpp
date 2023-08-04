#include <bits/stdc++.h>

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

ll N;

ll phi(ll x) {
	if(x == 1) return 0;
    vector<pll> p;
    // Factorization in O(sqrt(x)).
    for (ll i = 2; i <= sqrt(x); i++) {
        ll res = 1;
        while (x % i == 0) {
            x /= i, res *= i;
        }
        if (res > 1) p.push_back({ res, i });
    }
    if (x > 1) p.push_back({ x, x });
    // Find phi(x).
    // phi(p^k) = p^{k-1} * (p - 1) for any prime number p.
    ll ret = 1;
    for (auto& i : p) {
        ret *= (i.first / i.second) * (i.second - 1);
    }
    return ret;
}

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while(true) {
		cin>>N;
		if(N == 0) break;
		cout<<phi(N)<<'\n';
	}

	return 0;
}