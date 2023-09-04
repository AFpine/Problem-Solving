// #pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
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
const long long MOD = 1e9 + 7;
const int MAX = 1010101;

int N;
int psum[MAX];
int result[MAX];
string S;

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N;
	cin>>S;

	for(int i = 1; i <= N; ++i) {
		if(S[i-1] == 'S') psum[i]++;
		psum[i] += psum[i-1];
	}

	for(int i = 1; i <= N; ++i) {
		int cnt = 0;
		int idx = i;
		while(idx <= N) {
			cnt++;
			if(psum[idx] == i) break;
			else idx += (i - psum[idx]);
		}
		result[i] = cnt;
	}

	for(int i = 1; i <= N; ++i) {
		cout<<result[i]<<" ";
	}

	return 0;
}
