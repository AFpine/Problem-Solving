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
const int MAX = 202020;

int N, M;
vector<vector<int>> S;
set<int> selected;
double ans = 0.0;

int main() {
    #ifndef ONLINE_JUDGE
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/input.txt", "r", stdin);
	freopen("C:/Users/mrt20/Desktop/AFpine/PS/PS_NotePad/BOJ/output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cout<<fixed;
	cout.precision(16);

	cin>>N>>M;
	for(int i = 1; i <= M; ++i) {
		vector<int> tmp;
		int s;
		cin>>s;
		for(int j = 1; j <= s; ++j) {
			int x;
			cin>>x;
			tmp.push_back(x);
		}
		S.push_back(tmp);
	}

	sort(S.begin(), S.end(), [](vector<int> a, vector<int> b) {
		return a.size() < b.size();
	});

	for(auto &s : S) {
		for(auto &i : s) {
			if(selected.find(i) == selected.end()) {
				ans = ((double)s.size()-1) / (double)s.size();
			} 
			selected.insert(i);
		}
	}
	cout<<ans;

	return 0;
}
