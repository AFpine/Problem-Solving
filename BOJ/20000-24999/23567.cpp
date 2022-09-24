#include <bits/stdc++.h>

// 23567 Double Rainbow

// update 220924

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
const int MAX = 10005;

int N, K, arr[MAX], cnt[MAX], cur[MAX];

bool check1() {
	for(int i = 1; i <= K; ++i) {
		if(cur[i] == 0) return false;
	}
	return true;
}

bool check2() {
	for(int i = 1; i <= K; ++i) {
		if(cur[i] == cnt[i]) return false;
	}
	return true;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>K;
	for(int i = 1; i <= N; ++i) { cin>>arr[i]; cnt[arr[i]]++; }

	int l = 1, r = 1;
	int result = INF;
	cur[arr[1]]++;
	while(l <= r && r <= N) {
		if(check1()) {
			if(check2()) result = min(result, r-l+1);
			cur[arr[l++]]--;
		}
		else {
			cur[arr[++r]]++;
		}
	}

	if(result == INF) cout<<"0";
	else cout<<result;

	return 0;
}