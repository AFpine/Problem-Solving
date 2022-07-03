#include <bits/stdc++.h>

// 1450 냅색문제

// update 220703

using namespace std;
typedef long long ll;
typedef pair<long long, long long> pii;
#define x first
#define y second

const int INF = 1e9+5;
const long long llINF = 1e18;
const int minINF = -2e9-1;
const int MAX = 35;
const long long MOD = 1e9+7;

int N, C, mid;
ll arr[MAX];
ll result;
vector<ll> V;

void recur1(int n, ll cur) {
	if(cur > C) return;
	if(n > mid) {
		if(cur <= C) V.push_back(cur);
		return;
	}

	recur1(n+1, cur);
	recur1(n+1, cur + arr[n]);
}

void recur2(int n, ll cur) {
	if(cur > C) return;
	if(n > N) {
		auto it = upper_bound(V.begin(), V.end(), (C-cur));
		if(it == V.begin()) result++;
		else if(it == V.end()) result += V.size();
		else result += (it-V.begin());
		return;
	}

	recur2(n+1, cur);
	recur2(n+1, cur + arr[n]);
}

void input() {
	cin>>N>>C;
	
	for(int i = 1; i <= N; ++i) {
		cin>>arr[i];
	}
}

void solve() {
	mid = N/2;

	recur1(1, 0);
	sort(V.begin(), V.end());
	// for(auto &i : V) cout<<i<<" ";
	recur2(mid+1, 0);

	cout<<result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}