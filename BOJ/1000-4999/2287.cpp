#pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
const long long MOD = 998244353;
const int MAX = 10;

int K, N;
set<int> S[MAX];

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>K>>N;
	
	int t = 0;
	for(int i = 1; i <= 8; ++i) {
		t = (t * 10) + K;
		S[i].insert(t);
	}
	for(int i = 1; i <= 8; ++i) {
		for(int j = 1; j <= 8; ++j) {
			if(i + j > 8) continue;
			for(auto &a : S[i]) {
				for(auto &b : S[j]) {
					S[i+j].insert(a+b);
					S[i+j].insert(a*b);
					S[i+j].insert(a-b);
					S[i+j].insert(b-a);
					if(a != 0) S[i+j].insert(b/a);
					if(b != 0) S[i+j].insert(a/b);
				}
			}
		}
	}

	while(N--) {
		bool fin = false;
		cin>>t;
		for(int i = 1; i <= 8; ++i) {
			if(fin) break;
			if(S[i].find(t) != S[i].end()) {
				cout<<i<<'\n';
				fin = true;
			}
		}
		if(!fin) cout<<"NO\n";
	}
	
	
	return 0;
}
