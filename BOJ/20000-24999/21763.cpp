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
const long long MOD = 1e7;
const int MAX = 10101010;

int N, K;

void paint(int n, int k) {
	cout<<"YES\n";
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			if(i == 1 && j == n) cout<<".";
			else if(i == n && j == 1) cout<<".";
			else if(i != 1 && i != n && i == j) cout<<".";
			else {
				if(k) {
					cout<<"#";
					k--;
				}
				else cout<<".";
			}
		}
		cout<<'\n';
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

	cin>>N>>K;
	if(N <= 2) {
		if(K <= N/2) paint(N, K);
		else cout<<"NO";
	}
	else if(K > N*(N-1)) {
		cout<<"NO";
	}
	else paint(N, K);
	
	return 0;
}
