#include <bits/stdc++.h>

// 23577 Trio

// update 220926

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
const int MAX = 1000005;

int N;
int cnt[4][10];
vector<string> arr;

ll f(int idx, const string& s1, const string& s2) {
	if(idx >= 4) return 0;
	if(s1[idx] == s2[idx]) {
		
	}
	else {
		
	}
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N;
	arr.resize(N);
	for(auto &i : arr) cin>>i;
	
	sort(all(arr));
	for(auto &i : arr) {
		for(int j = 0; j < 4; ++j) cnt[j][i[j]]++;
	}

	ll res = 0;
	for(int i = 0; i < N; ++i) {
		for(int j = i + 1; j < N; ++j) {

		}
	}
	

	return 0;
}