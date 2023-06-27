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
const long long MOD = 1e9+9;
const int MAX = 202020;

int N;
map<int, int> mp;
vector<int> v;

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N;
	v.resize(N);
	for(int i = 0; i < N; ++i) {
		cin>>v[i];
		mp[v[i]] = i;
	}
	sort(v.begin(), v.end());

	int result = 0;
	for(int i = 0; i < N; ++i) {
		result = max(result, (mp[v[i]] - i));
	}

	cout<<result;
	
	return 0;
}