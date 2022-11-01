#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

// 16909

// 221031

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
ll A[MAX];
pii se[MAX];
stack<pii> st;
ll ans = 0;

void f() {
	for(int i = 1; i <= N; ++i) se[i] = {1, N};
	for(int i = 1; i <= N; ++i) {
		while(!st.empty() && st.top().first <= A[i]) {
			se[st.top().second].second = i-1;
			st.pop();
		}
		st.push({A[i], i});
	}
	while(!st.empty()) st.pop();
	for(int i = N; i >= 1; --i) {
		while(!st.empty() && st.top().first < A[i]) {
			se[st.top().second].first = i+1;
			st.pop();
		}
		st.push({A[i], i});
	}
	while(!st.empty()) st.pop();
	
	for(int i = 1; i <= N; ++i) {
		ans += A[i] * (se[i].second - i + 1) * (i - se[i].first + 1);
		// cout<<se[i].first<<" "<<se[i].second<<" "<<ans<<'\n';
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
	for(int i = 1; i <= N; ++i) cin>>A[i];

	f();
	for(int i = 1; i <= N; ++i) A[i] *= -1;
	f();

	cout<<ans;

	return 0;
}
