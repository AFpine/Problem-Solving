#include <bits/stdc++.h>

// 16496

// 221027

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
const int MAX = 1010101;

int N;
vector<string> S;

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N;
	S.resize(N);
	for(auto &s : S) cin>>s;

	sort(S.begin(), S.end(), [](string lhs, string rhs) {
		int l = sz(lhs), r = sz(rhs);
		for(int i = 0; i < 11; ++i) {
			if(i >= l) lhs.push_back(lhs[i % l]);
			if(i >= r) rhs.push_back(rhs[i % r]);
		}
		return rhs > lhs;
	});
	
	if(S[N-1] == "0") { cout<<0; return 0; }
	for(int i = N-1; i >= 0; --i) cout<<S[i];

	return 0;
}