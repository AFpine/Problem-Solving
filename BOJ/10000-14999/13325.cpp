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
const int MAX = 3030303;

int K, idx = 2;
ll edge[MAX], psum[MAX], diff[MAX];
ll result = 0;
ll mx = 0;

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>K;
	for(int i = 1; i <= K; ++i) {
		for(int j = 1; j <= (1<<i); ++j) {
			cin>>edge[idx];
			psum[idx] = edge[idx] + psum[idx/2];
			idx++;
		}
	}

	for(int i = (1<<K); i <= (1<<K)+(1<<K)-1; ++i) mx = max(mx, psum[i]);
	for(int i = K; i >= 1; --i) {
		ll l = 0, r = 0;
		for(int j = (1<<i); j <= (1<<i)+(1<<i)-1; ++j) {
			if(i == K) {
				if(j % 2 == 0) {
					l = mx - psum[j];
				}
				else {
					r = mx - psum[j];
					diff[j/2] = min(l, r);
					edge[j-1] += l - diff[j/2];
					edge[j] += r - diff[j/2];
				}
			}
			else {
				if(j % 2 == 0) {
					l = diff[j];
				}
				else {
					r = diff[j];
					diff[j/2] = min(l, r);
					edge[j-1] += l - diff[j/2];
					edge[j] += r - diff[j/2];
				}
			}
		}
	}

	for(int i = 2; i <= (1<<(K+1))-1; ++i) result += edge[i];
	// for(int i = 2; i <= (1<<(K+1))-1; ++i) cout<<edge[i]<<" ";
	// cout<<'\n';
	cout<<result;

	return 0;
}