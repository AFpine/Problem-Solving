#include <bits/stdc++.h>

// 23571 John's Gift

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
ll good[MAX], tag[MAX];
ll pre1[MAX], pre2[MAX], suf1[MAX], suf2[MAX];

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N;
	for(int i = 1; i <= N; ++i) cin>>good[i];
	for(int i = 1; i <= N; ++i) cin>>tag[i];
	
	sort(good+1, good+1+N);
	sort(tag+1, tag+1+N);

	for(int i = 1; i <= N; ++i) {
		pre1[i] = max(pre1[i-1], abs(good[i] - tag[i]));
		if(i != N) pre2[i] = max(pre2[i-1], abs(good[i] - tag[i+1]));
		if(i != N) pre2[i] = min(pre1[i], pre2[i]);
	}
	for(int i = N; i >= 1; --i) {
		suf1[i] = max(suf1[i+1], abs(good[i] - tag[i]));
		if(i != 1) suf2[i] = max(suf2[i+1], abs(good[i] - tag[i-1]));
		if(i != 1) suf2[i] = min(suf1[i], suf2[i]);
	}

	int ans = -1;
	ll mn = llINF;
	for(int i = 1; i <= N; ++i) {
		ll t = llINF;
		t = min(t, max(pre1[i-1], suf1[i+1]));
		t = min(t, max(pre2[i-1], suf1[i+1]));
		t = min(t, max(pre1[i-1], suf2[i+1]));

		if(mn > t) {
			mn = t;
			ans = i;
		}
	}

	cout<<good[ans];

	return 0;
}