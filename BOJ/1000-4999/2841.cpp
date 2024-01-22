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

const int MAX = 1010;

int N, P;
stack<int> st[7];

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>P;

	int ans = 0;
	for(int i = 1; i <= N; ++i) {
		int s, f;
		cin>>s>>f;

		while(!st[s].empty() && st[s].top() > f) {
			st[s].pop();
			ans++;
		}
		if(st[s].empty() || st[s].top() != f) {
			st[s].push(f);
			ans++;
		}
	}

	cout<<ans;

	return 0;
}