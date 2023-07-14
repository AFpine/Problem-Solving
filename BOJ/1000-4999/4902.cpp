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
const int MAX = 444;

int N, tt;
vector<ll> psum[MAX];

void init() {
	for(int i = 0; i < 404; ++i) {
		psum[i].clear();
		psum[i].resize(i*2 + 5);
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

	while(true) {
		cin>>N;
		if(N == 0) break;
		init();

		for(int i = 1; i <= N; ++i) {
			for(int j = 1; j <= 2*i-1; ++j) {
				cin>>psum[i][j];
				psum[i][j] += psum[i][j-1];
			}
		}

		ll result = -INF;
		// upper
		for(int i = 1; i <= N; ++i) {
			for(int j = 1; j <= 2*i-1; j += 2) {
				ll cur = 0;
				for(int k = 0; k <= N-i; ++k) {
					cur += (psum[i+k][j+(2*k)] - psum[i+k][j-1]);
					result = max(result, cur);
				}
			}
		}
		// lower
		for(int i = N; i >= 1; --i) {
			for(int j = 2; j < 2*i; j += 2) {
				ll cur = 0;
				for(int k = 0; k < i/2; ++k) {
					if((j-2*k) < 2 || j > ((i-k)*2-1)) break;
					cur += (psum[i-k][j] - psum[i-k][(j-2*k)-1]);
					result = max(result, cur);
				}
			}
		}

		cout<<++tt<<". "<<result<<'\n';
	}
	
	return 0;
}